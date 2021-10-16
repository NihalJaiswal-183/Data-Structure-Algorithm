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

    vector<int> p1 = findNode(root, value1);
    result.clear();
    vector<int> p2 = findNode(root, value2);
    int i = p1.size() - 1;
    int j = p2.size() - 1;
    while (i >= 0 && j >= 0 && p1[i] == p2[j])
    {
        i--;
        j--;
    }
    j++;
    i++;
    int ans = i + j;
    cout << ans;
}