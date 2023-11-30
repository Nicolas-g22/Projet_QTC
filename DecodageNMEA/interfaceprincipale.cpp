#include "interfaceprincipale.h"
#include "ui_interfaceprincipale.h"

InterfacePrincipale::InterfacePrincipale(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::InterfacePrincipale)
    , configGPS(lePort)
{
    ui->setupUi(this);
    labelEtatPort.setText("port fermé");
    ui->statusbar->addPermanentWidget(&labelEtatPort);
    ui->statusbar->show();
    ui->tableWidgetNMEA->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    connect(&lePort, &QSerialPort::readyRead, this, &InterfacePrincipale::onQserialPort_ReadyRead);
}

InterfacePrincipale::~InterfacePrincipale()
{
    delete ui;
}

//Fonction D'écriture
void InterfacePrincipale::onQserialPort_ReadyRead()
{
    QString trameCourante;
    buffer.append(lePort.readAll());
    if(buffer.count('\n')>0){
        trameCourante = buffer.left(buffer.indexOf('\n'));
        buffer.remove(0, buffer.indexOf('\n')+1);
        ui->textEditTrame->append(trameCourante);
        DecodageNMEA(trameCourante);
    }


}


void InterfacePrincipale::on_actionConfigurer_triggered()
{
    if (configGPS.exec() == QDialog::Accepted)
    { 	// ouverture du port et connexion du signal readyRead

        QString _parity;
        QString result;
        switch(lePort.parity()){

        case 0:
            _parity = "n";
            break;

        case 2:
            _parity = "p";
            break;

        case 3:
            _parity = "i";
            break;

        default:
            break;
        }

        QTextStream(&result)<<"Port " << lePort.portName() << ", " << lePort.baudRate() << ", " << lePort.dataBits() << ", " << _parity << ", " << lePort.stopBits();
        labelEtatPort.setText(result);
        if (lePort.open(QSerialPort::ReadWrite)){
            qDebug()<<"ouverture port ok";
        }
        else
        {
            qDebug()<<"ouverture port pas ok";
        }
    }

}

void InterfacePrincipale::DecodageNMEA(const QString &_trameNMEA)
{
    QStringList champsNMEA = _trameNMEA.split(',');

    if (champsNMEA.size() >= 12 && champsNMEA.at(0) == "$GPRMC")
    {
        // Extraction de l'heure
        QString heureStr = champsNMEA.at(1);
        QTime heure(heureStr.mid(0, 2).toInt(), heureStr.mid(2, 2).toInt(), heureStr.mid(4, 2).toInt());

        //Extraction de la date
        QString dateStr = champsNMEA.at(9);
        QDate date(dateStr.mid(4,2).toInt()+2000, dateStr.mid(2,2).toInt(),dateStr.mid(0,2).toInt() );

        //Extraction de la latitude
        QString latitudeStr = champsNMEA.at(3);
        QString latitudeDStr = champsNMEA.at(4);
        QString latitude = latitudeStr + latitudeDStr;

        //Extraction de la latitude
        QString longitudeStr = champsNMEA.at(5);
        QString longitudeDStr = champsNMEA.at(6);
        QString longitude = longitudeStr + longitudeDStr;


        //Horodatage
        QDateTime horodatage(date, heure, QTimeZone("Europe/Paris"));
        horodatage = horodatage.addSecs(horodatage.offsetFromUtc());



        int ligneCourante = ui->tableWidgetNMEA->rowCount();
        ui->tableWidgetNMEA->insertRow(ligneCourante);

        QTableWidgetItem *dateItem = new QTableWidgetItem(horodatage.toString(Qt::TextDate));
        ui->tableWidgetNMEA->setItem(ligneCourante,0,dateItem);

        QTableWidgetItem *latitudeItem = new QTableWidgetItem(latitude);
        ui->tableWidgetNMEA->setItem(ligneCourante,1,latitudeItem);

        QTableWidgetItem *longitudeItem = new QTableWidgetItem(longitude);
        ui->tableWidgetNMEA->setItem(ligneCourante,2,longitudeItem);

        // à compléter pour les autres colonnes du tableau
    }
}

void InterfacePrincipale::on_actionEnregistrer_triggered()
{
    QString nomFichier = QFileDialog::getSaveFileName(this, "");
    if (!nomFichier.isEmpty())
    {
        QFile fichierCSV(nomFichier);

        if (fichierCSV.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream flux(&fichierCSV); // pour l’écriture dans le fichier on utilise les flux
            flux << "Date; Latitude; Longitude\n";
            // Ajouter ici le code pour parcourir le tableWidgetNMEA et stocker dans le fichier chaque élément

            fichierCSV.close();
            qDebug() << "Enregistrement au format CSV réussi.";
        }

        else
        {
            qDebug() << "Erreur : Impossible d'ouvrir le fichier CSV.";
        }

    }
    else
    {
        qDebug() << "L'opération d'enregistrement a été annulée.";
    }
}


