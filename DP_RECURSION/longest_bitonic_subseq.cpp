// int LongestBitonicSequence(vector<int> nums)
// {
//     int n = nums.size();
//     int dplis[n];
//     dplis[0] = 1;
//     int maxlen;
//     for (int i = 1; i < nums.size(); i++)
//     {
//         maxlen = 0;
//         for (int j = i - 1; j >= 0; j--)
//         {

//             if (nums[j] < nums[i])
//                 maxlen = max(maxlen, dplis[j]);
//         }
//         dplis[i] = maxlen + 1;
//     }
//     int dplds[n];

//     dplds[n - 1] = 1;
//     for (int i = n - 2; i >= 0; i--)
//     {
//         maxlen = 0;
//         for (int j = i + 1; j < n; j++)
//         {

//             if (nums[j] < nums[i])
//                 maxlen = max(maxlen, dplds[j]);
//         }
//         dplds[i] = maxlen + 1;
//     }
    // int maxv = INT_MIN;
    // for (int i = 0; i < n; i++)
    // {
    //     maxv = max(maxv, dplds[i] + dplis[i]);
    // }
    //return maxv - 1;
// }