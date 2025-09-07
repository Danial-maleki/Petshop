#include "animal.h"

Animal::Animal(const QString &name, int price)
    : m_name(name), m_price(price)
{
}

Animal::~Animal()
{
}

QString Animal::getName() const
{
    return m_name;
}

int Animal::getPrice() const
{
    return m_price;
}
