// class Solution {
// public:
    // string makeanagram(string &t){
    //     string key="00000000000000000000000000";
    //     for(int i=0;i<t.length();i++){
    //         int m=(int)key[t[i]-'a'];
    //         m++;
    //         key[t[i]-'a']=m;
    //         }
    //     return key;
        
    // }
    
    
    
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map <string, vector <string>>Hash;
//         for(int i=0;i<strs.size();i++){
            
//          string key=makeanagram(strs[i]);
//               Hash[key].push_back(strs[i]);
            
//         }
//         vector<vector<string>> res;
//        for (auto it = Hash.begin(); it!=Hash.end(); it++) 
//        {
//            res.push_back((*it).second);
//        }
//         return res;
//     }
// };