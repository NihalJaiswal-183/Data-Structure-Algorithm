#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    vector<node *> children;
};
int dia = 0;
int diameter(node *Node)
{
    int fcm = -1;
    int scm = -1;
    for (auto child : (*Node).children)
    {
        int ans = diameter(child);
        if (ans > fcm)
        {
            scm = fcm;
            fcm = ans;
        }
        else if (ans > scm)
        {
            scm = ans;
        }
    }
    if (fcm + scm + 2 > dia)
    {
        dia = fcm + scm + 2;
    }
    fcm += 1;
    return fcm;
}
int main()
{
    int n, value1, value2;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> value1 >> value2;
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

    diameter(root);
    cout << dia;
}