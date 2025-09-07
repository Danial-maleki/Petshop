#include "dog.h"

Dog::Dog() : Animal("Dog", 300) {}

QString Dog::sound() const {
    return "bark";
}
