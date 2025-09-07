#include "petshop.h"
#include "cat.h"
#include "dog.h"
#include "chicken.h"

PetShop::PetShop() {
    animals.append(new Cat());
    animals.append(new Dog());
    animals.append(new Chicken());
}

PetShop::~PetShop() {
    qDeleteAll(animals);
}

void PetShop::showMenu() const
{
    qInfo() << "Pet Shop Meng";
    for (int i = 0; i < animals.size(); ++i) {
        qInfo()<<i+1<<":"<<animals[i]->getName()<<"price:"<<animals[i]->getPrice();
    }
}

void PetShop::suggestPurchases(int money) const {
    qInfo()<<"With"<<money<<"you can buy:";
    for (auto a : animals) {
        if (a->getPrice()<=money) {
            qInfo()<<a->getName()<<"price:"<<a->getPrice();
        }
    }
}




void PetShop::buy(int choice) const {
    int index =choice-1;
    if(index >= 0&&index<animals.size()) {
        Animal*selected=animals[index];
        qInfo()<<"You bought:"<<selected->getName()
            <<"for" << selected->getPrice();
        qInfo()<<"Sound:"<<selected->sound();
    }
    else
    {
        qInfo()<<"Invalid choice!";
    }
}

