#include "dog.h"
#include <QString>

Dog::Dog()
    : Animal("Dog", 300)
{
}

QString Dog::sound() const
{
    return QString::fromUtf8("bark");
}
