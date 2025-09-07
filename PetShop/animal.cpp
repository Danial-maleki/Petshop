#include "animal.h"

Animal::Animal(const QString &name, int price)
    : name(name), price(price) {}

Animal::~Animal() {}

QString Animal::getName() const {
    return name;
}

int Animal::getPrice() const {
    return price;
}
