#ifndef ANIMAL_H
#define ANIMAL_H

#include <QString>

class Animal {
protected:
    QString name;
    int price;

public:
    Animal(const QString &name, int price);
    virtual ~Animal();

    QString getName() const;
    int getPrice() const;

    virtual QString sound() const = 0; // pure virtual
};

#endif // ANIMAL_H
