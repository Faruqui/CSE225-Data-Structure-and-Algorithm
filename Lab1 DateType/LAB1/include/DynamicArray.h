#ifndef DYNAMICARRAY_H_INCLUDED
#define DYNAMICARRAY_H_INCLUDED


class DynamicArray
{
    public:
        DynamicArray(int);
        ~DynamicArray();
        void insertItem(int, int);
        int getItem(int);
    protected:

    private:
        int* data;
};

#endif // DYNAMICARRAY_H_INCLUDED
