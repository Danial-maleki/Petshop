#include <QCoreApplication>
#include "petshop.h"
#include "cat.h"
#include "dog.h"
#include "chicken.h"
#include "superuser.h"
#include "user.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PetShop shop;
    SuperUser superuser;
    shop.addAnimal(new Cat());
    shop.addAnimal(new Dog());
    shop.addAnimal(new Chicken());
    superuser.superuser("Superuser.txt");
    shop.loadPurchases("purchases.txt");
    shop.run();
    cin.ignore();
    cin.get();
    return a.exec();
}
