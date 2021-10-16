#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    vector<node *> children;
};

bool aresymmetric(node *Node)
{

    for (int i = 0; i < (*Node).children.size() / 2; i++)
    {
        int j = (*Node).children.size() - 1;
        node *child1 = (*Node).children[i];
        node *child2 = (*Node).children[j - i];
        if ((*child1).children.size() != (*child2).children.size())
        {
            return false;
        }
    }
    for (auto child : (*Node).children)
    {
        if (aresymmetric(child) == false)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

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

    if (aresymmetric(root))
        cout << "true";
    else
    {
        cout << "false";
    }
}