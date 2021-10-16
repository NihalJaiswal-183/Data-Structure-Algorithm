#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

public:
    node(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

class Pair
{
public:
    node *Node;
    int state;

public:
    Pair(node *x, int y)
    {
        this->Node = x;
        this->state = y;
    }
};

class bclass
{
public:
    bool bst;
    int ht;
};

void display(node *Node)
{
    if (Node == NULL)
    {
        return;
    }
    string str = "";
    if (Node->left == NULL)
    {
        str += ".";
    }
    else
    {
        str += to_string(Node->left->data);
    }
    str += " <- " + to_string(Node->data) + " -> ";
    if (Node->right == NULL)
    {
        str += ".";
    }
    else
    {
        str += to_string(Node->right->data);
    }
    cout << str << endl;
    display(Node->left);
    display(Node->right);
}
int maxv(node *Node)
{
    if (Node->right != NULL)
    {
        return maxv(Node->right);
    }
    else
    {
        return Node->data;
    }
}
node *removenode(node *Node, int value)
{
    if (Node == NULL)
    {

        return NULL;
    }

    if (Node->data > value)
    {
        Node->left = removenode(Node->left, value);
    }
    else if (Node->data < value)
    {
        Node->right = removenode(Node->right, value);
    }
    else
    {
        if (Node->left == NULL && Node->right == NULL)
        {
            return NULL;
        }
        else if (Node->left == NULL && Node->right != NULL)
        {
            return Node->right;
        }
        else if (Node->left != NULL && Node->right == NULL)
        {
            return Node->left;
        }
        else if (Node->left != NULL && Node->right != NULL)
        {
            int maxvalue = maxv(Node->left);
            Node->data = maxvalue;
            Node->left = removenode(Node->left, maxvalue);
            return Node;
        }
    }

    return Node;
}

int main()
{
    int n, find, k;
    cin >> n;
    int arr[n];
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str != "n")
        {
            int myint1 = stoi(str);
            arr[i] = myint1;
        }
        else
        {
            arr[i] = -1;
        }
    }
    cin >> find;
    node *root = new node(arr[0]);
    Pair *t = new Pair(root, 1);
    stack<Pair *> st;
    st.push(t);
    int idx = 0;
    while (st.size() > 0)
    {
        Pair *top = st.top();
        if (top->state == 1)
        {
            idx++;
            if (arr[idx] != -1)
            {

                node *curr = new node(arr[idx]);
                top->Node->left = curr;
                Pair *lp = new Pair(curr, 1);
                st.push(lp);
            }
            else
            {

                top->Node->left = NULL;
            }
            (*top).state += 1;
        }

        else if (top->state == 2)
        {
            idx++;
            if (arr[idx] != -1)
            {

                node *curr = new node(arr[idx]);
                top->Node->right = curr;
                Pair *rp = new Pair(curr, 1);
                st.push(rp);
            }
            else
            {

                top->Node->right = NULL;
            }
            (*top).state += 1;
        }
        else
        {
            st.pop();
        }
    }

    node *ans = removenode(root, find);
    display(ans);
}
