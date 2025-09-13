#include <QCoreApplication>
#include "petshop.h"
#include "cat.h"
#include "dog.h"
#include "chicken.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PetShop shop;
    shop.addAnimal(new Cat());
    shop.addAnimal(new Dog());
    shop.addAnimal(new Chicken());
    shop.loadPurchases("purchases.txt");
    shop.run();

    return a.exec();
}
