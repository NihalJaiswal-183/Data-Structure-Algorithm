#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

public:
    node(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

class Pair
{
public:
    node *Node;
    int state;

public:
    Pair(node *x, int y)
    {
        this->Node = x;
        this->state = y;
    }
};

vector<node *> result;
void findpath(node *Node, int find)
{
    if (Node == NULL)
    {
        return;
    }
    if (Node->data == find)
    {
        result.push_back(Node);
        return;
    }
    findpath(Node->left, find);
    if (result.size() > 0)
    {
        result.push_back(Node);
        return;
    }
    findpath(Node->right, find);
    if (result.size() > 0)
    {
        result.push_back(Node);
        return;
    }
}
void kthlevel(node *Node, int k, node *blocker)
{
    if (Node == NULL || k < 0 || Node == blocker)
    {
        return;
    }
    if (k == 0)
    {
        cout << Node->data << endl;
        return;
    }

    kthlevel(Node->left, k - 1, blocker);
    kthlevel(Node->right, k - 1, blocker);
}
void printknodeaway(int k)
{

    for (int i = 0; i < result.size(); i++)
        kthlevel(result[i], k - i, i == 0 ? NULL : result[i - 1]);
}

int main()
{
    int n, find, k;
    cin >> n;
    int arr[n];
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str != "n")
        {
            int myint1 = stoi(str);
            arr[i] = myint1;
        }
        else
        {
            arr[i] = -1;
        }
    }
    cin >> find >> k;
    node *root = new node(arr[0]);
    Pair *t = new Pair(root, 1);
    stack<Pair *> st;
    st.push(t);
    int idx = 0;
    while (st.size() > 0)
    {
        Pair *top = st.top();
        if (top->state == 1)
        {
            idx++;
            if (arr[idx] != -1)
            {

                node *curr = new node(arr[idx]);
                top->Node->left = curr;
                Pair *lp = new Pair(curr, 1);
                st.push(lp);
            }
            else
            {

                top->Node->left = NULL;
            }
            (*top).state += 1;
        }

        else if (top->state == 2)
        {
            idx++;
            if (arr[idx] != -1)
            {

                node *curr = new node(arr[idx]);
                top->Node->right = curr;
                Pair *rp = new Pair(curr, 1);
                st.push(rp);
            }
            else
            {

                top->Node->right = NULL;
            }
            (*top).state += 1;
        }
        else
        {
            st.pop();
        }
    }

    findpath(root, find);
    printknodeaway(k);
}
