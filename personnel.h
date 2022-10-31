#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class Personnel
{
private:
    int ID;
    QString Nom_Prenom, DateN, Adresse, Tel;
public:
    //CONSTRUCTEURS
    Personnel(){}
    Personnel(int, QString, QString, QString, QString);

    //GETTERS
    QString getNom(){return Nom_Prenom;}
    QString getDate(){return DateN;}
    QString getAdr(){return Adresse;}
    QString getTel(){return Tel;}
    int getID(){return ID;}

    //SETTERS
    void setNom(QString n){Nom_Prenom=n;}
    void setDate(QString d){DateN=d;}
    void setAdr(QString a){Adresse=a;}
    void setTel(QString t){Tel=t;}
    void setID(int i){this->ID=i;}


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier (int ID, QString Nom_Prenom, QString DateN, QString Tel, QString Adresse);
};

#endif // PERSONNEL_H
