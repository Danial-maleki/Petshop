#include "user.h"
User::User(QObject *parent, const QString &u, const QString &p)
    : UserManagement(parent, u, p)
{
}
void User::login()
{
    QTextStream qin(stdin);
    QString username;
    QString Password;

    qDebug()<<"user login******enter username:";
    qin>>username;
    qDebug()<<"enter password:";
    qin>>password;

    if (username==username&&Password==password) {
        qDebug()<<"user login successful";
        emit loginSuccess();
    }
    else
    {
        qDebug()<<"login failed your username or password is wrong";
        emit loginFailed();
    }
}
