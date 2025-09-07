#ifndef PETSHOP_H
#define PETSHOP_H

#include <QList>
#include <QDebug>
#include "animal.h"

class PetShop {
private:
    QList<Animal*> animals;

public:
    PetShop();
    ~PetShop();

    void showMenu() const;
    void suggestPurchases(int money) const;
    void buy(int choice) const;

    QList<Animal*> getAnimals() const { return animals; }
    void addAnimal(Animal* animal) { animals.append(animal); }
};

#endif // PETSHOP_H
