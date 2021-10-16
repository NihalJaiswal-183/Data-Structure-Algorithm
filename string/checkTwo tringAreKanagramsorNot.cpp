// // Optimized C++ program to check if two strings 
// // are k anagram or not. 
// #include<bits/stdc++.h> 
// using namespace std; 

// const int MAX_CHAR = 26; 

// // Function to check if str1 and str2 are k-anagram 
// // or not 
// bool areKAnagrams(string str1, string str2, int k) 
// { 
// 	// If both strings are not of equal 
// 	// length then return false 
// 	int n = str1.length(); 
// 	if (str2.length() != n) 
// 		return false; 

// 	int hash_str1[MAX_CHAR] = {0}; 

// 	// Store the occurrence of all characters 
// 	// in a hash_array 
// 	for (int i = 0; i < n ; i++) 
// 		hash_str1[str1[i]-'a']++; 

// 	// Store the occurrence of all characters 
// 	// in a hash_array 
// 	int count = 0; 
// 	for (int i = 0; i < n ; i++) 
// 	{ 
// 		if (hash_str1[str2[i]-'a'] > 0) 
// 			hash_str1[str2[i]-'a']--; 
// 		else
// 			count++; 

// 		if (count > k) 
// 			return false; 
// 	} 

// 	// Return true if count is less than or 
// 	// equal to k 
// 	return true; 
// } 

// // Driver code 
// int main() 
// { 
// 	string str1 = "fodr"; 
// 	string str2 = "gork"; 
// 	int k = 2; 
// 	if (areKAnagrams(str1, str2, k) == true) 
// 		cout << "Yes"; 
// 	else
// 		cout << "No"; 
// 	return 0; 
// } 
