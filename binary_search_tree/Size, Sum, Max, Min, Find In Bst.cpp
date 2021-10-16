#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

public:
    node(int x, node *y, node *z)
    {
        this->data = x;
        this->left = y;
        this->right = z;
    }
};
int size(node *Node)
{
    if (Node == NULL)
    {
        return 0;
    }

    int lc = size(Node->left);
    int rc = size(Node->right);

    return lc + rc + 1;
}

bool find(node *Node, int value)
{
    if (Node == NULL)
    {
        return false;
    }
    if (Node->data == value)
    {
        return true;
    }
    bool lc = find(Node->left, value);
    if (lc)
    {
        return true;
    }
    bool rc = find(Node->right, value);
    if (rc)
    {
        return true;
    }
    return false;
}

int sum(node *Node)
{
    if (Node == NULL)
    {
        return 0;
    }

    int lc = sum(Node->left);
    int rc = sum(Node->right);

    return lc + rc + Node->data;
}

int maxv(node *Node)
{
    if (Node == NULL)
    {
        return 0;
    }

    int lc = maxv(Node->left);
    int rc = maxv(Node->right);

    return max(Node->data, max(lc, rc));
}
int minv(node *Node)
{
    if (Node == NULL)
    {
        return INT_MAX;
    }

    int lc = minv(Node->left);
    int rc = minv(Node->right);

    return min(Node->data, min(lc, rc));
}
void display(node *Node)
{
    if (Node == NULL)
    {
        return;
    }
    string str = "";
    if (Node->left == NULL)
    {
        str += ".";
    }
    else
    {
        str += to_string(Node->left->data);
    }
    str += "<-" + to_string(Node->data) + "->";
    if (Node->right == NULL)
    {
        str += ".";
    }
    else
    {
        str += to_string(Node->right->data);
    }
    cout << str << endl;
    display(Node->left);
    display(Node->right);
}

node *formbinarysearchtree(int arr[], int low, int high)
{

    if (low > high)
    {
        return NULL;
    }
    int mid = (low + high) / 2;
    int d = arr[mid];
    node *lc = formbinarysearchtree(arr, low, mid - 1);
    node *rc = formbinarysearchtree(arr, mid + 1, high);
    node *cp = new node(d, lc, rc);
    return cp;
}
int main()
{
    int n, value, k = 0;
    cin >> n;
    int arr[n];
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str != "n")
        {
            int myint1 = stoi(str);
            arr[k] = myint1;
            k++;
        }
    }

    cin >> value;
    sort(arr, arr + k);

    node *root = formbinarysearchtree(arr, 0, k - 1);

    cout << size(root) << endl;

    cout << sum(root) << endl;

    cout << maxv(root) << endl;

    cout << minv(root) << endl;
    if (find(root, value))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}
