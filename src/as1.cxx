#include "as1.hpp"

namespace homework {
//Assingment 1.0 
void swap_ptr(int *a_ptr, int *b_ptr, int *c_ptr)
{
    // we have an initial value A. other adresses are shown using pointers 
    int A = *a_ptr;
    *a_ptr = *b_ptr;
    *b_ptr = *c_ptr;
    *c_ptr = A;
}


//Assingment 1.1
// Create an integer and store the pointer 
UniqueData::UniqueData(int value)
    //identify pointer 
{
    data_ = std::make_unique<int>(value);
}

// return the value stored inside of the data pointer 
int UniqueData::get() const
{
    return *data_;
}

// change the value stored in data_pointer 
void UniqueData::set(int value)
{
    *data_ = value;
}



}; // namespace homework
