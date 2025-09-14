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
    QString username;
    QString password;
    QString key;

    qDebug()<<"superuser login enter username:";
    qin>>username;
    qDebug()<<"Enter password:";
    qin>>password;
    qDebug()<<"enter secret key:";
    qin>>key;

    if(username==username&&password==password&&key==key) {
        qDebug()<<"superUser login successful";
        adminoptios();
        emit loginSuccess();
    }
    else
    {
        qDebug()<<"Login failed!";
        emit loginFailed();
    }
}

void SuperUser::adminoptios()
{
    qDebug()<<"superUser"<<username<<"you have special access";
}


