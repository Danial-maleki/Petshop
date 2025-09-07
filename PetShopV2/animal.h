#ifndef ANIMAL_H
#define ANIMAL_H

#include <QString>
#include <QDebug>
class Animal
{
public:
    Animal(const QString &name, int price);
    virtual ~Animal();

    QString getName() const;
    int getPrice() const;

    virtual QString sound() const = 0;

private:
    QString m_name;
    int m_price;
};

#endif // ANIMAL_H
