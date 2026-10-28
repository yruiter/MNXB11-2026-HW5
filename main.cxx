/** Use this main to test exercises. See the example with 'as1.0' below. 
 *  You can add all the exercise tests inside the same main.
 *  Don't forget to add includes properly.
 * */

#include "as1.hpp"
#include "as2.hpp"
#include <iostream>

using namespace homework;

// Assingment 1.0 
int main() { 
{
    // pick initial values 
    int a = 3;
    int b = 8;
    int c = 102;

    //use pointers and gets the adresses of a b and c 
    swap_ptr(&a, &b, &c);

    //show output 
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;

    std::cout << "1.0 is done!" << std::endl;
}
  

//Assingment 1.1
{
    // Create an object storing 2 
    homework::UniqueData number(2);

    // Print the initial value
    std::cout << number.get() << std::endl;

    // Change the initial value to 27
    number.set(27);

    // Print the updated value
    std::cout << number.get() << std::endl;

    std::cout << "1.1 is done!" << std::endl;

}


//Assingment 2.1 

    //of namespace use class knight and define knight name 
    homework::Knight knight("Legolas");

    //of funtions in void knight define weapon and attack
    knight.setWeapon("knife");
    knight.attack();

    // use std::make_unique in clone() which is smart pointer and be able to make a new copy of the knight 
    // and we want to call the attack using a pointer 
    std::unique_ptr <Entity> copyKnight = knight.clone();
    copyKnight->attack();

    std::cout << "2.1 is done!" << std::endl;




// Assignment 2.2

    //of namespace use class sorcerer and define name of socerer 
    homework::Sorcerer sorcerer("Saruman");

    //of funtions in void knight define weapon and attack
    sorcerer.setAbility("Telekinesis");
    sorcerer.attack();

    // use std::make_unique in clone() which is smart pointer and be able to make a new copy of the sorcerer 
    // and we want to call the attack using a pointer 
    std::unique_ptr <Entity> copySorcerer = sorcerer.clone();
    copySorcerer->attack();

    std::cout << "2.2 is done!" << std::endl;


//Optional assignment 2.3

     Duel<Knight, Sorcerer> duel(&knight, &sorcerer);
    std::unique_ptr<Entity> winner = duel.fight();

}


