#include "g_hoteles.h"
#include "ui_g_hoteles.h"
#include "hotel.h"
#include <QPixmap>
#include <QMessageBox>

G_Hoteles::G_Hoteles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::G_Hoteles)
{
    ui->setupUi(this);
    ui->tab_hotel->setModel(H.afficher());
}

G_Hoteles::~G_Hoteles()
{
    delete ui;
}



void G_Hoteles::on_pb_ajouter_clicked()
{
    QString nom=ui->le_nom->text();
    QString adresse=ui->l_adresse->text();
    int tel=ui->le_tel->text().toInt();
    int prix=ui->le_prix->text().toInt();
    Hotel H(nom,adresse,tel,prix);
    bool test=H.ajouter();
    QMessageBox msgBox;
    if(test)
        msgBox.setText("Ajout avec succes.");
    else
        msgBox.setText("Echec d'ajout.");
        msgBox.exec();
}

void G_Hoteles::on_pb_supprimer_clicked()
{
   Hotel H1; H1.settel(ui->le_hotel_supp->text().toInt());
   bool test=H1.supprimer(H1.gettel());
   QMessageBox msgBox;
   if(test)
       msgBox.setText("Suppression avec succes.");
   else
       msgBox.setText("Echec de suppression.");
       msgBox.exec();
}



void G_Hoteles::on_pb_modifier_clicked()
{
    Hotel H;
    QString Nom=ui->modif_nom->text();
    QString adr=ui->modif_adresse->text();
    int tel=ui->modif_tel->text().toInt();
    int prix=ui->modif_prix->text().toInt();
    bool test=H.update(Nom,adr,prix,tel);
    QMessageBox msgBox;
    if(test)
        msgBox.setText("Ajout avec succes.");
    else
        msgBox.setText("Echec d'ajout.");
        msgBox.exec();

}
