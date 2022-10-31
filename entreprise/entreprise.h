#ifndef ENTREPRISE_H
#define ENTREPRISE_H

#include<QString>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlQueryModel>
#include <QSqlQueryModel>

class entreprise
{

    int id_e,tel;
    QString nom,adresse;

public:
    entreprise();
    entreprise(int,QString,QString,int);
     int getide(){return id_e;}
     int gettel(){return tel;}
     QString getnom(){return nom;}
     QString getadresse(){return adresse;}
     void setide(int id){this->id_e= id;}
     void settel(int t){this->tel=t;}
     void setnom(QString n){this->nom= n;}
     void setadresse(QString ad){this->adresse=ad;}
        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int id_e);
        bool modifier(int id_e, QString nom ,QString adresse, int tel);
        QSqlQueryModel * affichervaleur(QString);
        private:
};

#endif // ENTREPRISE_H
