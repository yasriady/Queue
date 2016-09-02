//--------------------------------------------------------
// file name   :
// author      : Dedy Yasriady
// version     : v1.00
// copyright   : Btm, 2016
// description : c/c++, Qt application
//--------------------------------------------------------

#ifndef BIGNODE_H
#define BIGNODE_H

#include <QWidget>
#include "../SharedClass/config.h"
#include "../SharedClass/ndhelper.h"
#include <Inc/Widget>

namespace Ui {
class BigNode;
}

class BigNode : public DWidget
{
    Q_OBJECT

public:
    explicit BigNode(QWidget *parent = 0);
    ~BigNode();

    void setStatus(const QString &status);
    void setQueueNo(const QString &queueNo);
    void setDisplayedName(const QString &displayedName);
    void setService(const QString &service);

    void updateUi(NDHelper *dt);
    void resetUi();

private slots:
    void on_pushButton_clicked();

private:
    Ui::BigNode *ui;

    QString m_status;
    QString m_queueNo;
    QString m_displayedName;
    QString m_service;
};

#endif // BIGNODE_H
