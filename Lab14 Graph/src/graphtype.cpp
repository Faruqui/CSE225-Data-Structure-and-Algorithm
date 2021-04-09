#include "graphtype.h"
const int NULL_EDGE = 0;
template<class VertexType>
GraphType<VertexType>::GraphType(int maxV)
{
    numVertices = 0;
    maxVertices = maxV;
    vertices = new VertexType[maxV];
    edges = new int*[maxV];
    for(int i=0; i<maxV; i++)
        edges[i] = new int [maxV];
    marks = new bool[maxV];
}
template<class VertexType>
GraphType<VertexType>::~GraphType()
{
    delete [] vertices;
    delete [] marks;
    for(int i=0; i<maxVertices; i++)
        delete [] edges[i];
    delete [] edges;
}
template<class VertexType>
void GraphType<VertexType>::MakeEmpty()
{
    numVertices = 0;
}
template<class VertexType>
bool GraphType<VertexType>::IsEmpty()
{
    return (numVertices == 0);
}
template<class VertexType>
bool GraphType<VertexType>::IsFull()
{
    return (numVertices == maxVertices);
}
template<class VertexType>
void GraphType<VertexType>::AddVertex(VertexType vertex)
{
    vertices[numVertices] = vertex;
    for (int index=0; index<numVertices; index++)
    {
        edges[numVertices][index] = NULL_EDGE;
        edges[index][numVertices] = NULL_EDGE;
    }
    numVertices++;
}
template<class VertexType>
int IndexIs(VertexType* vertices, VertexType vertex)
{
    int index = 0;
    while (!(vertex == vertices[index]))
        index++;
    return index;
}
template<class VertexType>
void GraphType<VertexType>::ClearMarks()
{
    for(int i=0; i<maxVertices; i++)
        marks[i] = false;
}
template<class VertexType>
void GraphType<VertexType>::MarkVertex(VertexType vertex)
{
    int index = IndexIs(vertices, vertex);
    marks[index] = true;
}
template<class VertexType>
bool GraphType<VertexType>::IsMarked(VertexType
                                     vertex)
{
    int index = IndexIs(vertices, vertex);
    return marks[index];
}
template<class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex,
                                    VertexType toVertex, int weight)
{
    int row = IndexIs(vertices, fromVertex);
    int col= IndexIs(vertices, toVertex);
    edges[row][col] = weight;
}
template<class VertexType>
int GraphType<VertexType>::WeightIs(VertexType fromVertex,
                                    VertexType toVertex)
{
    int row = IndexIs(vertices, fromVertex);
    int col= IndexIs(vertices, toVertex);
    return edges[row][col];
}
template<class VertexType>
void GraphType<VertexType>::GetToVertices(VertexType vertex,
        QueType<VertexType>& adjVertices)
{
    int fromIndex, toIndex;
    fromIndex = IndexIs(vertices, vertex);
    for (toIndex = 0; toIndex < numVertices; toIndex++)
        if (edges[fromIndex][toIndex] != NULL_EDGE)
            adjVertices.Enqueue(vertices[toIndex]);
}
template<class VertexType>
void GraphType<VertexType>::DepthFirstSearch(VertexType
        startVertex, VertexType endVertex)
{
    StackType<VertexType> stack;
    QueType<VertexType> vertexQ;
    int cost = 0;
    bool found = false;
    VertexType vertex, item;
    ClearMarks();
    stack.Push(startVertex);
    do
    {
        vertex = stack.Top();
        stack.Pop();
        if(vertex == endVertex)
        {
            cout << vertex << " ";
            found = true;
        }
        else
        {
            if (!IsMarked(vertex))
            {
                MarkVertex(vertex);
                cout << vertex << " ";
                //cost++;
                GetToVertices(vertex,vertexQ);
                while (!vertexQ.IsEmpty())
                {
                    vertexQ.Dequeue(item);
                    if (!IsMarked(item))
                        stack.Push(item);
                }
            }
        }
    }
    while (!stack.IsEmpty() && !found);
    cout << endl;
    if (!found)
        cout << "Path not found." << endl;
    else
    {
        cout<<"Path Found. Path Cost = "<<cost<<endl;
    }
}
template<class VertexType>
void GraphType<VertexType>::BreadthFirstSearch(VertexType
        startVertex, VertexType endVertex)
{
    QueType<VertexType> queue;
    QueType<VertexType> vertexQ;
    int cost = 0;
    bool found = false;
    VertexType vertex, item;
    ClearMarks();
    queue.Enqueue(startVertex);
    do
    {
        queue.Dequeue(vertex);
        if (vertex == endVertex)
        {
            cout << vertex << " ";
            found = true;
        }
        else
        {
            if (!IsMarked(vertex))
            {
                MarkVertex(vertex);
                cout << vertex << " ";
                cost++;
                GetToVertices(vertex, vertexQ);
                while (!vertexQ.IsEmpty())
                {
                    vertexQ.Dequeue(item);
                    if (!IsMarked(item))
                        queue.Enqueue(item);
                }
            }
        }
    }
    while (!queue.IsEmpty() && !found);
    cout << endl;
    if (!found)
        cout << "Path not found." << endl;
    else
    {
        cout<<"Path Found. Path Cost = "<<cost<<endl;
    }
}
template<class VertexType>
int GraphType<VertexType>::OutDegree(VertexType v)
{
    QueType<VertexType> vertexQ;
    int degree = 0;
    ClearMarks();
    VertexType item;
    GetToVertices(v,vertexQ);

    while (!vertexQ.IsEmpty())
    {
        vertexQ.Dequeue(item);
        if(item != v) degree++;
    }
    return degree;

}
template<class VertexType>
bool GraphType<VertexType>::FoundEdge(VertexType u, VertexType v)
{
    QueType<VertexType> vertexQ;
    bool found = false;
    ClearMarks();
    VertexType item;

    GetToVertices(u,vertexQ);
    while (!vertexQ.IsEmpty())
    {
        vertexQ.Dequeue(item);
        if(item == v) found = true;
    }

    GetToVertices(v,vertexQ);
    while (!vertexQ.IsEmpty())
    {
        vertexQ.Dequeue(item);
        if(item == u) found = true;
    }

    return found;
}


template class GraphType<char>;
