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

    void setLabel1(const QString &text);
    void setLabel2(const QString &text);
    void setLabel3(const QString &text);
    void setLabel4(const QString &text);
    void setLabel5(const QString &text);
    void setLabel6(const QString &text);
    void setLabel7(const QString &text);

private:
    Ui::StatusBarWidget *ui;
    void resetUi();
};

#endif // STATUSBARWIDGET_H
