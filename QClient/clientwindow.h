#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <DMainWindow/dmainwindow.h>
#include <QtDebug>
#include <def.h>
#include <Node/node.h>

#define SB      ui->statusbar

namespace Ui {
class ClientWindow;
}

class ClientWindow : public DMainWindow
{
    Q_OBJECT

public:
    explicit ClientWindow(QWidget *parent = 0);
    ~ClientWindow();

private:
    Ui::ClientWindow *ui;

private slots:
    void slotResult(const Node *node);

    void on_pushButton_Test_clicked();
    void on_pushButton_Test2_clicked();
    void on_pushButton_clicked();

protected:
    virtual void showEvent(QShowEvent *event);

};

#endif // CLIENTWINDOW_H
