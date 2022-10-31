#include "voyageinterface.h"
#include "ui_voyageinterface.h"
#include <QDebug>
#include <attribute.h>
#include <QtWidgets>
#include <iostream>
#include <QDate>
#include <QAbstractItemModel>
#include <QDebug>


VoyageInterface::VoyageInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VoyageInterface)
{
    ui->setupUi(this);
    ui->tableView->hide();
    ui->Destination->hide();
    ui->DestinationLabel->hide();
    ui->PrixBillet->hide();
    ui->AjouterButton->hide();
    ui->PrixBilletLabel->hide();
    ui->Date->hide();
    ui->DateLabel->hide();
    ui->ClientCIN->hide();
    ui->ClientCINLabel->hide();
    ui->ModifierCIN->hide();
    ui->ModifierDestination->hide();
    ui->ModifierDateVoyage->hide();
    ui->ModifierPrixBillet->hide();
    ui->tableViewUpdate->hide();
    ui->tableView->setFocusPolicy(Qt::NoFocus);
    ui->AjouterVoyageButton->setFocusPolicy(Qt::NoFocus);
    ui->SupprimerVoyageButton->setFocusPolicy(Qt::NoFocus);

    setAddTravelClicked(1);
    setDeleteTravelClicked(1);
    setReadTravelClicked(1);

    //Animation ajouter flight
int x=207,y=245;
ui->Title->setText("Selectionner une Operation");

animation=new QPropertyAnimation(ui->AjouterVoyageButton,"geometry");
animation->setDuration(900);
animation->setStartValue(ui->AjouterVoyageButton->geometry());
animation->setEndValue(QRect(x,y,161,39));
QEasingCurve curve;
curve.setType(QEasingCurve::OutSine);
//outSine/outBounce/outBack
animation->setEasingCurve(curve);
animation->start();

//Animation Modifier flight
deleteFlightAnimation=new QPropertyAnimation(ui->SupprimerVoyageButton,"geometry");
deleteFlightAnimation->setDuration(900);
deleteFlightAnimation->setStartValue(ui->SupprimerVoyageButton->geometry());
deleteFlightAnimation->setEndValue(QRect(x+220,y,161,39));
deleteFlightAnimation->setEasingCurve(curve);
deleteFlightAnimation->start();

//Animation Afficher flight
readFlightAnimation=new QPropertyAnimation(ui->AfficherVoyageButton,"geometry");
readFlightAnimation->setDuration(900);
readFlightAnimation->setStartValue(ui->AfficherVoyageButton->geometry());
readFlightAnimation->setEndValue(QRect(x+440,y,161,41));
readFlightAnimation->setEasingCurve(curve);
readFlightAnimation->start();

updateFlightAnimation=new QPropertyAnimation(ui->ModifierVoyageButton,"geometry");
updateFlightAnimation->setDuration(900);
updateFlightAnimation->setStartValue(ui->ModifierVoyageButton->geometry());
updateFlightAnimation->setEndValue(QRect(x+220,y+80,161,41));
updateFlightAnimation->setEasingCurve(curve);
updateFlightAnimation->start();

//animationGroupe=new QParallelAnimationGroup;
//animationGroupe->addAnimation(animation);
//animationGroupe->addAnimation(deleteFlightAnimation);
//animationGroupe->addAnimation(readFlightAnimation);
//animationGroupe->start();




}

void VoyageInterface::setClickedAnimation()
{
    int x=850,y=130;

    animation=new QPropertyAnimation(ui->AjouterVoyageButton,"geometry");
    animation->setDuration(800);
    animation->setStartValue(ui->AjouterVoyageButton->geometry());
    animation->setEndValue(QRect(x,y,161,41));
    QEasingCurve curve;
    curve.setType(QEasingCurve::OutSine);
    //outSine/outBounce/outBack
    animation->setEasingCurve(curve);
    animation->start();

    deleteFlightAnimation=new QPropertyAnimation(ui->SupprimerVoyageButton,"geometry");
    deleteFlightAnimation->setDuration(900);
    deleteFlightAnimation->setStartValue(ui->SupprimerVoyageButton->geometry());
    deleteFlightAnimation->setEndValue(QRect(x,y+110,161,41));
    deleteFlightAnimation->setEasingCurve(curve);
    deleteFlightAnimation->start();

    //Animation Afficher flight
    readFlightAnimation=new QPropertyAnimation(ui->AfficherVoyageButton,"geometry");
    readFlightAnimation->setDuration(1000);
    readFlightAnimation->setStartValue(ui->AfficherVoyageButton->geometry());
    readFlightAnimation->setEndValue(QRect(x,y+220,161,41));
    readFlightAnimation->setEasingCurve(curve);
    readFlightAnimation->start();

    updateFlightAnimation=new QPropertyAnimation(ui->ModifierVoyageButton,"geometry");
    updateFlightAnimation->setDuration(1000);
    updateFlightAnimation->setStartValue(ui->ModifierVoyageButton->geometry());
    updateFlightAnimation->setEndValue(QRect(x,y+330,161,41));
    updateFlightAnimation->setEasingCurve(curve);
    updateFlightAnimation->start();


}

