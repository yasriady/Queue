//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, 2016
// description : LCD Test only, internal use
//--------------------------------------------------------
 *  This sketch is intended for LCD Display on with ESP8266
 *	using arduino library
 *
 */

// lcd
#include <LiquidCrystal.h>

// lcd
LiquidCrystal lcd(5, 4, 16, 14, 12, 13);

void setup() {

}

void loop() {

  lcd.clear();
  
  lcd.print("CALLING");
  delay(3000);

  lcd.clear();
    
  lcd.print("P");
  delay(1000);
  lcd.print("R");
  delay(1000);
  lcd.print("0");
  delay(1000);
  lcd.print("C");
  delay(1000);
  lcd.print("E");
  delay(1000);
  lcd.print("S");
  delay(1000);
  lcd.print("S");
  delay(1000);

}



