#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    vector<node *> children;
};

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
    queue<node *> level;
    level.push(root);
    level.push(NULL);

    while (level.size() > 0)
    {
        node *temp = level.front();
        if (temp == NULL)
        {
            level.pop();
            if (level.size() > 0)
            {

                level.push(NULL);
                cout << endl;
            }
        }
        else
        {
            level.pop();
            cout << (*temp).data << " ";
            for (auto child : (*temp).children)
            {
                level.push(child);
            }
        }
    }
    
}