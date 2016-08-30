//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, 2016
// description : c/c++, Qt application
//--------------------------------------------------------

#ifndef STATUSBARWIDGET_H
#define STATUSBARWIDGET_H

#include <QWidget>
#include <Object/dobject.h>
#include <Config>

namespace Ui {
class StatusBarWidget;
}

class StatusBarWidget : public QWidget, public DObject
{
    Q_OBJECT

public:
    explicit StatusBarWidget(QWidget *parent = 0);
    ~StatusBarWidget();

private:
    Ui::StatusBarWidget *ui;

private:
    bool m_connected;
    int m_progressValue;
    QString m_dbBackend;

public:

    bool connPixmap() const;
    void setConnPixmap(bool connected);

    bool connText() const;
    void setConnText(bool connected);

    int progressValue() const;
    void setProgressValue(int progressValue);

    QString dbBackend() const;
    void setDbBackend(const QString &dbBackend);

    void UpdateUi();

};

#endif // STATUSBARWIDGET_H
