#ifndef SUPERUSER_H
#define SUPERUSER_H

#include <QString>
#include <QDebug>
#include <QObject>
#include <QFile>
#include <QHash>
#include <QCoreApplication>
#include <QTextStream>
#include "user.h"
class SuperUser : public User
{
    Q_OBJECT
    QString key;
public:

    explicit SuperUser(QObject *parent = nullptr);
    SuperUser(QObject *parent, const QString &u, const QString &p, const QString &key);
    void login() override;
    void adminoptios();
signals:
};

#endif // SUPERUSER_H
