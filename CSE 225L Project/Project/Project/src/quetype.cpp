#include "quetype.h"
template <class DataType>
QueType<DataType>::QueType()
{
    front = NULL;
    rear = NULL;
}
template <class DataType>
bool QueType<DataType>::IsEmpty()
{
    return (front == NULL);
}
template<class DataType>
bool QueType<DataType>::IsFull()
{
    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(bad_alloc& exception)
    {
        return true;
    }
}
template <class DataType>
void QueType<DataType>::Enqueue(DataType newItem)
{
    if (IsFull())
        throw FullQueue();
    else
    {
        NodeType* newNode;
        newNode = new NodeType;
        newNode->info = newItem;
        newNode->next = NULL;
        if (rear == NULL)
            front = newNode;
        else
            rear->next = newNode;
        rear = newNode;
    }
}
template <class DataType>
DataType QueType<DataType>::Dequeue()
{
    DataType item;
    if (IsEmpty())
        throw EmptyQueue();
    else
    {
        NodeType* tempPtr;
        tempPtr = front;
        item = front->info;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete tempPtr;
        return item;
    }
}
template <class DataType>
void QueType<DataType>::MakeEmpty()
{
    NodeType* tempPtr;
    while (front != NULL)
    {
        tempPtr = front;
        front = front->next;
        delete tempPtr;
    }
    rear = NULL;
}
template <class DataType>
QueType<DataType>::~QueType()
{
    MakeEmpty();
}
template class QueType<int>;
