#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList animals = {"Cat", "Dog", "Chicken"};
    QList<int> prices = {200, 300, 400};


    QFile file("purchases.txt");
    if (file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream in(&file);
        qInfo()<<"Previous purchases:";
        qInfo()<<in.readAll();
        file.close();
    }


    qInfo()<<"Pet Shop Menu:";
    for (int i=0;i<animals.size();++i) {
        qInfo()<<(i + 1)<<animals[i]<<"price:"<<prices[i];
    }


    int money;
    qInfo() << "Enter your money:";
    cin >> money;

    qInfo()<<"with"<<money<<"you can buy:";
    for (int i =0;i<animals.size();++i)
    {
        if (money >= prices[i]) {
            qInfo()<<(i+1)<<animals[i]<<"price:"<<prices[i];
        }
    }


    int choice;
    qInfo()<<"enter the number of the animal you want to buy:";
    cin>>choice;

    if (choice>0&&choice<=animals.size()) {
        QString animal = animals[choice-1];
        int price=prices[choice-1];

        if (money>=price) {
            qInfo()<<"you bought:"<<animal<<"price:"<<price;

            if (file.open(QIODevice::Append|QIODevice::Text))
            {
                QTextStream out(&file);
                qInfo()<<"Animal: "<<animal<<"price: "<<price<<"money you had: "<<money;
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

    return 0;
}
