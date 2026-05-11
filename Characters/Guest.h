#ifndef GUEST_H
#define GUEST_H

#include "Character.h"

class Guest : public Character
{
public:
    void speak() override;
};

#endif
