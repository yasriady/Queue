#ifndef FORMREPORT_H
#define FORMREPORT_H

#include <QWidget>

namespace Ui {
class FormReport;
}

class FormReport : public QWidget
{
    Q_OBJECT

public:
    explicit FormReport(QWidget *parent = 0);
    ~FormReport();

private:
    Ui::FormReport *ui;
};

#endif // FORMREPORT_H
