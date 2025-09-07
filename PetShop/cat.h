#ifndef CAT_H
#define CAT_H

#include "animal.h"

class Cat : public Animal {
public:
    Cat();
    QString sound() const override;
};

#endif // CAT_H
