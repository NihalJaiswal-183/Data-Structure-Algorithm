// // #include <bits/stdc++.h>
// // using namespace std;

// // class node
// // {
// // public:
// //     int data;
// //     node *left;
// //     node *right;

// // public:
// //     node(int x)
// //     {
// //         this->data = x;
// //         this->left = NULL;
// //         this->right = NULL;
// //     }
// // };

// // class Pair
// // {
// // public:
// //     node *Node;
// //     int state;

// // public:
// //     Pair(node *x, int y)
// //     {
// //         this->Node = x;
// //         this->state = y;
// //     }
// // };

// // int height(node *Node)
// // {
// //     if (Node == NULL)
// //     {
// //         return -1;
// //     }
// //     int ht = -1;
// //     int lh = height(Node->left);
// //     int rh = height(Node->right);
// //     ht = max(lh, rh) + 1;
// //     return ht;
// // }
// // int diameter(node *Node)
// // {
// //     if (Node == NULL)
// //     {
// //         return 0;
// //     }
// //     int ld = diameter(Node->left);
// //     int rd = diameter(Node->right);

// //     int f = height(Node->left) + height(Node->right) + 2;
// //     int dia = max(f, max(ld, rd));
// //     return dia;
// // }

// // int main()
// // {
// //     int n, find, k;
// //     cin >> n;
// //     int arr[n];
// //     string str;
// //     for (int i = 0; i < n; i++)
// //     {
// //         cin >> str;
// //         if (str != "n")
// //         {
// //             int myint1 = stoi(str);
// //             arr[i] = myint1;
// //         }
// //         else
// //         {
// //             arr[i] = -1;
// //         }
// //     }

// //     node *root = new node(arr[0]);
// //     Pair *t = new Pair(root, 1);
// //     stack<Pair *> st;
// //     st.push(t);
// //     int idx = 0;
// //     while (st.size() > 0)
// //     {
// //         Pair *top = st.top();
// //         if (top->state == 1)
// //         {
// //             idx++;
// //             if (arr[idx] != -1)
// //             {

// //                 node *curr = new node(arr[idx]);
// //                 top->Node->left = curr;
// //                 Pair *lp = new Pair(curr, 1);
// //                 st.push(lp);
// //             }
// //             else
// //             {

// //                 top->Node->left = NULL;
// //             }
// //             (*top).state += 1;
// //         }

// //         else if (top->state == 2)
// //         {
// //             idx++;
// //             if (arr[idx] != -1)
// //             {

// //                 node *curr = new node(arr[idx]);
// //                 top->Node->right = curr;
// //                 Pair *rp = new Pair(curr, 1);
// //                 st.push(rp);
// //             }
// //             else
// //             {

// //                 top->Node->right = NULL;
// //             }
// //             (*top).state += 1;
// //         }
// //         else
// //         {
// //             st.pop();
// //         }
// //     }

// //     cout << diameter(root);
// // }
// #include <bits/stdc++.h>
// using namespace std;

// class node
// {
// public:
//     int data;
//     node *left;
//     node *right;

// public:
//     node(int x)
//     {
//         this->data = x;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// class Pair
// {
// public:
//     node *Node;
//     int state;

// public:
//     Pair(node *x, int y)
//     {
//         this->Node = x;
//         this->state = y;
//     }
// };

// class diapair
// {
// public:
//     int dia;
//     int ht;
// };

// diapair *diameter(node *Node)
// {
//     if (Node == NULL)
//     {
//         diapair *rp = new diapair;
//         rp->dia = 0;
//         rp->ht = -1;

//         return (rp);
//     }
//     diapair *ld = diameter(Node->left);
//     diapair *rd = diameter(Node->right);

//     diapair *mydia = new diapair;
//     mydia->ht = max(ld->ht, rd->ht) + 1;
//     int fes = ld->ht + rd->ht + 2;

//     mydia->dia = max(fes, max(ld->dia, rd->dia));
//     return (mydia);
// }

