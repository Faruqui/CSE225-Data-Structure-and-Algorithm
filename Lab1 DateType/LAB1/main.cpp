#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main()
{
    cout << "Enter the size of the array: " << endl;
    int size;
    cin>>size;

    DynamicArray d(size);

    int temp;
    for (int i = 0; i<size; i++){
        cout<< "Enter value to be inserted at index = "<<i<<endl;
        cin>>temp;
        d.insertItem(i, temp);
    }

    cout<< "The values stored are: \n";
    int tmp2;

    for(int i = 0; i < size; i++){
        tmp2 = d.getItem(i);
        cout<<"\nIndex = "<<i; cout<<",Value = "<<tmp2<<endl;
    }
}
