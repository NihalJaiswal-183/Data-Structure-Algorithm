#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    vector<node *> children;
};

void treetraversal(node *Node)
{

    cout << "Node Pre " << (*Node).data << endl;
    for (auto child : (*Node).children)
    {
        cout << "Edge Pre " << (*Node).data << "--" << (*child).data << endl;
        treetraversal(child);
        cout << "Edge Post " << (*Node).data << "--" << (*child).data << endl;
    }
    cout << "Node Post " << (*Node).data << endl;
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
    treetraversal(root);
}