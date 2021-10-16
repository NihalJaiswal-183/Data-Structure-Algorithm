#include<bits/stdc++.h> 
using namespace std; 

int main()
{
        string s;
        string a="";
        cin>>s;
        int odd=0;
        char oddchar;
        
        map<char,int> hashmap1,hashmap2;
         map<char, int>::iterator itr;
        for(int i=0;i<s.length();i++){
            hashmap1[s[i]]+=1;
        }
        for (itr = hashmap1.begin(); itr !=hashmap1.end(); ++itr){
            if((*itr).second%2==1){
                odd++;
            }
        }
        if(odd>1){
            cout<<"no palindromic string is possible";
        }
        else{
        for (itr = hashmap1.begin(); itr != hashmap1.end(); ++itr){
            if((*itr).second%2==1){
                (*itr).second-=1;
                oddchar=(*itr).first;
            }
         hashmap2[(*itr).first]=(*itr).second/2;   
        }
        for (itr = hashmap2.begin(); itr != hashmap2.end(); ++itr){
             while((*itr).second>0){
                 a=a+(*itr).first;
                 (*itr).second--;
             }
            
            }
            if(odd){
                a=a+oddchar;
            }
            if(a.length()%2==0){
                for(int i=a.length()-1;i>=0;i++){
                    a=a+a[i];
                }
            }
            else{
                for(int i=a.length()-2;i>=0;i--){
                    a=a+a[i];
                }
            }
            
        cout<<a<<endl;
        }
    
}