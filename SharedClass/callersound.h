#ifndef CALLERSOUND_H
#define CALLERSOUND_H

#include <QObject>
#include <../SharedClass/ndhelper.h>
#include <Inc/CallerSoundAlsa>
#include <Inc/Object>
#include <Inc/Setting>

class CallerSound : public QObject, public DObject
{
    Q_OBJECT
public:
    explicit CallerSound(QObject *parent = 0);
    ~CallerSound();

    void makeSound(const NDHelper &dt);

signals:
    void signalSoundFinish();

public slots:
    void slotSoundFinish();

private:
    DCallerSoundAlsa *m_callerSound;

    QStringList m_strList;
    bool m_chime;
    bool m_speech;

};

#endif // CALLERSOUND_H
