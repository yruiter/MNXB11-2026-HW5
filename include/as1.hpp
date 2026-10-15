#pragma once
#include <memory>

namespace homework {

  // As 1.1 Swap three raw pointers
  // TO DO: Implement this function in as1.cxx
  // Function takes three int pointers and swaps the values they point to
  // ptr a should get the value of ptr b
  // ptr b should get the value of ptr c
  // ptr c should get the value of ptr a
  void swap_ptr(int *a_ptr, int *b_ptr, int *c_ptr);


  
  // As 1.2 Unique data class (https://en.cppreference.com/w/cpp/memory/unique_ptr.html)
  // TO DO: Implement the methods of this class in as1.cxx
  // That is the constructor, get and set methods
  // constructor takes an int value and stores it in data_ // see make_unique
  // get returns the value stored in the heap
  // set sets the value stored in the heap
  // Hint: can use pointer arithmetics on a unique_ptr


  class UniqueData
  {
    public:
      //constructor stores the given integer 
      UniqueData(int value);
      // returns the stored integer which is not changed 
      int get() const;
      //this updates the integer that is stored 
      void set(int value);


    private:
      // pointer to an integer 
      std::unique_ptr<int> data_;

  };




} // namespace homework
