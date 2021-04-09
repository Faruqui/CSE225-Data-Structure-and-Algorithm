#include "linkedlist.h"
LinkedList::LinkedList()
{
    head = NULL;
    nextItem = NULL;
}
LinkedList::~LinkedList()
{
    MakeEmpty();
}
void LinkedList::MakeEmpty()
{
    ListNode *temp;
    while(head != NULL)
    {
        temp = head;
        head = head->nextNode;
        delete temp;
    }
}
void LinkedList::InsertNode(string name,string number, double BILL)
{
    ListNode *newNode;
    newNode = new ListNode(name,number, BILL); // creating &
// initializing the new node with the parameter data
    bool moreToSearch; // will be used to find the appropriate
// insertion place for the new node
    ResetList();
    nextItem = head;
    ListNode *predLoc = NULL; // predLoc will always point to the
//previous node of nextItem
    moreToSearch = (nextItem != NULL);
    while(moreToSearch)
    {
        if(nextItem->CompareToName(name)<0)
        {
            predLoc = nextItem;
            nextItem = nextItem->nextNode;
            moreToSearch = (nextItem != NULL);
        }
        else
            moreToSearch = false;
    }
    if(predLoc == NULL) // for the first node
    {
        newNode->nextNode = head; // for first node, value of
// head is null here
        head = newNode;
    }
    else
    {
        newNode->nextNode = nextItem;
        predLoc->nextNode = newNode;
    }
}
void LinkedList::ResetList()
{
    nextItem = NULL;
}
bool LinkedList::SearchByName(string n)
{
    ResetList();
    nextItem = head;
    bool searchFlag = false;
    while(nextItem!=NULL)
    {
        if(nextItem->CompareToName(n)==0)
        {
            searchFlag = true;
            break;
        }
        else
        {
            nextItem = nextItem->nextNode;
        }
    }
    ResetList();
    return searchFlag;
}
bool LinkedList::SearchByNumber(string num)
{
    ResetList();
    nextItem = head;
    bool searchFlag = false;
    while(nextItem!=NULL)
    {
        if(nextItem->CompareToNumber(num)==0)
        {
            searchFlag = true;
            break;
        }
        else
        {
            nextItem = nextItem->nextNode;
        }
    }
    ResetList();
    return searchFlag;
}
void LinkedList::DeleteNode(string name)
{
    if(SearchByName(name)==false)
    {
        cout<<"Node with name = ";
        cout<<name;
        cout<<" does not exist"<<endl;
    }
    else
    {
        ResetList();
        nextItem = head;
        if(nextItem->CompareToName(name)==0)// item to be deleted
//is at the list's beginning
        {
            ListNode *tempPtr = head;
            head = head->nextNode;
            delete tempPtr;
        }
        else
        {
            while(nextItem->nextNode->CompareToName(name)!=0)
            {
                nextItem = nextItem->nextNode;
            }
// now nextItem is pointing to the node before the
// ListNode containing the user to be deleted
            ListNode *tempPtr;
            tempPtr = nextItem->nextNode; // tempPtr pointing to
//the node to be deleted
            nextItem->nextNode = nextItem->nextNode->nextNode;
// pointing to the ListNode which was just after the
// node containing the ‘name’ to be deleted
            delete tempPtr;
        }
        ResetList();
    }
}
void LinkedList::PrintList()
{
    ResetList();
    nextItem = head;
    string name,number;
    while(nextItem!=NULL)
    {
        name = nextItem->GetName();
        number = nextItem->GetNumber();
        cout<<"Name:";
        cout<<name;
        cout<<" & Number:";
        cout<<number<<endl;
        nextItem = nextItem->nextNode;
    }
}

void LinkedList::PrintListWithBill()
{
    ResetList();
    nextItem = head;
    string name, number;
    double bill;

    while(nextItem != NULL)
    {
        name = nextItem->GetName();
        number = nextItem->GetNumber();
        bill = nextItem->GetBill();
        cout<<"Name: ";
        cout<<name;
        cout<<"\tNumber: ";
        cout<<number;
        cout<<"\tBill: ";
        cout<<bill<<endl;
        nextItem = nextItem->nextNode;
    }
}


void LinkedList::PrintAmount(double x)
{
    ResetList();
    nextItem = head;
    string name, number;
    double bill;

    while(nextItem != NULL)
    {
        name = nextItem->GetName();
        number = nextItem->GetNumber();
        bill = nextItem->GetBill();
        if(bill > x)
        {
            cout<<"Name: ";
            cout<<name;
            cout<<"\tNumber: ";
            cout<<number;
            cout<<"\tBill: ";
            cout<<bill<<endl;
        }
        nextItem = nextItem->nextNode;
    }
}

void LinkedList::printName(string x)
{
    ResetList();
    nextItem = head;
    string name, number;
    double bill;

    while(nextItem != NULL)
    {
        name = nextItem->GetName();
        number = nextItem->GetNumber();
        bill = nextItem->GetBill();

        if(SearchByName(x) && x.compare(name)==0)
        {
            cout<<"\tNumber: ";
            cout<<number;
        }
        nextItem = nextItem->nextNode;
    }
}
