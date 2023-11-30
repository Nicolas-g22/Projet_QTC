#include "ihm_digicode.h"
#include "ui_ihm_digicode.h"

IHM_Digicode::IHM_Digicode(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IHM_Digicode)
{
    ui->setupUi(this);
    setFixedSize(QSize(274,446));
    int i = 0;
    int colonne=0, ligne=0;
    grille = new QGridLayout(this);
    afficheur = new QLineEdit(this);
    afficheur->setReadOnly(true);
    afficheur->setAlignment(Qt::AlignRight);
    afficheur->setEchoMode(QLineEdit::Password);
    afficheur->setMinimumHeight(80);
    afficheur->setPlaceholderText("Entrez un code");
    afficheur->setStyleSheet("background-color : #ffffff");
    afficheur->setMaxLength(4);
    // effacer le contenu de l'afficheur
    afficheur->clear();

    // ajouter l'afficheur dans le gridLayout
    grille->addWidget(afficheur,ligne,colonne,1,3);

    // Création du clavier
    const QString TableDesSymboles[NBTOUCHES]={"7", "8", "9",
                                               "4", "5", "6",
                                               "1", "2", "3",
                                               "On", "0", "Ok"};


    for(ligne = 1; ligne<5; ligne++){
        for(colonne = 0; colonne<3; colonne++){
            touches[i] = new QPushButton();
            connect(touches[i], &QPushButton::clicked, this , &IHM_Digicode::onQPushButtonClicked);
            touches[i]->setText(TableDesSymboles[i]);
            grille->addWidget(touches[i], ligne, colonne);
            touches[i] -> setFixedSize(QSize(80,80));
            i++;
        }
        if(colonne == 3){
            colonne = 0;
        }
    }
    this->setLayout(grille);
}




void IHM_Digicode::onQPushButtonClicked(){
    QPushButton *touche;
    touche=qobject_cast<QPushButton*>(sender());
    if(touche->text() == "On") {
        afficheur -> setPlaceholderText("Entrez un code");
        afficheur -> setStyleSheet("background-color : #FFFFFF");
        afficheur -> clear();
    }
    else{
        if(touche->text() == "Ok"){
            if(modeAdmin == true){
                gestionModeAdmin();
            }

            else{
                gestionModeNormal();
            }
        }

    }
    if(touche->text() != "Ok" && touche->text() != "On"){
        QString val = touche->text();
        afficheur -> insert(val);
    }
}



void IHM_Digicode::gestionModeNormal()
{
    if(afficheur->text() == codeOuverture){
        afficheur -> setPlaceholderText("Code ouverture OK");
        afficheur -> setStyleSheet("background-color : #90EE90");
        afficheur -> clear();
    }
    else{
        if(afficheur->text() == codeAdmin){
            modeAdmin = true;
            afficheur -> setPlaceholderText("Mode admin");
            afficheur -> setStyleSheet("background-color : #FFFFE0");
            afficheur -> clear();
        }
        else{
            afficheur -> setPlaceholderText("Code inconnu");
            afficheur -> setStyleSheet("background-color : #FFCCCB");
            afficheur -> clear();
        }
    }
}

void IHM_Digicode::gestionModeAdmin()
{
    modeAdmin=false;
    if(afficheur -> text() != codeAdmin && afficheur->text().length() == 4){
        codeOuverture=afficheur->text();
        afficheur->setPlaceholderText("Nouveau code ouverture accepté");
        afficheur->clear();
        QTimer *timer=new QTimer(this);
        connect(timer,&QTimer::timeout,this,[=](){
            afficheur->setPlaceholderText("Entrez un code");
            afficheur->setStyleSheet("background-color : #ffffff");
            timer->stop();
            timer->deleteLater();
        });
        timer->start(3000);
    }
    else{
        afficheur -> setPlaceholderText("Code non valable");
        afficheur -> setStyleSheet("background-color : #FFCCCB");
        afficheur -> clear();
    }

}

IHM_Digicode::~IHM_Digicode()
{
    delete ui;
}





