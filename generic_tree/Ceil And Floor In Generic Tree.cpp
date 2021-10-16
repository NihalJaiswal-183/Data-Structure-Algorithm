#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    vector<node *> children;
};

int ceilv = INT_MAX;
int floorv = INT_MIN;
void successorandpredecessor(node *Node, int value)
{
    if ((*Node).data > value)
    {
        ceilv = min(ceilv, (*Node).data);
    }
    if ((*Node).data < value)
    {
        floorv = max(floorv, (*Node).data);
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

    cout << "CEIL = " << ceilv << endl;
    cout << "FLOOR = " << floorv << endl;
}