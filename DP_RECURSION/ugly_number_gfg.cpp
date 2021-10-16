	// ull getNthUglyNo(int n) {
	//   unsigned long long int dp[n+1];
	//    dp[0]=1;
	//   unsigned long long  int curr;
	//    int i2=0,i3=0,i5=0;
	//    for(int i=1;i<n;i++){
	//       curr=min(dp[i2]*2,min(dp[i3]*3,dp[i5]*5)); 
	//       dp[i]=curr;
	//       if(dp[i2]*2==curr){
	//           i2+=1;
	//       }
	//        if(dp[i3]*3==curr){
	//           i3+=1;
	//       }
	//         if(dp[i5]*5==curr){
	//           i5+=1;
	//       }
	//    }
	//    return curr;
	// }