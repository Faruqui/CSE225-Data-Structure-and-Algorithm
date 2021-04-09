#include <iostream>
#include "DigitalSearchTree.h"

using namespace std;

int main()
{
    DigitalSearchTree<int> ds;
    DigitalSearchTree<char> s;

    ds.insert(25);
    ds.insert(2);
    ds.insert(5);
    ds.insert(3);

    cout << "\nInorder: ";
    ds.print_inorder();
    cout <<"\nPreorder: ";
    ds.print_preorder();
    cout <<"\nPostorder: ";
    ds.print_postorder();

    int x = ds.countNode();
    cout<< "\nNo. of nodes: "<< x;



    s.insert('a');
    s.insert('z');
    s.insert('S');
    s.insert('d');
    s.insert('A');
    s.insert('r');
    cout << "\nInorder: ";
    s.print_inorder();
    cout <<"\nPreorder: ";
    s.print_preorder();
    cout <<"\nPostorder: ";
    s.print_postorder();

    x = s.countNode();
    cout<< "\nNo. of nodes: "<< x;

    if(s.search('A')) cout <<"\nFound";
    s.remove('A');
    cout << "\nInorder: ";
    s.print_inorder();
}
