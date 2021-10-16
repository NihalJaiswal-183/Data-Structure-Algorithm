#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    vector<node *> children;
};
void display(node *Node)
{
    string str = to_string((*Node).data) + " -> ";
    for (auto child : (*Node).children)
    {
        str += to_string((*child).data) + ", ";
    }
    str += ".";
    cout << str << endl;
    for (auto child : (*Node).children)
        display(child);
}

void mirror(node *Node)
{
    for (auto child : (*Node).children)
    {
        mirror(child);
    }
    reverse((*Node).children.begin(), (*Node).children.end());
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
    display(root);
    mirror(root);
    display(root);
}