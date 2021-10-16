#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    vector<node *> children;
};

bool findNode(node *Node, int value)
{
    if ((*Node).data == value)
    {
        return true;
    }

    bool ans = false;
    for (auto child : (*Node).children)
    {
        ans = findNode(child, value);
        if (ans)
        {
            return true;
        }
    }
    return ans;
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
    if (findNode(root, value))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}