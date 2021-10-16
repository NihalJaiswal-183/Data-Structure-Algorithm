  bool isSubsetSum(int arr[], int n, int sum) 
{ 
    bool subset[n + 1][sum + 1]; 
  
    for (int i = 0; i <= n; i++) 
        subset[i][0] = true; 
  
    for (int i = 1; i <= sum; i++) 
        subset[0][i] = false; 
  
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= sum; j++) { 
            if (j < arr[i - 1]) 
                subset[i][j] = subset[i - 1][j]; 
            if (j >= arr[i - 1]) 
                subset[i][j] = subset[i - 1][j] 
                               || subset[i - 1][j - arr[i - 1]]; 
        } 
    }
    return subset[n][sum];
}
int equalPartition(int N, int arr[])
    {
     int sum=0;
     for(int i=0;i<N;i++)
     sum+=arr[i];
     bool ans;
     if(sum%2==0){
     sum=sum/2;
     ans= isSubsetSum(arr,N,sum); 
     }
     else{
         ans=false;
     }
      return ans;  
    }