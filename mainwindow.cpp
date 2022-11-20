#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "entreprise.h"
#include <QString>
#include<QDateEdit>
#include <QTabWidget>
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlError>
#include<QSqlQuery>
#include<QIntValidator>
#include<QFile>
#include<QFileDialog>
#include<QThread>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
      ui->setupUi(this);
      ui->tableView->setModel(e.afficher());
      ui->tableView_2->setModel(e.afficher());
      ui->comboBox_2->setModel(e.affichervaleur("ID_E"));
      ui->comboboxEntrpriseVoyage->setModel(e.affichervaleur("ID_E"));

      //combobocEntrpriseVoyage

      int ret=A.connect_arduino(); // lancer la connexion à arduino
      switch(ret){
      case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
          break;
      case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
         break;
      case(-1):qDebug() << "arduino is not available";
      }
       QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
       //le slot update_label suite à la reception du signal readyRead (reception des données).



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")
        ui->label_3->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")
        ui->label_3->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}


void MainWindow::on_pushButton_clicked()
{

     int id_e=ui->lineEdit->text().toInt();
     QString nom=ui->lineEdit_2->text();
     QString adresse=ui->lineEdit_3->text();
      int tel=ui->lineEdit_4->text().toInt();
       entreprise e(id_e,nom,adresse,tel);

 if ((ui->lineEdit->text().isEmpty()||ui->lineEdit_2->text().isEmpty()||ui->lineEdit_3->text().isEmpty()||ui->lineEdit_4->text().isEmpty()))
       {
           A.write_to_arduino("2"); //envoyer 1 à arduino
           QMessageBox::critical(nullptr,QObject::tr("not ok"),
                      QObject::tr("remplir tout les donées.\n"
                                  "click Cancel to exit."),QMessageBox::Cancel);

       }
        else {
     bool test=e.ajouter();
     if (test)
     {
         A.write_to_arduino("1"); //envoyer 1 à arduino
         // Refresh (Actualiser)
         ui->tableView->setModel(e.afficher());
          ui->tableView_2->setModel(e.afficher());
          ui->comboBox_2->setModel(e.affichervaleur("ID_E"));
         QMessageBox::information(nullptr,QObject::tr("ok"),
                                  QObject::tr("ajout effectué.\n"
                                              "click Cancel to exit."),QMessageBox::Cancel);


     }else{
            A.write_to_arduino("3"); //envoyer 1 à arduino
             QMessageBox::critical(nullptr,QObject::tr("not ok"),
                        QObject::tr("ajout non effectué.\n"
                                    "click Cancel to exit."),QMessageBox::Cancel);

     }
 }


}
;


void MainWindow::on_pushButton_6_clicked()
{
    int id=ui->comboBox_2->currentText().toInt();

    bool test1=e.supprimer(id);
    if (test1)
    {
        // Refresh (Actualiser)
         ui->tableView->setModel(e.afficher());
         ui->comboBox_2->setModel(e.affichervaleur("ID_E"));
          ui->tableView_2->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("supression effectué.\n"
                                             "click Cancel to exit."),QMessageBox::Cancel);

                       QThread::sleep(1);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                   QObject::tr("Supression non effectué.\n"
                               "Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_4_clicked()
{
    entreprise e;
      int id_e=ui->lineEdit_6->text().toInt();
    QString nom=ui->lineEdit_14->text();
    QString adresse=ui->lineEdit_15->text();
     int tel=ui->lineEdit_16->text().toInt();

     bool test=e.modifier(id_e,nom,adresse,tel);

      if (test)
      {
          // Refresh (Actualiser)
           ui->tableView->setModel(e.afficher());
           ui->comboBox_2->setModel(e.affichervaleur("ID_E"));
            ui->tableView_2->setModel(e.afficher());
          QMessageBox::information(nullptr,QObject::tr("ok"),
                                   QObject::tr("modification effectué.\n"
                                               "click Cancel to exit."),QMessageBox::Cancel);

      }
      else
          QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                     QObject::tr("modification non effectué.\n"
                                 "Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    ui->comboboxEntrpriseVoyage->setModel(e.affichervaleur("ID_E"));
    if ( index == 5){
        QSqlQuery* query = e.statistique();
        int fidelisation1=0;
        int fidelisation2=0;
        int fidelisation3=0;
        while ( query->next() ){
            if ( query->value(4).toInt() == 1){
                fidelisation1 += 1;  // fidelisation1 = 2
            }
            if ( query->value(4).toInt() == 2){
                fidelisation2 += 1;  // fidelisation2 = 1
            }
            if ( query->value(4).toInt() == 3){
                fidelisation3 += 1;  // fidelisation3 = 1
            }
        }
        QPieSeries* series = new QPieSeries();
        series->append("Type 1", fidelisation1);
        series->append("Type 2", fidelisation2);
        series->append("Type 3", fidelisation3);

        QChart* chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("les type de fidelisations et leur taux");

        QChartView* chartView = new QChartView(chart);
        chartView->setParent(ui->horizontalFrame);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    int idEntreprise =ui->comboboxEntrpriseVoyage->currentText().toInt();

    QSqlQuery* queryVoyage = e.getVoyagesEntreprise(idEntreprise);
    QSqlQuery* queryEntreprise = e.getPromotionEntreprise(idEntreprise);
    int rowCount = 0;
    ui->tableWidget_3->setColumnCount(4);
    QStringList labels;
    labels << "ID Voyage" << "prix sans reduction" << "promotion" << "prix apres reduction";
    ui->tableWidget_3->setHorizontalHeaderLabels(labels);
    ui->tableWidget_3->setRowCount(0);
    while( queryEntreprise->next()){
        while( queryVoyage->next()){

            ui->tableWidget_3->insertRow(rowCount);
            int prixbillet = queryVoyage->value(1).toInt();
            int promotion = queryEntreprise->value(0).toInt();
            int nouveauPrix = prixbillet - ( prixbillet * promotion / 100);
            QTableWidgetItem * idVoyage = new QTableWidgetItem;
            QTableWidgetItem * ancienprix = new QTableWidgetItem;
            QTableWidgetItem * promo = new QTableWidgetItem;
            QTableWidgetItem * nouveauprix = new QTableWidgetItem;

            idVoyage->setText(queryVoyage->value(0).toString());
            ancienprix->setText(queryVoyage->value(1).toString());
            promo->setText(queryEntreprise->value(0).toString());
            nouveauprix->setText(QString::number(nouveauPrix));

            ui->tableWidget_3->setItem(rowCount,0,idVoyage);
            ui->tableWidget_3->setItem(rowCount,1,ancienprix);
            ui->tableWidget_3->setItem(rowCount,2,promo);
            ui->tableWidget_3->setItem(rowCount,3,nouveauprix);
            qDebug() << prixbillet << promotion << nouveauPrix ;
            rowCount++;
        }

    }

}

void MainWindow::on_searchLine_textChanged(const QString &arg1)
{

    int checkButton = 3;
    if ( ui->radioButton->isChecked() ){
        checkButton = 0;
    }else if ( ui->radioButton_2->isChecked() ){
        checkButton = 1;
    } if ( ui->radioButton_3->isChecked() ){
        checkButton = 2;
    }

    ui->tableView->setModel(e.recherche_avancee(arg1 , checkButton));
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->tableView->setModel(e.tri_avancee(arg1));
}
