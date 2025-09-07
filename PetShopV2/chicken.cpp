#include "chicken.h"
#include <QString>

Chicken::Chicken()
    : Animal("Chicken", 400)
{
}

QString Chicken::sound() const
{
    return QString::fromUtf8("قدقد");
}
