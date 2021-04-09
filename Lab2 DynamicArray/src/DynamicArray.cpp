#include "DynamicArray.h"

DynamicArray::DynamicArray(int s)
{
    data = new DateType[s];
}

void DynamicArray::insertItem(int index, DateType item)
{
    data[index] = item;
}

DateType DynamicArray::getItem(int index)
{
    return data[index];
}

DynamicArray::~DynamicArray()
{
    delete[] data;
}
