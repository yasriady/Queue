#include "callersound.h"

CallerSound::CallerSound(QObject *parent) : QObject(parent)
{
    m_callerSound = new DCallerSoundAlsa(this);
   connect( m_callerSound, SIGNAL(signalSoundFinish()), this, SLOT(slotSoundFinish()) );

   //mkCONFIX;
   m_chime = m_confix->boolean( KEY3(this, "chime"), true );
   m_speech = m_confix->boolean( KEY3(this, "speech"), true );

}

CallerSound::~CallerSound()
{

}

void CallerSound::makeSound(const NDHelper &dt)
{
    m_strList.clear();
    QStringList numList;

    if( dt.init() || (dt.queueNo()==0) )
    {
        slotSoundFinish();
        return;
    }

    switch ( dt.request() ) {

    case REQUEST::CALLING:

        if( m_speech ) {
            numList = NumericConverter2( (int)dt.queueNo() );
            numList.insert(0, QString(dt.groupCode()).toLower() );
            numList.insert(0, "nomor-urut");
            numList.append("di-loket");
            numList.append((NumericConverter1((int)dt.nodeId())).trimmed());
            m_strList << numList;
        }
        if( m_chime ) {
            m_strList.insert(0, "Ding-dong");
        }

        break;

    case REQUEST::PROCESS:

        if( m_chime ) {
            m_strList << "chime";
        }

        break;

    default:
        break;
    }
    m_callerSound->call(m_strList);
}

void CallerSound::slotSoundFinish()
{
    emit signalSoundFinish();
}
