#ifndef SUPERUSER_H
#define SUPERUSER_H

#include <QString>
#include <QDebug>
#include <QObject>
#include <QFile>
#include <QHash>
#include <QCoreApplication>
#include <QTextStream>
class SuperUser : public QObject
{
    Q_OBJECT
public:
    explicit SuperUser(QObject *parent = nullptr);
    void superuser(const QString &filename);
signals:
};

#endif // SUPERUSER_H
