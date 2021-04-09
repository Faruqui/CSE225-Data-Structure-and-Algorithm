#include "unsortedtype.h"
#include <iostream>

using namespace std;

int main()
{
    UnsortedType u;
    /*
    u.InsertItem(11);
    u.InsertItem(5);
    u.InsertItem(9);
    u.InsertItem(4);
    u.InsertItem(7); */

    for(int i=0; i < MAX_ITEMS; i++)
    {
        int x;
        cout<< "Enter number of mangoes for day "<<i+1<<" : ";
        cin>>x;
        u.InsertItem(x);
    }

    //Problem 1:-
    u.ResetList();
    for(int i = 0; i<MAX_ITEMS; i++)
    {
        int x;
        u.GetNextItem(x);
        cout<< "Day: "<<i+1<<" Mangoes - "<<x<<endl;
    }

    //Problem 2:-
    if(u.SearchItem(8))
    {
        cout<< "\nHe collected 8 mangoes\n";
    }
    else
    {
        cout<< "\nHe did not collect 8 mangoes\n";
    }

    //Problem 3:-
    u.DeleteItem(7);
    int sum=0;
    u.ResetList();
    for(int i = 0; i<MAX_ITEMS-1; i++)
    {
        int n;
        u.GetNextItem(n);
        sum = sum + n;
    }
    cout<< "\nNumber of mangoes after giving away 7 mangoes: "<<sum;

    //Problem 4:-
    double avg = sum/5.0;
    cout<< "\nAverage number of mangoes collected per day throughout the adventure: "<<avg;

    return 0;
}
