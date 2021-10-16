// class Solution{
// public:	
// 	int longSubarrWthSumDivByK(int arr[], int n, int k)
// 	{
// 	    unordered_map<int, int> fre;
// 	    int sum=0;
// 	    int length=0;
// 	    for(int i=0;i<n;i++){
// 	        sum+=arr[i];
// 	        int m=((sum % k) + k) % k;
// 	        if(m==0){
// 	            length=i+1;
// 	        }
// 	        if (fre.find(m) == fre.end()) {
//             fre[m] = i;
// 	        }
// 	        else {
// 	            if(length<i-fre[m])
// 	                        length=i-fre[m];
// 	        }
// 	    }
// 	    return length;
// 	}
// };