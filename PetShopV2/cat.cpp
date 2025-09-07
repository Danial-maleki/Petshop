#include "cat.h"
#include <QString>

Cat::Cat()
    : Animal("Cat", 200)      // نام و قیمت
{
}

QString Cat::sound() const
{
    return QString::fromUtf8("میو");
}
