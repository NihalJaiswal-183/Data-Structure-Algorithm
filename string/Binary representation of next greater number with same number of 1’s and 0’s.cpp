#include <bits/stdc++.h> 
using namespace std; 
string nextGreaterWithSameDigits(string bnum) 
{ 
	int l = bnum.size(); 
	int i; 
	for (int i=l-2; i>=1; i--) 
	{ 
		if (bnum.at(i) == '0' && 
		bnum.at(i+1) == '1') 
		{ 
			char ch = bnum.at(i); 
			bnum.at(i) = bnum.at(i+1); 
			bnum.at(i+1) = ch; 
			break; 
		} 
	} 

	if (i == 0) 
		"no greater number"; 
	int j = i+2, k = l-1; 
	while (j < k) 
	{ 
		if (bnum.at(j) == '1' && bnum.at(k) == '0') 
		{ 
			char ch = bnum.at(j); 
			bnum.at(j) = bnum.at(k); 
			bnum.at(k) = ch; 
			j++; 
			k--; 
		} 
		else if (bnum.at(i) == '0') 
			break; 

		else
			j++; 

	} 
	return bnum; 
} 
int main() 
{ 
	string bnum = "10010"; 
	cout << "Binary representation of next greater number = "
		<< nextGreaterWithSameDigits(bnum); 
	return 0; 
} 
