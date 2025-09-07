#ifndef DOG_H
#define DOG_H

#include "animal.h"

class Dog : public Animal {
public:
    Dog();
    QString sound() const override;
};

#endif // DOG_H
