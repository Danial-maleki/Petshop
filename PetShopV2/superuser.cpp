#include "superuser.h"
#include <QTextStream>
#include <QDebug>


SuperUser::SuperUser(QObject *parent)
    : User(parent)
{

}


SuperUser::SuperUser(QObject *parent, const QString &u, const QString &p, const QString &k): User(parent), key(k)
{

}


void SuperUser::login() {
    QTextStream qin(stdin);
    QString username="danial";
    QString password;
    QString key="nigga";
    QString Newkey;
    QString ADMIN_KEY ="petshop2025";
    qDebug()<<"superuser login enter username:";
    qin>>username;
    qDebug()<<"enter secret key:";
    qin>>Newkey;

    if(username==username&&ADMIN_KEY==ADMIN_KEY&&Newkey==key)
    {
        qDebug()<<"superUser login successful";
        adminoptios();
        emit loginSuccess();
    }
    else
    {
        qDebug()<<"login failed";
        emit loginFailed();
    }
}

void SuperUser::adminoptios() {
    QTextStream qin(stdin);
    int choice, items;
    while (true) {
        qDebug()<<"superUser"<<username<<"you have special access";
        qDebug()<<"you can now add or remove animals";
        qDebug()<<"(1)add animals";
        qDebug()<<"(2)soon";
        qDebug()<<"(0)exit";
        qin>>choice;
        if (choice==1) {
            qDebug()<<"add your items: ";
            qin>>items;
            qDebug()<<"you added->>"<<items;
        }
        else if(choice==2)
        {
            qDebug()<<"this item does not exist try again";
            continue;
        }
        else if(choice==0)
        {
            qDebug()<<"exiting admin menu";
            break;
        }
        else
        {
            qDebug()<<"invalid choice try again";
            continue;
        }
    }
}



