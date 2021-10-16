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
    int minv = INT_MAX;
    int maxv = INT_MIN;
    int size;
};

int tsize = 0;
int nodevalue;

bclass isbinarytree(node *Node)
{
    if (Node == NULL)
    {
        bclass p;
        p.bst = true;
        p.minv = INT_MAX;
        p.maxv = INT_MIN;
        p.size = 0;
        return p;
    }
    bclass lt = isbinarytree(Node->left);
    bclass rt = isbinarytree(Node->right);

    bclass ans;

    ans.bst = lt.bst && rt.bst && Node->data >= lt.maxv && Node->data <= rt.minv;
    ans.minv = min(Node->data, min(lt.minv, rt.minv));
    ans.maxv = max(Node->data, max(lt.maxv, rt.maxv));
    ans.size = lt.size + rt.size + 1;

    if (ans.bst == true)
    {

        if (ans.size > tsize)
        {
            tsize = lt.size + rt.size + 1;
            nodevalue = Node->data;
        }
    }

    return ans;
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

    isbinarytree(root);

    cout << nodevalue << "@" << tsize;
}
