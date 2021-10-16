#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    vector<node *> children;
};

bool aresimilar(node *Node1, node *Node2)
{
    if ((*Node1).children.size() != (*Node2).children.size())
    {
        return false;
    }

    for (int i = 0; i < (*Node1).children.size(); i++)
    {
        node *child1 = (*Node1).children[i];
        node *child2 = (*Node2).children[i];

        if (aresimilar(child1, child2) == false)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n1, n2;
    cin >> n1;
    int arr1[n1];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    node *root1;
    stack<node *> st;

    for (int i = 0; i < n1; i++)
    {
        if (arr1[i] == -1)
        {
            st.pop();
        }
        else
        {
            node *t = new node;
            (*t).data = arr1[i];
            if (st.size() > 0)
            {
                st.top()->children.push_back(t);
            }
            else
            {
                root1 = t;
            }
            st.push(t);
        }
    }
    cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr2[i];
    }

    node *root2;
    // stack<node *> st;

    for (int i = 0; i < n2; i++)
    {
        if (arr2[i] == -1)
        {
            st.pop();
        }
        else
        {
            node *t = new node;
            (*t).data = arr2[i];
            if (st.size() > 0)
            {
                st.top()->children.push_back(t);
            }
            else
            {
                root2 = t;
            }
            st.push(t);
        }
    }
    if (aresimilar(root1, root2))
        cout << "true";
    else
    {
        cout << "false";
    }
}