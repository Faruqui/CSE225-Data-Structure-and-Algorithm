#ifndef LISTNODE_H_INCLUDED
#define LISTNODE_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
class ListNode
{
private:
    string name,number;
    double bill;
public:
    ListNode();
    ListNode *nextNode;
    ListNode(string,string,double);
    string GetName();
    string GetNumber();
    double GetBill();
    void setBill(double);
    int CompareToName(string);
    int CompareToNumber(string);
    void printNode();
};
#endif // LISTNODE_H_INCLUDED
