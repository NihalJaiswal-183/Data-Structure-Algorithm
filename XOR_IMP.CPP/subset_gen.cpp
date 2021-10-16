#include <bits/stdc++.h> 
using namespace std; 

 
const int N = 1e5 + 10;
const int MAX_A = 70;
const int TOTAL_PRIMES = 19;
const int MOD = 1e9 + 7;
const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

int main(){
 int n;
 cin>>n;
 int a[n];
 for(int i=0;i<n;i++){
     cin>>a[i];
 }
//  creating a mask for each element of array of 19 size
 int mask[n]={0};
 for (int i = 1; i <= MAX_A; i++) {
		for (int p = 0; p < TOTAL_PRIMES; p++) {
			int cnt = 0;
			int at = i;
 
			while (at % primes[p] == 0) {
				at /= primes[p];
				cnt++;
			}
 
			if (cnt & 1) mask[i] |= (1 << p);
		}
	}

    
}