#include "hotel.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
Hotel::Hotel()
{
 nom=" "; adresse=" "; tel=0;prix=0;
}


Hotel::Hotel(QString nom,QString adresse,int tel,int prix)
{
    this->nom=nom; this->adresse=adresse;this->tel=tel;this->prix=prix;
}
QString Hotel:: getnom()
{return nom;}
QString Hotel::getadresse()
{return adresse;}
int Hotel::gettel()
{return tel;}
int Hotel::getprix()
{return prix;}
void Hotel::setnom(QString nom)
{
    this->nom=nom;
}
void Hotel::setadresse(QString adresse)
{
    this->adresse=adresse;
}
void Hotel::settel(int tel)
{
    this->tel=tel;
}
void Hotel::setprix(int prix)
{
    this->prix=prix;
}
bool Hotel::ajouter()
{
    QSqlQuery query;
    QString tel_string=QString::number(tel);
    QString prix_string=QString::number(prix);
          query.prepare("INSERT INTO Hotels VALUES (:nom, :adresse, :tel, :prix)");
          query.bindValue(":nom", nom);
          query.bindValue(":adresse", adresse);
          query.bindValue(":tel", tel_string);
          query.bindValue(":prix", prix_string);

    return query.exec();
}
bool Hotel::supprimer(int tel)
{
     QSqlQuery query;
     query.prepare(" Delete from hotels where tel=:tel");
     query.bindValue(":tel", tel);

     return query.exec();
}

bool Hotel::update(QString Nom,QString adr,int prix,int tel)
{
    QString tel_string=QString::number(tel);
    QString prix_string=QString::number(prix);
    QSqlQuery query;
    query.prepare("UPDATE Hotels SET (nom)=:nom, (adresse)=:adresse, (prix)=:prix where (tel)=:tel)");
    query.bindValue(":nom", Nom);
    query.bindValue(":adresse", adr);
    query.bindValue(":tel", tel_string);
    query.bindValue(":prix", prix_string);
    return query.exec();
}

QSqlQueryModel* Hotel::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM Hotels");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Tel"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));

    return model;
}

