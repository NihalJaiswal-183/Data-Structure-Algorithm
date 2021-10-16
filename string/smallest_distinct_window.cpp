#include<bits/stdc++.h> 
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
       string s;
       cin>>s;
       int left=-1; 
       int windowlength=0;
       int min_length=INT_MAX;
       unordered_map<char, int> hash_map;
       set <char> s1;
          for(int right=0;right<s.length();right++){
              s1.insert(s[right]);
          }
          // cout<<s1.size()<<endl;
       for(int right=0;right<s.length();right++){
           if(hash_map.size()<s1.size()){
               
               hash_map[s[right]]+=1;
           }
           
               while(left<right &&hash_map.size()==s1.size()){
                   windowlength=right-left;
                   if(min_length>windowlength){
                       min_length=windowlength;
                   }
                   left++;
                   if(hash_map[s[left]]==1){
                       hash_map.erase(s[left]);
                   }
                   else{
                   hash_map[s[left]]-=1;
                      }
                  }
    }
           cout<<min_length<<endl;
    }
}