#include <iostream>
#include "DateType.h"
#include "DynamicArray.h"

using namespace std;

int main()
{
    DateType d1, d2,d3,d4,d5;

    d1.Initialize(31,12,1999);
    d2.Initialize(30,12,1929);
    d3.Initialize(29,12,1929);
    d4.Initialize(1,1,2001);
    d5.Initialize(25,3,1931);

    DynamicArray da(5);

    da.insertItem(0, d1);
    da.insertItem(1,d1);
    da.insertItem(2,d3);
    da.insertItem(3,d4);
    da.insertItem(4,d5);

    DateType temp;

    for(int i=0; i<5; i++)
    {
        temp = da.getItem(i);
        temp.Print();
        cout<<endl;
    }

    //smallest date
    DateType small;
    small = d1;

    for(int i = 0; i< 5 ; i++)
    {
        if(small.compareTo(da.getItem(i))== 2)
        {
            small = da.getItem(i);
        }
    }

    cout<<"\nEarliest Date - ";
    small.Print();
    return 0;
}
