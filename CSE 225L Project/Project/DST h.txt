#ifndef DIGITALSEARCHTREE_H_INCLUDED
#define DIGITALSEARCHTREE_H_INCLUDED
#include <bitset>

#include "quetype.h"

template <class DataType>
class DigitalSearchTree
{
private:
    struct tree_node
    {
        tree_node* left;
        tree_node* right;
        DataType data;
    };
    tree_node* root;
    void fillInOrder(QueType<int>&,tree_node*);
    void fillInPreOrder(QueType<int>&,tree_node*);
    void fillInPostOrder(QueType<int>&,tree_node*);
    void makeEmpty(tree_node*&);
    void inorder(tree_node*);
    void preorder(tree_node*);
    void postorder(tree_node*);

public:
    DigitalSearchTree();
    virtual ~DigitalSearchTree();
    bool isEmpty();
    void insert(DataType);
    void remove(DataType);
    void print_inorder();
    void print_preorder();
    void print_postorder();
    bool searchItem(DataType);
    void makeTreeEmpty();
    void getInOrder(QueType<int>&);
    void getPreOrder(QueType<int>&);
    void getPostOrder(QueType<int>&);
    void counter(int*, tree_node*);
    bool search(DataType);
    int countNode();

};

#endif // DIGITALSEARCHTREE_H_INCLUDED