VoyageInterface::~VoyageInterface()
{
    delete ui;
}


void VoyageInterface::on_AjouterVoyageButton_clicked()

{
    //hide ajouter Widgets
    ui->Destination->show();
    ui->DestinationLabel->show();
    ui->Title->setText("Ajouter Un Voyage");
    ui->Title->setStyleSheet("color:rgb(253,250,250);");
    ui->Date->show();
    ui->DateLabel->show();
    ui->PrixBillet->show();
    ui->PrixBilletLabel->show();
    ui->ClientCIN->show();
    ui->ClientCINLabel->show();
    ui->AjouterButton->show();
    ui->tableView->hide();
    ui->DeleteButton->hide();
    ui->SelectLigne->hide();
    ui->Update->hide();

    //Update Button Widgets
    ui->ModifierCIN->hide();
    ui->ModifierDateVoyage->hide();
    ui->ModifierPrixBillet->hide();
    ui->ModifierDestination->hide();
    ui->tableViewUpdate->hide();

    if(addTravelClicked==1)
    {

        setClickedAnimation();
        QEasingCurve curve;

        animation=new QPropertyAnimation(ui->ClientCIN,"geometry");
        animation->setDuration(600);
        animation->setStartValue(ui->ClientCIN->geometry());
        animation->setEndValue(QRect(160,180,151,20));
        curve.setType(QEasingCurve::OutSine);
        //outSine/outBounce/outBack
        animation->setEasingCurve(curve);
        animation->start();

        animation=new QPropertyAnimation(ui->ClientCINLabel,"geometry");
        animation->setDuration(600);
        animation->setStartValue(ui->ClientCINLabel->geometry());
        animation->setEndValue(QRect(70,180,81,20));
        curve.setType(QEasingCurve::OutSine);
        //outSine/outBounce/outBack
        animation->setEasingCurve(curve);
        animation->start();

animation=new QPropertyAnimation(ui->Destination,"geometry");
animation->setDuration(600);
animation->setStartValue(ui->Destination->geometry());
animation->setEndValue(QRect(480,180,201,21));
curve.setType(QEasingCurve::OutSine);
//outSine/outBounce/outBack
animation->setEasingCurve(curve);
animation->start();

animation=new QPropertyAnimation(ui->DestinationLabel,"geometry");
animation->setDuration(600);
animation->setStartValue(ui->DestinationLabel->geometry());
animation->setEndValue(QRect(390,180,81,20));
curve.setType(QEasingCurve::OutSine);
//outSine/outBounce/outBack
animation->setEasingCurve(curve);
animation->start();

animation=new QPropertyAnimation(ui->Date,"geometry");
animation->setDuration(600);
animation->setStartValue(ui->Date->geometry());
animation->setEndValue(QRect(180,250,110,22));
curve.setType(QEasingCurve::OutSine);
//outSine/outBounce/outBack
animation->setEasingCurve(curve);
animation->start();

animation=new QPropertyAnimation(ui->DateLabel,"geometry");
animation->setDuration(600);
animation->setStartValue(ui->DateLabel->geometry());
animation->setEndValue(QRect(70,250,81,20));
curve.setType(QEasingCurve::OutSine);
//outSine/outBounce/outBack
animation->setEasingCurve(curve);
animation->start();

animation=new QPropertyAnimation(ui->PrixBillet,"geometry");
animation->setDuration(600);
animation->setStartValue(ui->PrixBillet->geometry());
animation->setEndValue(QRect(480,250,113,20));
curve.setType(QEasingCurve::OutSine);
//outSine/outBounce/outBack
animation->setEasingCurve(curve);
animation->start();

animation=new QPropertyAnimation(ui->PrixBilletLabel,"geometry");
animation->setDuration(600);
animation->setStartValue(ui->PrixBilletLabel->geometry());
animation->setEndValue(QRect(390,250,81,20));
curve.setType(QEasingCurve::OutSine);
//outSine/outBounce/outBack
animation->setEasingCurve(curve);
animation->start();

animation=new QPropertyAnimation(ui->AjouterButton,"geometry");
animation->setDuration(600);
animation->setStartValue(ui->AjouterButton->geometry());
animation->setEndValue(QRect(280,350,161,31));
curve.setType(QEasingCurve::OutSine);
//outSine/outBounce/outBack
animation->setEasingCurve(curve);
animation->start();

setAddTravelClicked(0);
    }



}
void VoyageInterface::on_AfficherVoyageButton_clicked()
{
voyage v;
ui->Title->setText("Afficher Un Voyage");
ui->Title->setStyleSheet("color:rgb(253,250,250);");

//addTravelWidgets
ui->Destination->hide();
ui->DestinationLabel->hide();
ui->Date->hide();
ui->DateLabel->hide();
ui->PrixBillet->hide();
ui->PrixBilletLabel->hide();
ui->ClientCIN->hide();
ui->ClientCINLabel->hide();
ui->tableView->show();

//deleteTravelWidgets
ui->SelectLigne->hide();
ui->DeleteButton->hide();
ui->tableView->setModel(v.afficherVoyage());
ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

//Update Button Widgets
ui->ModifierCIN->hide();
ui->ModifierDateVoyage->hide();
ui->ModifierPrixBillet->hide();
ui->ModifierDestination->hide();
ui->tableViewUpdate->hide();


//updateTravelWidget
ui->Update->hide();
    if(readTravelClicked==1)
    {
    QEasingCurve curve;

    animation=new QPropertyAnimation(ui->tableView,"geometry");
    animation->setDuration(600);
    animation->setStartValue(ui->tableView->geometry());
    animation->setEndValue(QRect(90,170,561,301));
    curve.setType(QEasingCurve::OutSine);
    //outSine/outBounce/outBack
    animation->setEasingCurve(curve);
    animation->start();
    setClickedAnimation();
    setReadTravelClicked(0);

    }
}

