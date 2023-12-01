/********************************************************************************
** Form generated from reading UI file 'ihm_serveur.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IHM_SERVEUR_H
#define UI_IHM_SERVEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IHM_Serveur
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBoxPortEcoute;
    QPushButton *pushButtonLancer;
    QTextEdit *textEditMessages;
    QPushButton *pushButtonQuitter;

    void setupUi(QWidget *IHM_Serveur)
    {
        if (IHM_Serveur->objectName().isEmpty())
            IHM_Serveur->setObjectName("IHM_Serveur");
        IHM_Serveur->resize(439, 377);
        verticalLayout = new QVBoxLayout(IHM_Serveur);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(IHM_Serveur);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        spinBoxPortEcoute = new QSpinBox(IHM_Serveur);
        spinBoxPortEcoute->setObjectName("spinBoxPortEcoute");
        spinBoxPortEcoute->setMinimum(2048);
        spinBoxPortEcoute->setMaximum(65535);
        spinBoxPortEcoute->setValue(5555);

        horizontalLayout->addWidget(spinBoxPortEcoute);

        pushButtonLancer = new QPushButton(IHM_Serveur);
        pushButtonLancer->setObjectName("pushButtonLancer");

        horizontalLayout->addWidget(pushButtonLancer);


        verticalLayout->addLayout(horizontalLayout);

        textEditMessages = new QTextEdit(IHM_Serveur);
        textEditMessages->setObjectName("textEditMessages");

        verticalLayout->addWidget(textEditMessages);

        pushButtonQuitter = new QPushButton(IHM_Serveur);
        pushButtonQuitter->setObjectName("pushButtonQuitter");

        verticalLayout->addWidget(pushButtonQuitter);


        retranslateUi(IHM_Serveur);
        QObject::connect(pushButtonQuitter, &QPushButton::clicked, IHM_Serveur, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(IHM_Serveur);
    } // setupUi

    void retranslateUi(QWidget *IHM_Serveur)
    {
        IHM_Serveur->setWindowTitle(QCoreApplication::translate("IHM_Serveur", "IHM_Serveur", nullptr));
        label->setText(QCoreApplication::translate("IHM_Serveur", "Port d'\303\251coute", nullptr));
        pushButtonLancer->setText(QCoreApplication::translate("IHM_Serveur", "Lancer le serveur", nullptr));
        pushButtonQuitter->setText(QCoreApplication::translate("IHM_Serveur", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IHM_Serveur: public Ui_IHM_Serveur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHM_SERVEUR_H
