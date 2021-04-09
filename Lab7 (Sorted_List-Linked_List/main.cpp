#include <iostream>
#include "LinkedList.h"
#include "ListNode.h"

using namespace std;

int main()
{
    LinkedList l;

    l.InsertNode("Lars Ulrich", "+(607)253645", 125.75);
    l.InsertNode("Krik Hammett", "+(963)748254", 113.89);
    l.InsertNode("Jason Newsted", "+(984)125745", 254.01);
    l.InsertNode("Cliff Burton", "+(964)187795", 362.8);
    l.InsertNode("Tarja Turunen", "+(357)015745", 11.25);
    l.InsertNode("Robert Langdon", "+(781)175705", 369.45);
    l.InsertNode("Jeremy Clarkson", "+(984)127745", 1254.05);
    l.InsertNode("Richard Hammond", "+(984)127746", 254.01 );
    l.InsertNode("James May", "+(984)127747", 369.69);
    l.InsertNode("Adele Laurie Blue Adkins", "+(984)125745", 123.32);
    l.InsertNode("Dan Brown", "+(154)342547", 25.36);
    l.InsertNode("Bob Marley", "+(989)125961", 1237.24);
    l.InsertNode("Chuck Norris", "(999)999999", 0.0);

    l.PrintListWithBill();
    cout <<"\n\n";
    l.PrintAmount(150);

    cout<<"\nEnter name to search: ";
    string x;
    //getchar();
    getline(cin, x);
    l.printName(x);
}



