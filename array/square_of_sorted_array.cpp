// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& A) {
//         int i=0;
//         int j=A.size()-1;
//         vector<int> ans;
//         while(i<j){
//             if(A[i]*A[i]>A[j]*A[j]){
//                ans.push_back(A[i]*A[i]);
//                 i++;
//             }
//             else{
//                 ans.push_back(A[j]*A[j]);
//                 j--;
//             }
//         }
//         ans.push_back(A[j]*A[j]);
        
//         reverse(ans.begin(), ans.end());
//         return ans;   
//     }
// };