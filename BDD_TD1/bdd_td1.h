#ifndef BDD_TD1_H
#define BDD_TD1_H

#include <QWidget>
#include <QSql>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class BDD_TD1; }
QT_END_NAMESPACE

class BDD_TD1 : public QWidget
{
    Q_OBJECT

public:
    BDD_TD1(QWidget *parent = nullptr);
    ~BDD_TD1();

private slots:
    void on_pushButton_clicked();
    void on_comboBoxRegions_currentIndexChanged(int index);
    void on_comboBoxDepartements_currentIndexChanged(int index);


private:
    Ui::BDD_TD1 *ui;
    QSqlDatabase bdd;
};
#endif // BDD_TD1_H
