#ifndef ANIMAL_H
#define ANIMAL_H

#include <QString>
#include <QDebug>
#include <QObject>
#include <QFile>
#include <QDir>
#include <QDateTime>
class Animal
{
public:
    Animal(const QString &name, int price);
    // Logger(QObject *parent = nullptr);
    virtual ~Animal();
    virtual QString sound() const = 0;
////////////////////////////////////////////////////
    QString getName() const;
    int getPrice() const;
///////////////////////////////////////
    static bool logging;
    static QString filename;
    static void attach();
    static void handler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
private:
    QString m_name;
    int m_price;
};

#endif // ANIMAL_H
