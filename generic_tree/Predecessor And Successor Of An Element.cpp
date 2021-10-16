#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    vector<node *> children;
};
int state = 0;
int successor = -1;
int predecessor = -1;
void successorandpredecessor(node *Node, int value)
{
    if (state == 0)
    {
        if ((*Node).data == value)
        {
            state = 1;
        }
        else
        {
            predecessor = (*Node).data;
        }
    }
    else if (state == 1)
    {
        successor = (*Node).data;
        state = 2;
    }
    else if (state == 2)
    {
        return;
    }

    for (auto child : (*Node).children)
    {
        successorandpredecessor(child, value);
    }
}
int main()
{
    int n, value;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> value;
    node *root;
    stack<node *> st;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            st.pop();
        }
        else
        {
            node *t = new node;
            (*t).data = arr[i];
            if (st.size() > 0)
            {
                st.top()->children.push_back(t);
            }
            else
            {
                root = t;
            }
            st.push(t);
        }
    }

    successorandpredecessor(root, value);

    cout << "Predecessor = " << predecessor << endl;
    if (successor == -1)
    {
        cout << "Successor = Not found";
    }
    else
    {
        cout << "Successor = " << successor << endl;
    }
}