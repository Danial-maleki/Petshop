#include "cat.h"
#include <QString>

Cat::Cat()
    : Animal("Cat", 200)    
{
}

QString Cat::sound() const
{
    return QString::fromUtf8("mewo");
}