// int main()
// {
//     int n, find, k;
//     cin >> n;
//     int arr[n];
//     string str;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> str;
//         if (str != "n")
//         {
//             int myint1 = stoi(str);
//             arr[i] = myint1;
//         }
//         else
//         {
//             arr[i] = -1;
//         }
//     }

//     node *root = new node(arr[0]);
//     Pair *t = new Pair(root, 1);
//     stack<Pair *> st;
//     st.push(t);
//     int idx = 0;
//     while (st.size() > 0)
//     {
//         Pair *top = st.top();
//         if (top->state == 1)
//         {
//             idx++;
//             if (arr[idx] != -1)
//             {

//                 node *curr = new node(arr[idx]);
//                 top->Node->left = curr;
//                 Pair *lp = new Pair(curr, 1);
//                 st.push(lp);
//             }
//             else
//             {

//                 top->Node->left = NULL;
//             }
//             (*top).state += 1;
//         }

//         else if (top->state == 2)
//         {
//             idx++;
//             if (arr[idx] != -1)
//             {

//                 node *curr = new node(arr[idx]);
//                 top->Node->right = curr;
//                 Pair *rp = new Pair(curr, 1);
//                 st.push(rp);
//             }
//             else
//             {

//                 top->Node->right = NULL;
//             }
//             (*top).state += 1;
//         }
//         else
//         {
//             st.pop();
//         }
//     }

//     diapair *ans = diameter(root);
//     cout << ans->dia;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class node
// {
// public:
//     int data;
//     node *left;
//     node *right;

// public:
//     node(int x)
//     {
//         this->data = x;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// class Pair
// {
// public:
//     node *Node;
//     int state;

// public:
//     Pair(node *x, int y)
//     {
//         this->Node = x;
//         this->state = y;
//     }
// };

// class diapair
// {
// public:
//     int dia;
//     int ht;
// };

// diapair diameter(node *Node)
// {
//     if (Node == NULL)
//     {
//         diapair rp;
//         rp.dia = 0;
//         rp.ht = -1;

//         return rp;
//     }
//     diapair ld = diameter(Node->left);
//     diapair rd = diameter(Node->right);

//     diapair mydia;
//     mydia.ht = max(ld.ht, rd.ht) + 1;
//     int fes = ld.ht + rd.ht + 2;

//     mydia.dia = max(fes, max(ld.dia, rd.dia));
//     return mydia;
// }

// int main()
// {
//     int n, find, k;
//     cin >> n;
//     int arr[n];
//     string str;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> str;
//         if (str != "n")
//         {
//             int myint1 = stoi(str);
//             arr[i] = myint1;
//         }
//         else
//         {
//             arr[i] = -1;
//         }
//     }

//     node *root = new node(arr[0]);
//     Pair *t = new Pair(root, 1);
//     stack<Pair *> st;
//     st.push(t);
//     int idx = 0;
//     while (st.size() > 0)
//     {
//         Pair *top = st.top();
//         if (top->state == 1)
//         {
//             idx++;
//             if (arr[idx] != -1)
//             {

//                 node *curr = new node(arr[idx]);
//                 top->Node->left = curr;
//                 Pair *lp = new Pair(curr, 1);
//                 st.push(lp);
//             }
//             else
//             {

//                 top->Node->left = NULL;
//             }
//             (*top).state += 1;
//         }

//         else if (top->state == 2)
//         {
//             idx++;
//             if (arr[idx] != -1)
//             {

//                 node *curr = new node(arr[idx]);
//                 top->Node->right = curr;
//                 Pair *rp = new Pair(curr, 1);
//                 st.push(rp);
//             }
//             else
//             {

//                 top->Node->right = NULL;
//             }
//             (*top).state += 1;
//         }
//         else
//         {
//             st.pop();
//         }
//     }

//     diapair ans = diameter(root);
//     cout << ans.dia;
// }
