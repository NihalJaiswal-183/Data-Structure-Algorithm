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

vector<int> result;

void findpath(node *Node, int find)
{
    if (Node == NULL)
    {
        return;
    }
    if (Node->data == find)
    {
        result.push_back(find);
        return;
    }
    findpath(Node->left, find);
    if (result.size() > 0)
    {
        result.push_back(Node->data);
        return;
    }
    findpath(Node->right, find);
    if (result.size() > 0)
    {
        result.push_back(Node->data);
        return;
    }
}

bool hasnode(node *Node, int find)
{
    if (Node == NULL)
    {
        return false;
    }
    if (Node->data == find)
    {
        return true;
    }

    bool a = hasnode(Node->left, find);
    if (a == true)
    {
        return true;
    }
    bool b = hasnode(Node->right, find);
    if (b == true)
    {
        return true;
    }

    return false;
}

int main()
{
    int n, find;
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
    if (hasnode(root, find) == true)
    {
        cout << "true" << endl;
        findpath(root, find);
        cout << "[";
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i];
            if (i != result.size() - 1)
                cout << ", ";
        }
        cout << "]";
    }
    else
    {
        cout << "false" << endl;
        cout << "[]";
    }
}
