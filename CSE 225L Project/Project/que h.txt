
#ifndef QUETYPE_H_INCLUDED
#define QUETYPE_H_INCLUDED
#include <iostream>
using namespace std;
class FullQueue {};
class EmptyQueue {};
template <class DataType>
class QueType
{
    struct NodeType
    {
        DataType info;
        NodeType* next;
    };
public:
    QueType();
    ~QueType();
    void MakeEmpty();
    void Enqueue(DataType);
    DataType Dequeue();
    bool IsEmpty();
    bool IsFull();
private:
    NodeType *front, *rear;
};
#endif // QUETYPE_H_INCLUDED
