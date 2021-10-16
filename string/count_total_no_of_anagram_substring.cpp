#include<bits/stdc++.h> 
using namespace std; 
  string makeanagram(string &t){
        string key="00000000000000000000000000";
        for(int i=0;i<t.length();i++){
            int m=(int)key[t[i]-'a'];
            m++;
            key[t[i]-'a']=m;
            }
        return key;
    }

int totalanagram(string s){
    unordered_map<string,int> hash;
    int ans=0;
    int p;
    unordered_map<string, int>::iterator itr;
    for(int i=0;i<s.length();i++){
         for(int j=i;j<s.length();j++){
             string t=s.substr(i,j-i+1);
             string key=makeanagram(t);
             hash[key]++;
         }
    }
    for (itr = hash.begin(); itr !=hash.end(); ++itr){
            p=(*itr).second;
             p=p*(p-1)/2;
             ans+=p;
            }
    cout<<ans;
}

int main()
{
        string s;
        cin>>s;
        totalanagram(s);
}