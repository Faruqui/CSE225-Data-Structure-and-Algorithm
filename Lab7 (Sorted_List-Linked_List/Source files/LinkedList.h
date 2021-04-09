#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include "listnode.h"
class LinkedList
{
private:
    ListNode *head;// will always point to the head/front of the
// list
    ListNode *nextItem;//will be used to traverse the nodes of the
//list
public:
    LinkedList();// constructor
    ~LinkedList();// destructor
    void MakeEmpty();
    void InsertNode(string,string, double);
    void ResetList(); // resets the nextItem pointer to the front
    bool SearchByName(string);
    bool SearchByNumber(string);
    void DeleteNode(string); //will delete the ListNode whose
// name is equal to this function's
// parameter
    //ListNode getNextNode();
    void PrintList();
    void PrintListWithBill();
    void PrintAmount(double);
    void printName(string);
};
#endif // LINKEDLIST_H_INCLUDED
