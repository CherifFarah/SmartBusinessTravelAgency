#include "entreprise.h"
#include <iostream>
using namespace std;
#include <QDebug>
#include <QSqlRecord>
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
    QSqlQueryModel * modelCountVoyage=new QSqlQueryModel();

    QSqlQuery query;
    model->setQuery("select * from ENTREPRISE");
    for (int i = 0; i < model->rowCount(); i++) {
            int id = model->record(i).value(id_e).toInt();
            QString idEntreprise = QString::number(id);
            modelCountVoyage->setQuery("select * from VOYAGE where cin='" + idEntreprise + "' ");
            int countVoyage = modelCountVoyage->rowCount();
            if ( countVoyage >= 5 && countVoyage < 10){
                int promo1 = 5;
                int fidel1 = 1;
                query.prepare("update ENTREPRISE set FIDELISATION=:fidel,PROMOTION=:promo WHERE ID_E=:id_e");
                query.bindValue(":fidel",fidel1);
                query.bindValue(":promo",promo1);
                query.bindValue(":id_e",idEntreprise);
                query.exec();

            } else if ( countVoyage >= 10 && countVoyage < 20 ){
                int promo2 = 7;
                int fidel2 = 2;
                query.prepare("update ENTREPRISE set FIDELISATION=:fidel,PROMOTION=:promo WHERE ID_E=:id_e");
                query.bindValue(":fidel",fidel2);
                query.bindValue(":promo",promo2);
                query.bindValue(":id_e",idEntreprise);
                query.exec();

            }else if ( countVoyage >= 20){
                int promo3 = 10;
                int fidel3 = 3;
                query.prepare("update ENTREPRISE set FIDELISATION=:fidel,PROMOTION=:promo WHERE ID_E=:id_e");
                query.bindValue(":fidel",promo3);
                query.bindValue(":promo",fidel3);
                query.bindValue(":id_e",idEntreprise);

                query.exec();
            }

        }

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

QSqlQuery* entreprise::getIdEntreprise(){

    QSqlQuery* query = new QSqlQuery();
    query->prepare("select * from ENTREPRISE");
    return query;

}


QSqlQuery* entreprise::getVoyagesEntreprise(int idEntreprise){

    QSqlQuery* query = new QSqlQuery();
    query->prepare("select IDVOY,PRIXBILLET from VOYAGE WHERE CIN=:id_e");
    query->bindValue(":id_e",idEntreprise);
    query->exec();
    return query;

}

QSqlQuery* entreprise::getPromotionEntreprise(int idEntreprise){

    QSqlQuery* query = new QSqlQuery();
    query->prepare("select PROMOTION from ENTREPRISE WHERE ID_E=:id_e");
    query->bindValue(":id_e",idEntreprise);
    query->exec();
    return query;

}

QSqlQueryModel* entreprise::recherche_avancee(QString arg, int checkButton)
{

    QSqlQueryModel * model=new QSqlQueryModel();

    if ( checkButton == 0 ){
        model->setQuery("select * from ENTREPRISE where NOM like '" "%" + arg + "%" "'  ");
    }else if ( checkButton == 1 ){
        model->setQuery("select * from ENTREPRISE where ADRESSE like '" "%" + arg + "%" "'  ");
    }else if ( checkButton == 2 ){
        model->setQuery("select * from ENTREPRISE where TEL like '" "%" + arg + "%" "'  ");
    }

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_E"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("TEL"));

    return model;
}


QSqlQueryModel* entreprise::tri_avancee(QString arg)
{

    QSqlQueryModel * model=new QSqlQueryModel();

    if ( arg == "nom" ){
        model->setQuery("select * from ENTREPRISE order by NOM ASC ");
    }else if ( arg == "adresse" ){
        model->setQuery("select * from ENTREPRISE order by ADRESSE ASC ");
    }else if ( arg == "telephone" ){
        model->setQuery("select * from ENTREPRISE order by TEL like ASC ");
    }else{
        model->setQuery("select * from ENTREPRISE");
    }

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_E"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("TEL"));

    return model;
}


QSqlQuery* entreprise::statistique(){

    QSqlQuery* query = new QSqlQuery();
    query->prepare("select * from ENTREPRISE");
    query->exec();
    return query;

}



