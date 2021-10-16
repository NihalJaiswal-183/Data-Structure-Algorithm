#include<bits/stdc++.h> 
using namespace std;

void generate(string s,string asf,int n){
    if(n==s.length()){
        cout<<asf<<" ";
        return;
    }
    
    
    if(s[n]=='1'||s[n]=='0')
    generate(s,asf+s[n],n+1);
    else{
            generate(s,asf+'0',n+1);
            generate(s,asf+'1',n+1);
    }
    
}



int main(){
    int t;
    cin>>t;
    while(t--){
       string s;
       cin>>s;
       int n=s.length();
       generate(s,"",0);
       cout<<endl;
    }
}