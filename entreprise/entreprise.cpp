#include "entreprise.h"

entreprise::entreprise()
{
id_e=0;
nom="";
adresse="";
tel=0 ;
}
entreprise::entreprise(int id_e, QString nom ,QString adresse ,int tel)
{
    this->id_e= id_e ;
    this->nom= nom;
    this->adresse=adresse;
    this->tel= tel ;

};
bool entreprise::ajouter()
{

   QSqlQuery query;
     QString t=QString::number(tel);
    QString id = QString::number(id_e);
    query.prepare("insert into ENTREPRISE (ID_E,NOM,ADRESSE,TEL)"
                  "values(:id_e,:nom,:adresse,:tel)");
       query.bindValue(":id_e",id);
       query.bindValue(":nom",nom);
       query.bindValue(":adresse",adresse);
       query.bindValue(":tel",t);



       return query.exec();



}
bool entreprise::supprimer(int id)
{

    QSqlQuery query;
    QString res =QString::number(id);
    query.prepare("Delete from ENTREPRISE where ID_E = :id_e");
    query.bindValue(":id_e",res);
    return  query.exec();
};
QSqlQueryModel * entreprise::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from ENTREPRISE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_E"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("TEL"));
        return model;
};

bool entreprise::modifier(int id_e, QString nom ,QString adresse, int tel)
{
    QSqlQuery query;
    QString t=QString::number(tel);
    QString res=QString::number(id_e);
            query.prepare("update ENTREPRISE set ID_E=:id_e,NOM=:nom,ADRESSE=:adresse,TEL=:tel WHERE ID_E=:id_e");
            query.bindValue(":id_e",res);
            query.bindValue(":nom",nom);
            query.bindValue(":adresse",adresse);
            query.bindValue(":tel",t);

            return  query.exec();
}
QSqlQueryModel* entreprise::affichervaleur(QString valeur)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString ch="SELECT ";
    QString query=" FROM ENTREPRISE";
    query=ch+valeur+query;
    model->setQuery(query);
    return model;


}
