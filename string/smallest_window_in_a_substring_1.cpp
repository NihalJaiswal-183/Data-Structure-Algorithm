#include<bits/stdc++.h> 
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
       string s1,s2;
       cin>>s1>>s2;
    map<char,int> hash1,hash2;
    int mct=0;
    for(int i=0;i<s2.length();i++){
        hash2[s2[i]]+=1;
        mct++;
    }
    int left=-1;
    int cmt=0;
    int smalllen=0;
    int curlen=0;
    int ri,li;
    bool flag=false;
    for(int right=0;right<s1.length();right++){
        if(cmt<mct){
           hash1[s1[right]]+=1;
           if(hash1[s1[right]]<=hash2[s1[right]])
           cmt++;
        }
        while(left<right &&cmt==mct){
            flag =true;
            curlen=right-left+1;
            if(smalllen==0||curlen<smalllen){
                ri=right;
                li=left+1;
                smalllen=curlen;
            }
            left++;
            if(hash1[s1[left]]==1){
                hash1.erase(s1[left]);
            }
            else{
             hash1[s1[left]]-=1;   
            }
            if(hash1[s1[left]]<hash2[s1[left]])
            cmt--;
        }
        
    }
    if(flag){
     string r = s1.substr(li,ri-li+1);
     cout<<r<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
        
    }
}