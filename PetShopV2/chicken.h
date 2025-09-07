#ifndef CHICKEN_H
#define CHICKEN_H

#include "animal.h"

class Chicken : public Animal
{
public:
    Chicken();
    QString sound() const override;
};

#endif // CHICKEN_H
