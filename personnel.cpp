#include "personnel.h"


Personnel::Personnel(int ID, QString Nom_Prenom, QString DateN, QString Tel, QString Adresse)
{
    this->ID=ID;
    this->Nom_Prenom=Nom_Prenom;
    this->DateN=DateN;
    this->Tel=Tel;
    this->Adresse=Adresse;

}

bool Personnel::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(ID);

    query.prepare("insert into personnel (ID, Nom_Prenom, DateN, Tel, Adresse)" "values(:ID, :Nom_Prenom, :DateN, :Tel, :Adresse)");
    query.bindValue(":ID",res);
    query.bindValue(":Nom_Prenom",Nom_Prenom);
    query.bindValue(":DateN",DateN);
    query.bindValue(":Tel",Tel);
    query.bindValue(":Adresse",Adresse);


    return query.exec();
}

bool Personnel::modifier(int ID, QString Nom_Prenom, QString DateN, QString Tel, QString Adresse)
{
    QString ID_res=QString::number(ID);
    QSqlQuery query;
    query.prepare("Update Personnel set ID=:ID, Nom_Prenom =:Nom_Prenom , Adresse=:Adresse , DateN=:DateN ,Tel=:Tel where ID =:ID ");
    query.bindValue(":ID",ID_res);
    query.bindValue(":Nom_Prenom",Nom_Prenom);
    query.bindValue(":DateN",DateN);
    query.bindValue(":Tel",Tel);
    query.bindValue(":Adresse",Adresse);



return    query.exec();
}


bool Personnel::supprimer(int ID)
{
    QSqlQuery query;
    QString res=QString::number(ID);

    query.prepare("delete from personnel where ID=:ID");
    query.bindValue(":ID",res);
    return query.exec();
}

QSqlQueryModel * Personnel::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from personnel");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom_Prenom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATEN"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Tel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Adresse"));

    return model;
}
