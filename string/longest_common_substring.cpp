#include <iostream> 
using namespace std; 

string X,Y; 
int lcs(int i, int j, int count) 
{ 
	
	if (i == 0 || j == 0) 
		return count; 
	int countPREV=count;	
	if (X[i-1] == Y[j-1]) { 
		countPREV= lcs(i - 1, j - 1,count+1); 
	} 
		return max(countPREV, max(lcs( i, j - 1,0), lcs( i - 1, j,0))); 

} 
 
int main() 
{ 
int n,m; 
X = "abcdxyz"; 
Y = "xyzabcd"; 
n=X.size(); 
m=Y.size(); 
cout<<lcs(n,m,0); 
} 
