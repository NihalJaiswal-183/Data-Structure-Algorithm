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

int tilt = 0;
int findtilt(node *Node)
{
    if (Node == NULL)
    {

        return 0;
    }
    int lt = findtilt(Node->left);
    int rt = findtilt(Node->right);
    int ltilt = abs(lt - rt);

    tilt += ltilt;
    int sum = lt + rt + Node->data;

    return sum;
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

    findtilt(root);
    cout << tilt;
}
