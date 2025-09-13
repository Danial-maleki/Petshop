#ifndef PETSHOP_H
#define PETSHOP_H

#include <QList>
#include <QString>

class Animal;

class PetShop
{
public:
    PetShop();
    ~PetShop();

    void addAnimal(Animal* animal);

    void showMenu() const;
    void suggestPurchases(int money) const;
    void buy(int choice, int money, const QString &filename);
    void moods(int money) const;
    void loadPurchases(const QString &filename) const;
    void run();

private:
    QList<Animal*> m_animals;
};

#endif // PETSHOP_H
