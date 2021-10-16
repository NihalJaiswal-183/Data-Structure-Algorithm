#include<bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int length,li,ri;
	    int maxlen=INT_MIN;
	    int left,right;
	    for(int i=1;i<s.length();i++){
	        if(s[i]==s[i-1]){
	       left=i-1;
	       right=i;
	        while( left>=0&&right<s.length() &&s[right]==s[left]){
	            length=right-left+1;
	            if(maxlen<length){
	                li=left;
	                ri=right;
	                maxlen=length;
	            }
	            left--;
	            right++;
	         }
	        }
	        if(s[i]==s[i+1]){
	       left=i;
	       right=i+1;
	        while( left>=0&&right<s.length() &&s[right]==s[left]){
	            length=right-left+1;
	            if(maxlen<length){
	                li=left;
	                ri=right;
	                maxlen=length;
	            }
	            left--;
	            right++;
	          }
	        }
	         left=i-1;
	        right=i+1;
	        while( left>=0&&right<s.length() &&s[right]==s[left]){
	            length=right-left+1;
	            if(maxlen<length){
	                li=left;
	                ri=right;
	                maxlen=length;
	            }
	            left--;
	            right++;
	            }
	    }
	        if(maxlen>1){
	        for (int i = li; i <= ri; ++i) 
        cout << s[i]; 
	        }
	        else{
	            cout<<s[0];
	        }
	        cout<<endl;
	        
	    }
}