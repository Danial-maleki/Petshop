#include "usermanagement.h"

UserManagement::UserManagement(QObject *parent, const QString &u, const QString &p)
    : QObject(parent), username(u), password(p)
{
}

void UserManagement::login()
{
    QTextStream qin(stdin);
    QString username;
    QString password;
    qDebug()<<"enter username:";
    qin>>username;
    qDebug()<<"enter password:";
    qin >> password;
    if (password==username&&password==password)
    {
        qDebug()<<"login successful";
        emit loginSuccess();
    }
    else
    {
        qDebug()<<"login failedasd";
        emit loginFailed();
    }
}
