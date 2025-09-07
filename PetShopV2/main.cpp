#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>

#include "cat.h"
#include "dog.h"
#include "chicken.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QList<Animal*> animals;
    animals.append(new Cat());
    animals.append(new Dog());
    animals.append(new Chicken());


    QFile file("purchases.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        qInfo()<<"Previous purchases:";
        qInfo().noquote() << in.readAll();
        file.close();
    }


    qInfo()<<"Pet Shop Menu";
    for (int i=0;i<animals.size();++i)
    {
        qInfo()<<(i+1)<<animals[i]->getName()<< "Price:"<<animals[i]->getPrice();
    }


    int money;
    qInfo()<<"Enter your money:";
    cin>>money;


    qInfo()<<"With"<<money<<"you can buy:";
    for (int i=0;i<animals.size();++i)
    {
        if (money>=animals[i]->getPrice())
        {
            qInfo()<<(i+1)<<animals[i]->getName()<<"Price:"<<animals[i]->getPrice();
        }
    }


    int choice;
    qInfo()<<"Enter the number of the animal you want to buy:";
    cin>>choice;


    if(choice>0&&choice<=animals.size()) {
        Animal* selected = animals[choice-1];
        if (money >= selected->getPrice()) {
            qInfo()<<"You bought:"<<selected->getName()<<"Price:"<<selected->getPrice()<<"Sound:"<<selected->sound();


            if (file.open(QIODevice::Append | QIODevice::Text)) {
                QTextStream out(&file);
                qInfo()<<"Animal: "<<selected->getName()<<"price:"<<selected->getPrice()<<"Money you had: "<<money;
                file.close();
                qInfo()<<"Saved to purchases.txt";
            }
            else
            {
                qWarning()<<"Could not open file!";
            }
        }
        else
        {
            qInfo()<<"You don't have enough money for this animal!";
        }
    }
    else

    {
        qInfo()<<"Invalid choice!";
    }


    qDeleteAll(animals);

    return 0;
}
