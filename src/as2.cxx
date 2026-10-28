#include "as2.hpp"

namespace homework {


// Print the knight's attack does not return anthing but text 
void Knight::attack() const
{
    std::cout << name << " wields a mighty " << weapon << std::endl;
}

// create a copy of knight
// return the same thing twice using the knight as daughter of the entity class and this* meaning not the pointer but contents of pointer 
std::unique_ptr<Entity> Knight::clone() const
{
    return std::make_unique<Knight>(*this);
}

// set the weapon
// use the void and function of setweapon and defines variable weapon as weapon
// this->weapon variable belonging to the current Knight object and copies value into the member variabl

void Knight::setWeapon(std::string weapon)
{
    this->weapon = weapon;
}




//now for the sorcerer 
// Print the sorcerers attack does not return anthing but text 
void Sorcerer::attack() const
{
    std::cout << name << " uses his mystical " << spell << std::endl;
}

// create a copy of sorcerer
// return the same thing twice using the knight as daughter of the entity class and this* meaning not the pointer but contents of pointer 
std::unique_ptr<Entity> Sorcerer::clone() const
{
    return std::make_unique<Sorcerer>(*this);
}

// set the weapon
// use the void and function of setweapon and defines variable weapon as weapon
// this->weapon variable belonging to the current sorcerer object and copies value into the member variabl

void Sorcerer::setAbility(std::string spell)
{
    this->spell = spell;
}


} // namespace homework

