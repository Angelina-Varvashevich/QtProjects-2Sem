#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H


class DynamicArray
{
public:
    DynamicArray();
    ~DynamicArray();
    void push_back(int value);
private:
    int *array;
    int size=1;
};

#endif // DYNAMICARRAY_H
