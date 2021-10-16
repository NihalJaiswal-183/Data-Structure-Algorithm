#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    vector<node *> children;
};
vector<int> result;
vector<int> findNode(node *Node, int value)
{
    if ((*Node).data == value)
    {
        result.push_back((*Node).data);
        return result;
    }

    for (auto child : (*Node).children)
    {
        findNode(child, value);
        if (result.size() > 0)
        {

            result.push_back((*Node).data);
            return result;
        }
    } 
    return result;
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

    findNode(root, value);
    cout << "[";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i != result.size() - 1)
            cout << ", ";
    }
    cout << "]";
}