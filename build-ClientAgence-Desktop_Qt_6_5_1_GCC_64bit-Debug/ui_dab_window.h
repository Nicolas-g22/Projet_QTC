/********************************************************************************
** Form generated from reading UI file 'dab_window.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAB_WINDOW_H
#define UI_DAB_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DAB_Window
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBoxConnexion;
    QGridLayout *gridLayout;
    QPushButton *pushButtonConnexion;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *textEditEtatConnexion;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEditAdresse;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *spinBoxPort;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonQuitter;
    QGroupBox *groupBoxInteraction;
    QGridLayout *gridLayout_4;
    QLabel *label_5;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *lineEditNom;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QLineEdit *lineEditPrenom;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QLineEdit *lineEditEmail;
    QComboBox *comboBoxVols;
    QGridLayout *gridLayoutPlaces;
    QPushButton *pushButtonValider;

    void setupUi(QWidget *DAB_Window)
    {
        if (DAB_Window->objectName().isEmpty())
            DAB_Window->setObjectName("DAB_Window");
        DAB_Window->resize(611, 623);
        gridLayout_3 = new QGridLayout(DAB_Window);
        gridLayout_3->setObjectName("gridLayout_3");
        groupBoxConnexion = new QGroupBox(DAB_Window);
        groupBoxConnexion->setObjectName("groupBoxConnexion");
        gridLayout = new QGridLayout(groupBoxConnexion);
        gridLayout->setObjectName("gridLayout");
        pushButtonConnexion = new QPushButton(groupBoxConnexion);
        pushButtonConnexion->setObjectName("pushButtonConnexion");

        gridLayout->addWidget(pushButtonConnexion, 3, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(groupBoxConnexion);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        textEditEtatConnexion = new QTextEdit(groupBoxConnexion);
        textEditEtatConnexion->setObjectName("textEditEtatConnexion");

        verticalLayout->addWidget(textEditEtatConnexion);


        gridLayout->addLayout(verticalLayout, 1, 1, 3, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(groupBoxConnexion);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        lineEditAdresse = new QLineEdit(groupBoxConnexion);
        lineEditAdresse->setObjectName("lineEditAdresse");

        horizontalLayout->addWidget(lineEditAdresse);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(groupBoxConnexion);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        spinBoxPort = new QSpinBox(groupBoxConnexion);
        spinBoxPort->setObjectName("spinBoxPort");
        spinBoxPort->setMaximum(9999);
        spinBoxPort->setValue(5555);

        horizontalLayout_2->addWidget(spinBoxPort);

        horizontalSpacer = new QSpacerItem(150, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        gridLayout_3->addWidget(groupBoxConnexion, 0, 0, 1, 1);

        pushButtonQuitter = new QPushButton(DAB_Window);
        pushButtonQuitter->setObjectName("pushButtonQuitter");

        gridLayout_3->addWidget(pushButtonQuitter, 2, 0, 1, 1);

        groupBoxInteraction = new QGroupBox(DAB_Window);
        groupBoxInteraction->setObjectName("groupBoxInteraction");
        groupBoxInteraction->setEnabled(false);
        gridLayout_4 = new QGridLayout(groupBoxInteraction);
        gridLayout_4->setObjectName("gridLayout_4");
        label_5 = new QLabel(groupBoxInteraction);
        label_5->setObjectName("label_5");

        gridLayout_4->addWidget(label_5, 1, 1, 1, 1);

        label_4 = new QLabel(groupBoxInteraction);
        label_4->setObjectName("label_4");

        gridLayout_4->addWidget(label_4, 0, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_6 = new QLabel(groupBoxInteraction);
        label_6->setObjectName("label_6");

        horizontalLayout_3->addWidget(label_6);

        lineEditNom = new QLineEdit(groupBoxInteraction);
        lineEditNom->setObjectName("lineEditNom");

        horizontalLayout_3->addWidget(lineEditNom);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_7 = new QLabel(groupBoxInteraction);
        label_7->setObjectName("label_7");

        horizontalLayout_4->addWidget(label_7);

        lineEditPrenom = new QLineEdit(groupBoxInteraction);
        lineEditPrenom->setObjectName("lineEditPrenom");

        horizontalLayout_4->addWidget(lineEditPrenom);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_8 = new QLabel(groupBoxInteraction);
        label_8->setObjectName("label_8");

        horizontalLayout_5->addWidget(label_8);

        lineEditEmail = new QLineEdit(groupBoxInteraction);
        lineEditEmail->setObjectName("lineEditEmail");

        horizontalLayout_5->addWidget(lineEditEmail);


        verticalLayout_2->addLayout(horizontalLayout_5);


        gridLayout_4->addLayout(verticalLayout_2, 2, 1, 1, 2);

        comboBoxVols = new QComboBox(groupBoxInteraction);
        comboBoxVols->setObjectName("comboBoxVols");

        gridLayout_4->addWidget(comboBoxVols, 0, 2, 1, 1);

        gridLayoutPlaces = new QGridLayout();
        gridLayoutPlaces->setObjectName("gridLayoutPlaces");

        gridLayout_4->addLayout(gridLayoutPlaces, 1, 2, 1, 1);

        pushButtonValider = new QPushButton(groupBoxInteraction);
        pushButtonValider->setObjectName("pushButtonValider");

        gridLayout_4->addWidget(pushButtonValider, 3, 2, 1, 1);


        gridLayout_3->addWidget(groupBoxInteraction, 1, 0, 1, 1);


        retranslateUi(DAB_Window);
        QObject::connect(pushButtonQuitter, &QPushButton::clicked, DAB_Window, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(DAB_Window);
    } // setupUi

    void retranslateUi(QWidget *DAB_Window)
    {
        DAB_Window->setWindowTitle(QCoreApplication::translate("DAB_Window", "DAB_Window", nullptr));
        groupBoxConnexion->setTitle(QCoreApplication::translate("DAB_Window", "Etablissement de la connexion", nullptr));
        pushButtonConnexion->setText(QCoreApplication::translate("DAB_Window", "Connexion", nullptr));
        label->setText(QCoreApplication::translate("DAB_Window", "Etat de la connexion", nullptr));
        label_2->setText(QCoreApplication::translate("DAB_Window", "Adresse", nullptr));
        lineEditAdresse->setText(QCoreApplication::translate("DAB_Window", "172.18.58.73", nullptr));
        label_3->setText(QCoreApplication::translate("DAB_Window", "Port", nullptr));
        pushButtonQuitter->setText(QCoreApplication::translate("DAB_Window", "Quitter", nullptr));
        groupBoxInteraction->setTitle(QCoreApplication::translate("DAB_Window", "Int\303\251raction agence", nullptr));
        label_5->setText(QCoreApplication::translate("DAB_Window", "Places libres", nullptr));
        label_4->setText(QCoreApplication::translate("DAB_Window", "Vols disponibles", nullptr));
        label_6->setText(QCoreApplication::translate("DAB_Window", "Nom", nullptr));
        label_7->setText(QCoreApplication::translate("DAB_Window", "Pr\303\251nom", nullptr));
        label_8->setText(QCoreApplication::translate("DAB_Window", "Email", nullptr));
        pushButtonValider->setText(QCoreApplication::translate("DAB_Window", "Valider la commande", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DAB_Window: public Ui_DAB_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAB_WINDOW_H
