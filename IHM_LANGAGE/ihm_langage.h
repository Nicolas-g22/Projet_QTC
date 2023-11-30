#ifndef IHM_LANGAGE_H
#define IHM_LANGAGE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class IHM_LANGAGE; }
QT_END_NAMESPACE

class IHM_LANGAGE : public QMainWindow
{
    Q_OBJECT

public:
    IHM_LANGAGE(QWidget *parent = nullptr);
    ~IHM_LANGAGE();

private slots:

private:


    void on_pushButtonLinux_3_clicked();

    void on_pushButtonWindows_3_clicked();

    void on_pushButtonLion_3_clicked();

    void on_checkBoxLinux_3_stateChanged(int arg1);

    void on_checkBoxWindows_3_stateChanged(int arg1);

    void on_checkBoxLion_3_stateChanged(int arg1);

    void on_radioButtonLinux__clicked();

    void on_radioButtonWindows_3_clicked();

    void on_radioButtonLion_3_clicked();

    void on_comboBoxChoix_3_currentTextChanged(const QString &arg1);

    void on_lineEditEntrezCode_3_textChanged(const QString &arg1);

    void on_actionC_2_triggered();

    void on_actionJava_triggered();

    void on_actionC_3_triggered();

    void on_actionPHP_triggered();

    void on_actionJavaScript_triggered();

private:
    Ui::IHM_LANGAGE *ui;
};
#endif // IHM_LANGAGE_H
