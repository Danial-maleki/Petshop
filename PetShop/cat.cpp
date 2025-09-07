#include "cat.h"

Cat::Cat() : Animal("Cat", 200) {}

QString Cat::sound() const {
    return "Meow";
}
