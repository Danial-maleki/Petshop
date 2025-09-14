#include "superuser.h"
using namespace std;
SuperUser::SuperUser(QObject *parent)
    : QObject{parent}
{}

void SuperUser::superuser(const QString &filename)
{

    QTextStream qin(stdin);
    QTextStream qout(stdout);
    QString name, superPassword, answer, answer2, animalname;
    int animalprice;

        qInfo()<<"Enter your name: ";
        qin>>name;
////////////////////////////////////////////////////////////////////////////////////////
        qInfo()<<"Enter your password: ";
        qin>>superPassword;
////////////////////////////////////////////////////////////////////////////////////////
        qInfo()<<"your name:"<<name<<"this is your password:"<<superPassword<< "is it correct (yes/no)?";
        qin>>answer;
////////////////////////////////////////////////////////////////////////////////////////
        if (answer=="yes") {
            qInfo()<<"welcome superuser:"<<name;
////////////////////////////////////////////////////////////////////////////////////////

                qInfo()<<name<<"your options:\n(1)create animal\n";
                qin>>answer2;

                if (answer2=="1") {
                    qInfo()<<"Set your animal name:";
                    qin>>animalname;

                    qInfo()<<"Enter your animal price:";
                    qin>>animalprice;

                    qInfo()<<"Animal created:"<<animalname<<"with price:"<<animalprice;
                }
                else
                {
                    qInfo()<<"Invalid option";
                }

        }
        else if(answer=="no")
        {
            qInfo()<<"your password or username is wrong try again";
        }
        else
        {
            qInfo()<<"invalid answer please type yes or no";
            // uint basd = qHash(superPassword);

        }
        ///note:  add a file to sava all of this on that file
        // QFile file(filename);
        // if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        //     qWarning()<<"Failed to open file for writing: "<<filename<<"error: " << file.errorString();
        //     return;
        // }

        // QTextStream out(&file);

        // out<<"Name: "<<name<<"\n";
        // out<<"Password: "<<superPassword<<"\n";
        // out<<"Animalname: "<<animalname<<"\n";
        // out<<"AnimalPrice: "<<animalprice<<"\n";

        // out.flush();
        // file.close();

        // qInfo()<<"Saved to"<<filename;
    ////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////
}


