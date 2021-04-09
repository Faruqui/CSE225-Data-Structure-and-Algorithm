#include "DynamicArray.h"

DynamicArray::DynamicArray(int s)
{
    data = new int[s];
}

void DynamicArray::insertItem(int index, int item)
{
    data[index] = item;
}

int DynamicArray::getItem(int index)
{
    return data[index];
}

DynamicArray::~DynamicArray()
{
    delete[] data;
}
