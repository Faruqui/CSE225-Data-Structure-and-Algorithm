#include <iostream>
#include "graphtype.h"

using namespace std;

int main()
{
    GraphType <char> g(8);

    g.AddVertex('A');
    g.AddVertex('B');
    g.AddVertex('C');
    g.AddVertex('D');
    g.AddVertex('E');
    g.AddVertex('F');
    g.AddVertex('G');
    g.AddVertex('H');

    g.AddEdge('F','H', 1);
    g.AddEdge('H','E', 1);
    g.AddEdge('D','E', 1);
    g.AddEdge('D','G', 1);
    g.AddEdge('G','F', 1);
    g.AddEdge('D','A', 1);
    g.AddEdge('A','D', 1);
    g.AddEdge('A','B', 1);
    g.AddEdge('A','C', 1);
    g.AddEdge('B','A', 1);

    int x = g.OutDegree('D');
    cout << "\nThe out Degree of D is "<<x;

    if(g.FoundEdge('A', 'D')) cout<<"\n\nThere is an edge.";
    else cout<<"\n\nThere is no edge.";

    if(g.FoundEdge('B', 'D')) cout<<"\n\nThere is an edge.";
    else cout<<"\n\nThere is no edge.";

    cout <<"\n\n";
    g.DepthFirstSearch('B','E');
    g.DepthFirstSearch('E','B');
    g.BreadthFirstSearch('B','E');
    g.BreadthFirstSearch('E','B');
}
