#include "voyage.h"
#include <QStandardItem>
#include <QTableWidgetItem>
voyage::voyage()
{

}

voyage::voyage(QString cin,QString destination,QString date,float prix)
{

this->cin=cin;
this->destination=destination;
dateVoyage=date;
prixBillet=prix;
}

bool voyage::ajouterVoyage()
{
QSqlQuery query;
QString res=QString::number(prixBillet);
query.prepare("insert into VOYAGE (cin, destination, datevoyage, PrixBillet) values (:cin, :destination, :date, :prix) ");

query.bindValue(":cin",cin);
query.bindValue(":destination",destination);
query.bindValue(":date",dateVoyage);
query.bindValue(":prix",res);
return query.exec();
}

bool voyage::SupprimerVoyage(QString Cin)
{

QSqlQuery query;
query.prepare("delete from voyage where cin=:cin");
query.bindValue(":cin",Cin);
return query.exec();
}

QSqlQueryModel *voyage::afficherVoyage()
{
QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from voyage");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ClientCin"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Destination"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("DateVoyage"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("PrixBillet"));

return model;
}

bool voyage::modifierVoyage(QString Cin,QString Destination,QString Date,float Prix)
{
QSqlQuery query;
QString res=QString::number(Prix);
query.prepare("update voyages set (destination)=:destination,(dateVoyage)=:date,(prixBillet)=:prix where (cin)=:cin");
query.bindValue(":cin",Cin);
query.bindValue(":destination",Destination);
query.bindValue(":date",Date);
query.bindValue(":prix",res);

return query.exec();
}



