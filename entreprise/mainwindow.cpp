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
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
      ui->setupUi(this);
      ui->tableView->setModel(e.afficher());
      ui->tableView_2->setModel(e.afficher());
      ui->comboBox_2->setModel(e.affichervaleur("ID_E"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int id_e=ui->lineEdit->text().toInt();
     QString nom=ui->lineEdit_2->text();
     QString adresse=ui->lineEdit_3->text();
      int tel=ui->lineEdit_4->text().toInt();
       entreprise e(id_e,nom,adresse,tel);
       bool test=e.ajouter();
       if (test)
       {
           // Refresh (Actualiser)
           ui->tableView->setModel(e.afficher());
            ui->tableView_2->setModel(e.afficher());
            ui->comboBox_2->setModel(e.affichervaleur("ID_E"));
           QMessageBox::information(nullptr,QObject::tr("ok"),
                                    QObject::tr("ajout effectué.\n"
                                                "click Cancel to exit."),QMessageBox::Cancel);

       }
else if ((ui->lineEdit->text().isEmpty()||ui->lineEdit_2->text().isEmpty()||ui->lineEdit_3->text().isEmpty()||ui->lineEdit_4->text().isEmpty()))
       {
           QMessageBox::critical(nullptr,QObject::tr("not ok"),
                      QObject::tr("remplir tout les donées.\n"
                                  "click Cancel to exit."),QMessageBox::Cancel);
       }
       else
           QMessageBox::critical(nullptr,QObject::tr("not ok"),
                      QObject::tr("ajout non effectué.\n"
                                  "click Cancel to exit."),QMessageBox::Cancel);

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
