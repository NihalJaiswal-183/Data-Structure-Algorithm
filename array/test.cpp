#include <bits/stdc++.h> 
using namespace std;

void printPermutation(string s,string asf){
    
    if(s.length()==0){
        cout<<asf<<endl;
        return;
    }
    
    for(int i=0;i<s.length();i++){
        char a=s[i];
        string leftpart = s.substr(0, i);
        string rightpart = s.substr(i+1);
        string newstring =leftpart+rightpart;
        printPermutation(newstring,asf+a);
        
        
    }
    
    
    
} 



int main() {
    
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    printPermutation(s,"");
	   
}
}