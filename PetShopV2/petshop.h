#ifndef PETSHOP_H
#define PETSHOP_H

#include <QList>

class Animal;

class PetShop
{
public:
    PetShop();
    ~PetShop();

    void addAnimal(Animal* animal);
    void showMenu() const;
    void suggestPurchases(int money) const;
    void buy(int choice) const; // choice: شماره از 1 تا n

private:
    QList<Animal*> m_animals;
};

#endif // PETSHOP_H
