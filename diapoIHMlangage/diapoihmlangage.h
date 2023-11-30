#ifndef DIAPOIHMLANGAGE_H
#define DIAPOIHMLANGAGE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class DiapoIHMlangage; }
QT_END_NAMESPACE

class DiapoIHMlangage : public QWidget
{
    Q_OBJECT

public:
    DiapoIHMlangage(QWidget *parent = nullptr);
    ~DiapoIHMlangage();

private:
    Ui::DiapoIHMlangage *ui;
};
#endif // DIAPOIHMLANGAGE_H
