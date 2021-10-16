#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    vector<node *> children;
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
string anspre = "";
string anspost = "";
void iterativePreandPost(node *Node)
{
    stack<Pair *> st;
    Pair *t = new Pair(Node, -1);
    st.push(t);
    while (st.size() > 0)
    {
        Pair *temp = st.top();
        if (temp->state == -1)
        {
            temp->state = temp->state + 1;
            anspre += to_string(temp->Node->data) + " ";
        }
        else if (temp->state < temp->Node->children.size())
        {
            int index = temp->state;
            temp->state += 1;
            Pair *temp2 = new Pair(temp->Node->children[index], -1);
            st.push(temp2);
        }
        else if (temp->state == temp->Node->children.size())
        {
            anspost += to_string(temp->Node->data) + " ";
            st.pop();
        }
    }
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
    // cin >> value1 >> value2;
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

    iterativePreandPost(root);
    cout << anspre << endl;
    cout << anspost;
}