//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, 2016
// description : Arduino/ESP8266 wireless node sketch, for Queue Ticketing System
//--------------------------------------------------------
/*
 *  This sketch sends doing wireless communication via WLAN/TCPIP to Queue server (QDisplay)
 */

#include <ESP8266WiFi.h>
// lcd
#include <LiquidCrystal.h>
//#include "config.h"
#include "/home/dedy/QtProjects/Queue/QDisplay/config.h"
#include <WiFiUdp.h>

const char* ssid = MYSSID; // "SSID2";
const char* password = MY_PWD; // "5422f891";

const char* host = SERVER_IP;       // 192.168.1.2
const int serverPort = SERVER_PORT; // 9000

WiFiClient client;
WiFiUDP port;

char packetBuffer[255];
unsigned int localPort = 9999;

// lcd
LiquidCrystal lcd(5, 4, 16, 14, 12, 13);

// button
int buttonValue = 0;

uint8_t MAC_array[6];
char MAC_char[18];

// added 20160827
class MyError {
public:
    const int MAXERRCNT=10;
    int count = 0;
    bool error;
    void reset() {
        error = false;
        count = 0;
    }
};
MyError m_err;

void lcdDisplay(const NodeData *dt) 
{
    switch ( dt->serverAnswer ) {

    case SRVANSWER::REQUESTOK:

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print( dt->service );
        lcd.setCursor(0, 1);

        lcd.print( dt->requestText );
        lcd.print( " " );
        lcd.print( dt->queueNo_s );

        switch ( dt->request ) {

        case REQUEST::CALLING:
            lcd.setCursor(14, 1);
            lcd.print( dt->calledCount );
            lcd.print( "x" );
            break;

        case REQUEST::PROCESS:
            lcd.setCursor(13, 1);
            //lcd.print( " | " );
            char numOfWaiting[4];
            sprintf(numOfWaiting, "%03d", dt->numOfWaiting);
            lcd.print(numOfWaiting);
            break;

        default:
            break;
        }

        break;

    case SRVANSWER::NOTREGISTERED:
        lcd.setCursor(0, 1); lcd.print( "                " );
        lcd.setCursor(0, 1); lcd.print( dt->message );          // print "Not Registered"
        delay(3000);
        lcd.setCursor(0, 1);
        lcd.print( "PIN:" ); lcd.println( MAC_char );
        break;

    case SRVANSWER::SRVBUSY:
        lcd.setCursor(0, 0); lcd.print( "                " );
        lcd.setCursor(0, 0); lcd.print( dt->message );          // print "Busy, Please wait!"
        m_err.error = true;
        break;

    default:
        break;

    }

}

void doAct(int action) {   
    
    // Use WiFiClient class to create TCP connections
    //WiFiClient client;
    const int httpPort = serverPort;
    if (!client.connect(host, httpPort)) {
        Serial.println("connection failed");
        lcd.clear();
        lcd.print("N0 Server!");
        lcd.setCursor(0,1);
        lcd.print("Please try again ...");
        return;
    }

    RequestData rd;
    NodeData dt;
    rd.request = action;
    strncpy(rd.macAddress, MAC_char, sizeof(rd.macAddress) );
    size_t LEN = sizeof(dt);
    const char *rdBuf = (char*) &rd;
    uint8_t *dtBuf = (uint8_t*) &dt;
    
    client.write( rdBuf, sizeof(rd) );
    
    int timeout = millis() + 5000;
    
    while (client.available() == 0) {
        if (timeout - millis() < 0) {
            Serial.println(">>> Client timeout !");
            return;
        }
    }

    // Read all the lines
    while (client.available()) {
        client.read(dtBuf, sizeof(dt) );
    }

    lcdDisplay(&dt);

    delay(100);
    
}

void setup_tcp() {
    
    // BUTTON
    pinMode(A0, INPUT);
    
    Serial.begin(115200);
    delay(10);
    
    // We start by connecting to a WiFi network
    
    // lcd
    lcd.clear();
    lcd.begin(16, 2);

    // Welcome message
    lcd.setCursor(0, 0);
    lcd.print( "WELC0ME tc QUEUE" );
    
    Serial.println();
    Serial.println();
    Serial.print("Connecting to Wifi: ");
    Serial.println(ssid);
    
    WiFi.begin(ssid, password);
    
    //lcd.print("scan ");
    //lcd.print(ssid);
    //lcd.print(" ");
    lcd.setCursor(0, 1);
    lcd.print("Start up");
    //lcd.setCursor(0, 1);
    //lcd.print("wireless logon");

    while (WiFi.status() != WL_CONNECTED) {
        // loop hingga connected
        delay(500);
        Serial.print(".");
        lcd.print(".");
    }
    
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    lcd.clear();
    lcd.print("System lcgin...");
    //lcd.print(WiFi.localIP());
    //lcd.setCursor(0, 1);
    //lcd.print("PIN:");

    WiFi.macAddress(MAC_array);
    for (int i = 0; i < sizeof(MAC_array); ++i) {
        //sprintf(MAC_char, "%s%02x:", MAC_char, MAC_array[i]);
        sprintf(MAC_char, "%s%02x", MAC_char, MAC_array[i]);      // hex separator (:) removed
    }
    Serial.println(MAC_char); // - See more at: http://www.esp8266.com/viewtopic.php?f=29&t=3587#sthash.p1IZMGiv.dpuf
    //lcd.print(MAC_char);
    
    pinMode(0, INPUT);
    pinMode(2, INPUT);

    doAct(REQUEST::INIT);
    
}

void setup() {
    setup_tcp();
}

void buttonPressed(uint8_t no) {
    lcd.setCursor(15, 0);
    lcd.print("*");
    Serial.print("Button ");
    Serial.println(no);
}

void loop() {
    
    //loop_tcp();
    //return;
    
    buttonValue = analogRead(A0);
    
    //Serial.print("buttonValue: ");
    //Serial.println(buttonValue);

    if (buttonValue > 768) {
        buttonPressed(5);
        while (buttonValue > 768) {
            buttonValue = analogRead(A0);
        }
    }
    
    else if (buttonValue > 610) {
        buttonPressed(4);
        while (buttonValue > 610) {
            buttonValue = analogRead(A0);
        }
    }
    else if (buttonValue > 441) {
        buttonPressed(3);
        while (buttonValue > 441) {
            buttonValue = analogRead(A0);
        }
    }
    else if (buttonValue > 310) {
        buttonPressed(2);
        doAct(CLIREQUEST::CLI_PROCESS);
        while (buttonValue > 310) {
            buttonValue = analogRead(A0);
        }
    }
    else if (buttonValue > 160) {
        buttonPressed(1);
        doAct(CLIREQUEST::CLI_CALLING);
        while (buttonValue > 160) {
            buttonValue = analogRead(A0);
        }
    }
    
    // clear error count down
    //    if( m_err.error && ( m_err.count<m_err.MAXERRCNT) )
    //    {
    //        m_err.count++;
    //    } else {
    //        doAct(REQUEST::INIT);
    //        m_err.reset();
    //    }

    delay(75);
    
}



