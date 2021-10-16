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

int size(node *Node)
{

    if (Node == NULL)
    {
        return 0;
    }

    int leftsize = size(Node->left);
    int rightsize = size(Node->right);
    int ts = leftsize + rightsize + 1;
    return ts;
}
int sum(node *Node)
{

    if (Node == NULL)
    {
        return 0;
    }

    int leftsum = sum(Node->left);
    int rightsum = sum(Node->right);
    int ts = leftsum + rightsum + Node->data;
    return ts;
}
int maxvalue(node *Node)
{
    if (Node == NULL)
    {
        return INT_MIN;
    }
    int leftmax = maxvalue(Node->left);
    int rightmax = maxvalue(Node->right);
    int totalmax = max(Node->data, max(leftmax, rightmax));
    return totalmax;
}
int height(node *Node)
{
    if (Node == NULL)
    {
        return -1;
    }
    int leftmax = height(Node->left);
    int rightmax = height(Node->right);
    int totalmax = max(leftmax, rightmax);
    return totalmax + 1;
}
int main()
{
    int n;
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

    cout << size(root) << endl;
    cout << sum(root) << endl;
    cout << maxvalue(root) << endl;
    cout << height(root) << endl;
}
