#include "dynamicarray.h"

DynamicArray::DynamicArray()
{
    array = new int [size];
    for (int i=0; i<size; ++i){
        array[i]=0;
    }

}

DynamicArray::~DynamicArray()
{
    delete [] array;
}

void DynamicArray::push_back(int value)
{
    size+=1;
    int *new_array= new int [size];
    for  (int i =0; i<size; ++i){
        new_array[i]=array[i];
    }
    new_array[size-1]=value;
    delete []array;
    array= new int[size];
    array=new_array;
    delete[] new_array;
        }
