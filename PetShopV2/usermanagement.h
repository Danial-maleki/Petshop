#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include <QObject>
#include <QString>
#include <QDebug>
#include <QTextStream>

class UserManagement : public QObject
{
    Q_OBJECT
protected:
    QString username;
    QString password;
public:
    explicit UserManagement(QObject *parent = nullptr, const QString& u = "", const QString& p = "");
    virtual void login();
signals:
    void loginSuccess();
    void loginFailed();
};

#endif // USERMANAGEMENT_H
