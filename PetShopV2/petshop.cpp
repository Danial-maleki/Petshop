#include "petshop.h"
#include "animal.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>
#include <QTime>
#include <QDateTime>
using namespace std;

PetShop::PetShop() {}

PetShop::~PetShop() {
    qDeleteAll(m_animals);
}
/////////////////////////////////////////////////////////////////////////////////////////////
void PetShop::addAnimal(Animal* animal) {
    m_animals.append(animal);
}


/////////////////////////////////////////////////////////////////////////////////////////////
void PetShop::showMenu() const {
    qInfo()<<"Available Animals:";
    for (int i =0;i<m_animals.size();++i) {
        qInfo()<<i+1<<m_animals[i]->getName()<<"price:"<<m_animals[i]->getPrice();
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////
void PetShop::moods(int money) const {
//c = cat
//d = dog
// k=chicken
    int priceCat =200;
    int priceDot = 300;
    int priceChicken = 400;
    for (int c=0;c<=money/priceCat;c++) {
        for (int d=0; d<=money/priceDot;d++) {
            for (int k=0;k<=money/priceChicken;k++) {
                int total=c*priceCat+d*priceDot+k*priceChicken;
                if(total<=money){
                    qInfo()<<c<<"cat"<<d<<"dog"<<k<<"chicken"<<"total:"<<total;
                }
            }
        }
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////
void PetShop::suggestPurchases(int money) const {
    for (auto animal : m_animals) {
        if (animal->getPrice()<=money) {
            qInfo()<<"-"<<animal->getName();
        }
    }

}
/////////////////////////////////////////////////////////////////////////////////////////////
void PetShop::buy(int choice, int money, const QString &filename) {
    if (choice>0&&choice<=m_animals.size()) {
        Animal* selected = m_animals[choice - 1];
        if (money >= selected->getPrice()) {
            qInfo()<< "You bought:" << selected->getName()<< "Price:" << selected->getPrice()<<"Sound:"<<selected->sound();

            QFile file(filename);
            if (file.open(QIODevice::Append | QIODevice::Text)) {
                QTextStream out(&file);
                qInfo()<<"Animal: "<<selected->getName()<<"price:"<<selected->getPrice()<<" Money you had: "<<money;
                file.close();
                qInfo() << "Saved to" << filename;
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
    } else {
        qInfo()<<"Invalid choice!";
    }
}

void PetShop::loadPurchases(const QString &filename) const {
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly|QIODevice::Text)) {
        QTextStream in(&file);
        qInfo()<<"Previous purchases:";
        qInfo().noquote()<<in.readAll();
        file.close();
    }
}

void PetShop::run() {
    int money, choice;
    string name,password;
    QString data;
    qInfo()<<"Enter your money:";
    cin>>money;
    qInfo()<<"Enter your name: ";
    cin>>name;
    qInfo()<<"Enter your password: ";
    cin>>password;
    /////////////////////////////////////
    for(int i=0;i<1000;i++){
        data.append(password);
    }

    createuser();
    showMenu();
    moods(money);
    suggestPurchases(money);
    qInfo()<<"Enter the number of the animal you want to buy:";
    cin>>choice;
    // ///////////////////////////////
    buy(choice, money, "purchases.txt");
}

