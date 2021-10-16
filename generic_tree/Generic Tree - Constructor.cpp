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
    string str = to_string((*Node).data) + "->";
    for (auto child : (*Node).children)
    {
        str += to_string((*child).data) + ",";
    }
    str += ".";
    cout << str << endl;
    for (auto child : (*Node).children)
        display(child);
}
int main()
{
    int n = 24;
    int arr[n] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};

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
    
}