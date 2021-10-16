// #include <bits/stdc++.h>
// using namespace std;
// // brute force 2^n*n^2
// int maxlen = 1;

// void bridgecount(int a1[], int b1[], int n, string asf, int i)
// {

//     if (i == n)
//     {
//         if (asf.length() > 1)
//         {
//             bool flag = true;
//             for (int i = 0; i < asf.length(); i++)
//             {
//                 int in = int(asf[i]) - '0';
//                 for (int j = i + 1; j < asf.length(); j++)
//                 {
//                     int inj = (int)asf[j] - '0';

//                     if (a1[in] > a1[inj])
//                     {

//                         if (b1[in] < b1[inj])
//                         {
//                             flag = false;
//                             break;
//                         }
//                     }
//                     if (a1[in] < a1[inj])
//                     {
//                         if (b1[in] > b1[inj])
//                         {
//                             flag = false;
//                             break;
//                         }
//                     }
//                 }
//             }

//             if (flag)
//                 maxlen = max(maxlen, (int)asf.length());
//         }
//         return;
//     }

//     bridgecount(a1, b1, n, asf + to_string(i), i + 1);
//     bridgecount(a1, b1, n, asf, i + 1);
// }

// int main()
// {
//     int a1[] = {8, 1, 4, 3, 5, 2, 6, 7};
//     int b1[] = {1, 2, 3, 4, 5, 6, 7, 8};

//     bridgecount(a1, b1, 8, "", 0);
//     cout << maxlen;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main(){
    
}
