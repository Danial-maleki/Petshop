#include "chicken.h"

Chicken::Chicken() : Animal("Chicken", 400) {}

QString Chicken::sound() const {
    return "Chicken sound |:";
}
