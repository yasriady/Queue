//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, Aug 2016
// description : c/c++, Qt application
//--------------------------------------------------------

#ifndef STATUSBARWIDGET_H
#define STATUSBARWIDGET_H

#include <QWidget>

namespace Ui {
class StatusBarWidget;
}

class StatusBarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StatusBarWidget(QWidget *parent = 0);
    ~StatusBarWidget();

private:
    Ui::StatusBarWidget *ui;

public:
    void setConnected(const bool &connected);
    void setMessage(const QString &text);
    void setMacAddress(const QString &text);
    void setGroupCode(const QString &text);
    void setNodeName(const QString &text);
    void setCalledCount(const int &calledCount);

};

#endif // STATUSBARWIDGET_H
