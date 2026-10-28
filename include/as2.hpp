#pragma once

#include <string>
#include <iostream>
#include <random>
#include <memory>

namespace homework {

  // Random number generator setup
  inline std::random_device rd;
  inline std::mt19937 gen(rd()); 
  inline std::uniform_real_distribution<double> dist(0.0, 1.0);
  // to generate a random number between 0 and 1, use auto random_number = dist(gen);

  // Base class for entities
  // Has a implemented method getName()
  // Has a pure virtual method attack()
  // Has a pure virtual method clone() to support polymorphic copying
  // TO DO: Nothing, everything is implemented for you
  struct Entity {
      explicit Entity(const std::string name) : name{std::move(name)} {}
      virtual ~Entity() = default;
      virtual void attack() const = 0;
      std::string getName() const {
        return name;
      }

      virtual std::unique_ptr<Entity> clone() const = 0;
    protected:
      std::string name;
  };
  
  ///////// EXERCISES BEGIN BELOW /////////




  // as 2.1
  // Derived class Knight
  // TO DO: implement attack() and clone() and setWeapon()
  // Should have a private member variable for weapon (std::string)
  // Note: use std::make_unique in clone() and the \it{this} pointer to copy the object. E.g. std::make_unique<Type>(*this);
  // The attack should use std::cout to print something like "<name> swings a <weapon>\n"
  // The setWeapon() method should set the weapon variable (the private member variable) 

class Knight : public Entity {
public:
    //call from the parent class 
    Knight(std::string name) : Entity(name) {}

    //yet undefined function which doenst change the variable but overrides the virtual function 
    void attack() const override;

    //returns an object of entity, copies this, doenst change it and overrides the virtual function 
    std::unique_ptr<Entity> clone() const override;

    //yet undefined function  
    void setWeapon(std::string weapon);

private:
    std::string weapon;

};


  // Assingment 2.2
  // Derived class Sorcerer
  // TO DO: implement attack() and clone() and setAbility()
  // Same as the Knight class

class Sorcerer : public Entity {
public:
    //call from the parent class 
    Sorcerer(std::string name) : Entity(name) {}

    //yet undefined function which doenst change the variable but overrides the virtual function 
    void attack() const override;

    //returns an object of entity, copies this, doenst change it and overrides the virtual function 
    std::unique_ptr<Entity> clone() const override;

    //yet undefined function  
    void setAbility(std::string spell);

private:
    std::string spell;


}; 

  /////////

  // NOT MANDATORY (Stretch goal): as 2.3. You can pass assignment without doing this one. 
  // If you want to see how templates work, you can implement this one.
  // Duel class template
  // TO DO: create a struct/class called Duel that is templated by two types (T1 and T2)
  // The constructor should take two pointers (T1* and T2*)
  // The fight() method should:
  // - call attack() on both entities
  // - randomly select one of the two entities as the winner (use the random number generator above)
  // - print to std::cout "<name> wins the duel!\n"
  // - return a std::unique_ptr<Entity> to the winner (use clone() to copy the object)


//set up the template 
template <typename T1, typename T2>

//create a struct (different data types) under a single name using poiners to dereference 
struct Duel {
    T1* knight;
    T2* sorcerer;

    //set up duel using the pointers to set up order of attack 
    Duel(T1* first, T2* second)
        : knight(first), sorcerer(second) {}

    // now we want to set up the dual, using a pointer and setting up the fight command 
    std::unique_ptr<Entity> fight() const
    
    //now we want to call attack on the both of them 
    // the random number generator is used to determine the winner of the duel 
    // if dis(gen), generated above, is lower than 0.5 the if statement is implemented if not, else is implemented 
    // fight requires a pointer as return and a cloned winner to fight 
    {
        knight->attack();
        sorcerer->attack();

        if (dist(gen) < 0.5) {
            std::cout << knight->getName() << " doges the attack and manages to cut the staff of " << sorcerer->getName() << ". "
            << sorcerer->getName() << " is beyond baffeled by this, and disapears into the cold dark night. "<< knight->getName() 
            << " is left standing above the edge where he thought he was for sure going to die."<< std::endl;
            return knight->clone();
        } 
        else {
            std::cout <<  sorcerer->getName() << " is almost supprised he managed to hit the agile " << knight->getName() 
            << ". "<< knight->getName() << " is thrown to the air and slips over the edge. The threw a last look of disgust at his opponent. Right before he fell in what looked like never ending darkness. "
            <<  sorcerer->getName() << " Is left standing above the edge, processing the battle, after which he yelled to his first in command: Prepare the troops, we move out first thing in the morning."
            << std::endl;
                    
            return sorcerer->clone();
        }
    }
};



} // namespace homework

