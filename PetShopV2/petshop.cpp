#include "petshop.h"
#include "animal.h"

#include <QTextStream>
#include <QList>

PetShop::PetShop()
{
}

PetShop::~PetShop()
{
    qDeleteAll(m_animals);
    m_animals.clear();
}

void PetShop::addAnimal(Animal* animal)
{
    m_animals.append(animal);
}

void PetShop::showMenu() const
{

    qInfo()<<"Pet Shop";
    for (int i = 0; i < m_animals.size(); ++i) {
        qInfo()<<(i+1)<<m_animals.at(i)->getName()<<"Price: "<<m_animals.at(i)->getPrice();
    }

}

void PetShop::suggestPurchases(int money) const
{

    qInfo()<<"with" <<money<<"$ You can buy";
    bool any = false;
    for (auto animal:m_animals){
        if (animal->getPrice()<=money) {
            qInfo()<<animal->getName()<<animal->getPrice();
            any=true;
        }
    }
    if (!any)
        qInfo()<<"Nothing";

}

void PetShop::buy(int choice) const
{
    QTextStream out(stdout);
    if (choice<1||choice>m_animals.size()) {
        qInfo()<<"Invalid choice";
        return;
    }
    Animal* selected = m_animals.at(choice - 1);
    out.flush();
}
