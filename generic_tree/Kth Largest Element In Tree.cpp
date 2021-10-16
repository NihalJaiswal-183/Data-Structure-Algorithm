
//by using priority queue (one more soln is there by using ceil and floor property of INT_MAX)
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    vector<node *> children;
};

priority_queue<int, vector<int>, greater<int>> pq;
int k;
void traverse(node *Node)
{
    if (Node == NULL)
    {
        return;
    }

    for (auto child : (*Node).children)
    {
        traverse(child);
    }
    pq.push(Node->data);
    if (pq.size() > k)
    {
        pq.pop();
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
    cin >> k;
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
    traverse(root);
    cout << pq.top() << endl;
}