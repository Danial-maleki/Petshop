#include <QCoreApplication>
#include "petshop.h"
#include "cat.h"
#include "dog.h"
#include "chicken.h"
#include "superuser.h"
#include "user.h"
#include <iostream>
#include <QTextStream>
using namespace std;
int main(int argc, char *argv[])
{
    SuperUser su;
    QTextStream qin(stdin);
    QCoreApplication a(argc, argv);
    QString chooice;
    QString name, password,key;
    qDebug()<<"Please first login to app";
    qDebug()<<"Enter username:";
    qin>>name;
    qDebug()<<"Enter password:";
    qin>>password;
    qDebug()<<"";
    qin>>key;
    qDebug()<<"check your password"<<password<<"and username"<<name<<"is it right?(Y/N)";
    // qDebug()<<"do you whant to login as superuser or user?(U/S)";
    // qin>>chooice;
    if(key==key){
    SuperUser su(nullptr, name, password, key);
    su.login();
    }
    else {
        User u(nullptr, name, password);
        u.login();
    }

    PetShop shop;
    SuperUser superuser;
    shop.addAnimal(new Cat());
    shop.addAnimal(new Dog());
    shop.addAnimal(new Chicken());

    shop.loadPurchases("purchases.txt");
    shop.run();
    cin.ignore();
    cin.get();
    return a.exec();
}
