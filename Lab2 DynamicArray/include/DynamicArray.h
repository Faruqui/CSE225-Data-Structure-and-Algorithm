#ifndef DYNAMICARRAY_H_INCLUDED
#define DYNAMICARRAY_H_INCLUDED
#include "DateType.h"

class DynamicArray
{
    public:
        DynamicArray(int);
        ~DynamicArray();
        void insertItem(int, DateType);
        DateType getItem(int);
    protected:

    private:
        DateType* data;
};

#endif // DYNAMICARRAY_H_INCLUDED