void VoyageInterface::on_SupprimerVoyageButton_clicked()
{
     voyage v;
    ui->Destination->hide();
    ui->DestinationLabel->hide();
    ui->Date->hide();
    ui->DateLabel->hide();
    ui->PrixBillet->hide();
    ui->PrixBilletLabel->hide();
    ui->ClientCIN->hide();
    ui->ClientCINLabel->hide();
    ui->Update->hide();
    //Update Button Widgets
    ui->ModifierCIN->hide();
    ui->ModifierDateVoyage->hide();
    ui->ModifierPrixBillet->hide();
    ui->ModifierDestination->hide();
    ui->tableViewUpdate->hide();

    //delete Button Widgets
    ui->DeleteButton->show();
    ui->SelectLigne->show();
    ui->tableView->show();
    ui->Title->setText("Supprimer Un Voyage");
    ui->Title->setStyleSheet("color:rgb(253,250,250);");
    ui->SelectLigne->setText("Selectionner une Ligne Pour supprimer");
    ui->tableView->setModel(v.afficherVoyage());
ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
   /* name->setText(ui->ClientCIN->text());
ui->tableView->setItem(0,0,name);*/


if(deleteTravelClicked==1)
{
    QEasingCurve curve;

    animation=new QPropertyAnimation(ui->tableView,"geometry");
    animation->setDuration(600);
    animation->setStartValue(ui->tableView->geometry());
    animation->setEndValue(QRect(90,170,561,301));
    curve.setType(QEasingCurve::OutSine);
    //outSine/outBounce/outBack
    animation->setEasingCurve(curve);
    animation->start();

    animation=new QPropertyAnimation(ui->DeleteButton,"geometry");
    animation->setDuration(600);
    animation->setStartValue(ui->DeleteButton->geometry());
    animation->setEndValue(QRect(280,500,161,39));
    curve.setType(QEasingCurve::OutSine);
    //outSine/outBounce/outBack
    animation->setEasingCurve(curve);
    animation->start();

    setClickedAnimation();
    setDeleteTravelClicked(0);

}
}

