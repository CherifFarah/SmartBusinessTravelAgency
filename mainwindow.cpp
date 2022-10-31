#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personnel.h"
#include <QMessageBox>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator(0, 99999999, this));
    ui->supp_id->setValidator(new QIntValidator(0, 99999999, this));
    ui->lineEdit_2->setValidator(new QIntValidator(0, 99999999, this));


    ui->tableView->setModel(Ptmp.afficher());
    ui->tableView_2->setModel(Ptmp.afficher());

    QPixmap photo("C:/Users/MSI/Downloads/logo.png");
    ui->label_6->setPixmap(photo.scaled(160,160,Qt::KeepAspectRatio));

    QPixmap photo9("C:/Users/MSI/Downloads/cap_slide2.png");
    ui->label->setPixmap(photo9.scaled(1322,742,Qt::KeepAspectRatio));


    QPixmap photo2("C:/Users/MSI/Downloads/startup.png");
    ui->label_12->setPixmap(photo2.scaled(130,130,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_clicked()
{
    int ID=ui->lineEdit->text().toInt();
    QString Nom_Prenom=ui->lineEdit_nom->text();
    QString DateN=ui->date_naissance->text();
    QString Tel=ui->lineEdit_tel->text();
    QString Adresse=ui->lineEdit_adresse->text();
    Personnel P (ID, Nom_Prenom, DateN, Tel, Adresse);
    bool test=P.ajouter();
    if (test)
    {
        ui->tableView->setModel(P.afficher());
        ui->tableView_2->setModel(P.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Ajout effectué\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Ajout non effectué\n" "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_supprimer_clicked()
{
    int ID=ui->supp_id->text().toInt();
    bool test=Ptmp.supprimer(ID);
    if (test)
    {
        ui->tableView->setModel(Ptmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Suppression effectuée\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Suppression non effectuée\n" "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_modifier_clicked()
{
   int ID=ui->lineEdit_2->text().toInt();
   QString Nom_Prenom=ui->lineEdit_nom_2->text();
   QString DateN=ui->date_naissance_2->text();
   QString Tel=ui->lineEdit_tel_2->text();
   QString Adresse=ui->lineEdit_adresse_2->text();
   //Personnel P;
   bool test;
   test=Ptmp.modifier(ID, Nom_Prenom, DateN, Tel, Adresse);
   if (test)
   {
       ui->tableView->setModel(Ptmp.afficher());
       ui->tableView_2->setModel(Ptmp.afficher());

       QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Modification effectuée\n" "Click Cancel to exit."), QMessageBox::Cancel);
   }
   else QMessageBox::critical(nullptr, QObject::tr("Not OK"), QObject::tr("Modification non effectuée\n" "Click Cancel to exit."), QMessageBox::Cancel);


}




