#include "calculatricefd.h"
#include "ui_calculatricefd.h"

Calculatricefd::Calculatricefd(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculatricefd)
{
    ui->setupUi(this);
    int i = 0;
    int colonne, ligne;
    grille=new QGridLayout();
    afficheur=new QLineEdit();
    afficheur->setReadOnly(true);
    afficheur->setAlignment(Qt::AlignRight);
    grille->addWidget(afficheur,0,0,1,4); //(y,x,rowspan,colspan)


    for(ligne = 1; ligne<5; ligne++){
        for(colonne = 0; colonne<4; colonne++){
            touches[i] = new QPushButton();
            if(tableDesSymboles[i] == 'c'){
                connect(touches[i], &QPushButton::clicked, this , &Calculatricefd::onQPushButtonClearclicked);
            }
            else{
                if(tableDesSymboles[i] == '='){
                    connect(touches[i], &QPushButton::clicked, this , &Calculatricefd::onQPushButtonEgalclicked);
                }

                else{
                    connect(touches[i], &QPushButton::clicked, this , &Calculatricefd::onQPushButtonClicked);
                }


            }
            touches[i]->setText(tableDesSymboles[i]);
            grille->addWidget(touches[i], ligne, colonne);
            i++;
        }
        if(colonne == 4){
            colonne = 0;
        }
    }

    // ajout du layout à l'interface principale
    this->setLayout(grille);
}




void Calculatricefd::onQPushButtonEgalclicked()
{
    QJSEngine myEngine;
    QJSValue resultat;
    QString affichage;

    affichage = afficheur -> text();

    resultat = myEngine.evaluate(affichage);

    afficheur->setText(resultat.toString());
}

void Calculatricefd::onQPushButtonClearclicked()
{
    afficheur->clear();
}

void Calculatricefd::onQPushButtonClicked(){
    QPushButton *touche;
    touche=qobject_cast<QPushButton*>(sender());
    QString val = touche->text();
    afficheur -> insert(val);
}

Calculatricefd::~Calculatricefd()
{
    delete ui;
}