void VoyageInterface::on_ModifierVoyageButton_clicked()
{
    voyage v;
    int x=690,y=150,w=125,h=24;
    ui->Destination->hide();
    ui->DestinationLabel->hide();
    ui->Date->hide();
    ui->DateLabel->hide();
    ui->PrixBillet->hide();
    ui->PrixBilletLabel->hide();
    ui->ClientCIN->hide();
    ui->ClientCINLabel->hide();
    ui->tableView->hide();
    ui->DeleteButton->hide();
    ui->Update->show();
    ui->SelectLigne->show();
    ui->ModifierCIN->show();
    ui->ModifierDateVoyage->show();
    ui->ModifierPrixBillet->show();
    ui->ModifierDestination->show();
    ui->tableViewUpdate->show();
 ui->SelectLigne->setText("Selectionner une ligne pour Modifier");
    ui->Title->setText("Modifier Un Voyage");

    ui->tableViewUpdate->setModel(v.afficherVoyage());
    ui->tableViewUpdate->setSelectionBehavior(QAbstractItemView::SelectRows);

    if(updateTravelClicked)
    {
        QEasingCurve curve;
        curve.setType(QEasingCurve::OutSine);

        animation=new QPropertyAnimation(ui->tableViewUpdate,"geometry");
        animation->setDuration(600);
        animation->setStartValue(ui->tableViewUpdate->geometry());
        animation->setEndValue(QRect(90,170,561,301));
        //outSine/outBounce/outBack
        animation->setEasingCurve(curve);
        animation->start();

        animation=new QPropertyAnimation(ui->Update,"geometry");
        animation->setDuration(600);
        animation->setStartValue(ui->Update->geometry());
        animation->setEndValue(QRect(280,500,161,39));
        //outSine/outBounce/outBack
        animation->setEasingCurve(curve);
        animation->start();


        animation=new QPropertyAnimation(ui->ModifierCIN,"geometry");
        animation->setDuration(800);
        animation->setStartValue(ui->ModifierCIN->geometry());
        animation->setEndValue(QRect(x,y,w,h));
        animation->setEasingCurve(curve);
        animation->start();

        deleteFlightAnimation=new QPropertyAnimation(ui->ModifierDestination,"geometry");
        deleteFlightAnimation->setDuration(900);
        deleteFlightAnimation->setStartValue(ui->ModifierDestination->geometry());
        deleteFlightAnimation->setEndValue(QRect(x,y+90,w,h));
        deleteFlightAnimation->setEasingCurve(curve);
        deleteFlightAnimation->start();

        //Animation Afficher flight
        readFlightAnimation=new QPropertyAnimation(ui->ModifierDateVoyage,"geometry");
        readFlightAnimation->setDuration(1000);
        readFlightAnimation->setStartValue(ui->ModifierDateVoyage->geometry());
        readFlightAnimation->setEndValue(QRect(x,y+180,w,h));
        readFlightAnimation->setEasingCurve(curve);
        readFlightAnimation->start();

        updateFlightAnimation=new QPropertyAnimation(ui->ModifierPrixBillet,"geometry");
        updateFlightAnimation->setDuration(1000);
        updateFlightAnimation->setStartValue(ui->ModifierPrixBillet->geometry());
        updateFlightAnimation->setEndValue(QRect(x,y+270,w,h));
        updateFlightAnimation->setEasingCurve(curve);
        updateFlightAnimation->start();
        setUpdateTravelClicked(0);
        setClickedAnimation();

    }

    /*if(ui->tableView->rect().x()==90 && ui->tableView->rect().y()==170)
     ui->SelectLigne->setText("Selectionner une ligne pour Modifier");*/

}

void VoyageInterface::on_AjouterButton_clicked()
{

    QString cin=ui->ClientCIN->text();
    QString destination=ui->Destination->text();
    QString dateVoyage=ui->Date->text();
    float prixBillet=ui->PrixBillet->text().toFloat();
    voyage v(cin,destination,dateVoyage,prixBillet);

    bool test=v.ajouterVoyage();
if(test)
{
QMessageBox::information(nullptr,QObject::tr("Ok"),QObject::tr("Ajout effectué\n""Click Cancel to exit"),QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr,QObject::tr("Not Ok"),QObject::tr("Ajout non effectué\n""Click Cancel to exit"),QMessageBox::Cancel);

}

void VoyageInterface::on_DeleteButton_clicked()
{
voyage v;


    int ind=ui->tableView->selectionModel()->currentIndex().row();
    QString cin=ui->tableView->model()->index(ind,0).data().toString();
    v.SupprimerVoyage(cin);
ui->tableView->setModel(v.afficherVoyage());}



void VoyageInterface::on_Update_clicked()
{
voyage v;
QString cin,destination,date;
float prix;

cin=ui->ModifierCIN->text();
destination=ui->ModifierDestination->text();
date=ui->ModifierDateVoyage->text();
prix=ui->ModifierPrixBillet->text().toFloat();

v.modifierVoyage(cin,destination,date,prix);

ui->tableViewUpdate->setModel(v.afficherVoyage());
ui->ModifierCIN->clear();
ui->ModifierDestination->clear();
ui->ModifierPrixBillet->clear();
ui->ModifierDateVoyage->clear();

}

void VoyageInterface::on_tableViewUpdate_clicked()
{
    QString cin,destination,date,res;
    float prix;
    int ind=ui->tableViewUpdate->selectionModel()->currentIndex().row();
    res=ui->tableViewUpdate->model()->index(ind,3).data().toString();

    cin=ui->tableViewUpdate->model()->index(ind,0).data().toString();
    destination=ui->tableViewUpdate->model()->index(ind,1).data().toString();
    date=ui->tableViewUpdate->model()->index(ind,2).data().toString();
    prix=ui->tableViewUpdate->model()->index(ind,3).data().toFloat();

    ui->ModifierCIN->setText(cin);
    ui->ModifierDateVoyage->setText(date);
    ui->ModifierDestination->setText(destination);
    ui->ModifierPrixBillet->setText(res);
    qDebug()<<"Hello";
}


