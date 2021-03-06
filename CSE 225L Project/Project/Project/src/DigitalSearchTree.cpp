#include "DigitalSearchTree.h"

template <class DataType>
DigitalSearchTree<DataType>::DigitalSearchTree()
{
    root = NULL;
}

template <class DataType>
DigitalSearchTree<DataType>::~DigitalSearchTree()
{
    //dtor
}

template <class DataType>
void DigitalSearchTree<DataType>::insert(DataType d)
{
    std::string s = std::bitset< 4 >( (int)d ).to_string();
    int i = 0;
    cout << "\n"<<d<<" is: "<<s<<"\n";
    char c = s[0];

    tree_node* t = new tree_node;
    t->data = d;
    t->left = NULL;
    t->right = NULL;
    tree_node* parent;
    parent = NULL;

    if(isEmpty())
    {
        root = t;
    }
    else // inserting into a non-empty tree
    {
        tree_node* curr;
        curr = root;

        while(curr)
        {
            parent = curr;
            if(c == '0')
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
            i++;
            c = s[i];
        }
        i--;
        c = s[i];
        if(c == '0')
        {
            parent->left = t;
        }
        else
        {
            parent->right = t;
        }
    }
}

template <class DataType>
bool DigitalSearchTree<DataType>::isEmpty()
{
    if(root == NULL)
    {
        return true;
    }
    else
        return false;
}

template <class DataType>
void DigitalSearchTree<DataType>::inorder(tree_node* p)
{
    if(p != NULL)
    {
        if(p->left)
            inorder(p->left);
        cout<<" "<<p->data<<" ";
        if(p->right)
            inorder(p->right);
    }
    else
        return;
}
template <class DataType>
void DigitalSearchTree<DataType>::getInOrder(QueType<int>& q)
{
    if(!q.IsEmpty())
        q.MakeEmpty();
    fillInOrder(q,root);
}
template <class DataType>
void DigitalSearchTree<DataType>::fillInOrder(QueType<int>& q,tree_node* p)
{
    if(p!= NULL)
    {
        if(p->left)
            fillInOrder(q,p->left);
        q.Enqueue(p->data);
        if(p->right)
            fillInOrder(q,p->right);
    }
    else
        return;
}
template <class DataType>
void DigitalSearchTree<DataType>::print_inorder()
{
    inorder(root);
}


template<class DataType>
void DigitalSearchTree<DataType>::print_preorder()
{
    preorder(root);
}
template<class DataType>
void DigitalSearchTree<DataType>::preorder(tree_node* p)
{
    if(p != NULL)
    {
        cout<<" "<<(DataType)p->data<<" ";
        if(p->left)
            preorder(p->left);
        if(p->right)
            preorder(p->right);
    }
    else
        return;
}
template<class DataType>
void DigitalSearchTree<DataType>::print_postorder()
{
    postorder(root);
}
template<class DataType>
void DigitalSearchTree<DataType>::postorder(tree_node* p)
{
    if(p != NULL)
    {
        if(p->left)
            postorder(p->left);
        if(p->right)
            postorder(p->right);

        cout<<" "<<(DataType)p->data<<" ";
    }
    else
        return;
}
template <class DataType>
void DigitalSearchTree<DataType>::counter(int* c, tree_node* p)
{
    if(p != NULL)
    {
        if(p->left)
            counter(c, p->left);
        if(p->right)
            counter(c, p->right);
        *c = *c+1;
    }
    else
        return;
}
template <class DataType>
int DigitalSearchTree<DataType>::countNode()
{
    int c=0;
    counter(&c, root);
    return c;
}

template <class DataType>
bool DigitalSearchTree<DataType>::search(DataType d)
{
    std::string s = std::bitset< 4 >( (int)d ).to_string();
    cout << "\n"<<d<<" is: "<<s<<"\n";

    int i = 0;
    char c = s[0];
    bool found = false;

    tree_node* parent;
    parent = NULL;

    if(isEmpty())
    {
        cout<<"tree is empty"<<endl;
    }
    else
    {
        tree_node* curr;
        curr = root;
        while(curr)
        {
            if(curr->data == d)
            {
                found = true;
                break;
            }
            if(curr->left == NULL && curr->right == NULL)
            {
                return found;
            }
            if(c == '0' && curr->left != NULL )
            {
                curr = curr->left;
                if(curr->data == d)
                {
                    found = true;
                    break;
                }
            }
            else if(curr->right != NULL )
            {
                curr = curr->right;
                if(curr->data == d)
                {
                    found = true;
                    break;
                }
            }
            i++;
            c = s[i];
        }
    }
    return found;
}

template <class DataType>
void DigitalSearchTree<DataType>::remove(DataType d)
{
    std::string s = std::bitset< 4 >( (int)d ).to_string();
    cout << "\n"<<d<<" is: "<<s<<"\n";

    int i = 0;
    char c = s[0];
    bool found = false;
    tree_node* parent;
    parent = NULL;

    if(isEmpty())
    {
        cout<<"tree is empty"<<endl;
    }
    else
    {

        tree_node* curr;
        curr = root;

        while(curr)
        {
            if(curr->data == d)
            {
                found = true;
                break;
            }
            if(curr->left == NULL && curr->right == NULL)
            {
                cout<<"not found"<<endl;
                break;
            }
            if(c == '0' && curr->left != NULL )
            {
                parent = curr;
                curr = curr->left;
                if(curr->data == d)
                {
                    found = true;

                    break;
                }
            }
            else if(curr->right != NULL )
            {
                parent = curr;
                curr = curr->right;
                if(curr->data == d)
                {
                    found = true;

                    break;
                }

            }
            i++;
            c = s[i];
        }
        if(found)
        {
            if((curr->left == NULL && curr->right != NULL) || (curr->left != NULL
                    && curr->right == NULL))
            {
                if(curr->left == NULL && curr->right != NULL)
                {
                    if(parent->left == curr)
                    {
                        parent->left = curr->right;
                        delete curr;
                    }
                    else
                    {
                        parent->right = curr->right;
                        delete curr;
                    }
                }
                else
                {
                    if(parent->left == curr)
                    {
                        parent->left = curr->left;
                        delete curr;
                    }
                    else
                    {
                        parent->right = curr->left;
                        delete curr;
                    }
                }
                return;
            }
            if( curr->left == NULL && curr->right == NULL)
            {
                if(parent->left == curr)
                    parent->left = NULL;
                else
                    parent->right = NULL;
                delete curr;
                return;
            }
            if (curr->left != NULL && curr->right != NULL)
            {
                tree_node* chkr;
                chkr = curr->right;
                if((chkr->left == NULL) && (chkr->right == NULL))
                {
                    curr->data = chkr->data;
                    delete chkr;
                    curr->right = NULL;
                }
                else
                {

                    if((curr->right)->left != NULL)
                    {
                        tree_node* lcurr;
                        tree_node* lcurrp;
                        lcurrp = curr->right;
                        lcurr = (curr->right)->left;
                        while(lcurr->left != NULL)
                        {
                            lcurrp = lcurr;
                            lcurr = lcurr->left;
                        }
                        curr->data = lcurr->data;
                        delete lcurr;
                        lcurrp->left = NULL;
                    }
                    else
                    {
                        tree_node* tmp;
                        tmp = curr->right;
                        curr->data = tmp->data;
                        curr->right = tmp->right;
                        delete tmp;
                    }
                }
                return;
            }
        }
    }
}

template class DigitalSearchTree<int>;
template class DigitalSearchTree<char>;
