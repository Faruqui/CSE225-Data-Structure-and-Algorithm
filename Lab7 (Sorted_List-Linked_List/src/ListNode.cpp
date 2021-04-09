#include "listnode.h"
ListNode::ListNode(string n,string num, double x)
{
    name = n;
    number = num;
    bill = x;
    nextNode = NULL;
}
ListNode::ListNode()
{
    nextNode = NULL;
}

string ListNode::GetName()
{
    return name;
}
string ListNode::GetNumber()
{
    return number;
}
int ListNode::CompareToName(string n)
{
    return name.compare(n); // returns 0 if found equal, -ve if n
// greater than name, +ve if n smaller
}
int ListNode::CompareToNumber(string num)
{
    return number.compare(num);// returns 0 if found equal, -ve
// if n greater than name, +ve if n smaller
}
double ListNode::GetBill()
{
    return bill;
}
void ListNode::setBill(double x)
{
    bill = x;
}
void ListNode::printNode()
{
    cout<<"Name: "<<name;
    cout<<"Number: "<<number;
    cout<<"Bill: "<<bill<<endl;
}
