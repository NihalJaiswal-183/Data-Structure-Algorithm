// class Solution {
// public:
//     bool wordPattern(string pattern, string s) {
//         vector<string>words;
//         int n = s.length(); 
//             char str[n + 1]; 
//               strcpy(str, s.c_str()); 
//         char *ptr;
//         ptr=strtok(str," ");
//         words.push_back(ptr);
//         while(ptr!=NULL){
//         ptr=strtok(NULL," ");
//             if(ptr!=NULL)
//         words.push_back(ptr);
            
//         }
//         unordered_map<char,string>hash1;
//         unordered_map<string,bool>hash2;
//         if(pattern.length()!=words.size())
//             return false;
//         for(int i=0;i<pattern.length();i++){
//             if(hash1.find(pattern[i])==hash1.end()){
//                 if(hash2.find(words[i])==hash2.end()){
//                 hash1[pattern[i]]=words[i];
//                 hash2[words[i]]=true;
//                 }
//                 else{
//                     return false;
//                 }
//             }
//             else{
//                 if(hash1[pattern[i]]!=words[i])
//                     return false;
//             }
//         }
//         return true;
        
//     }
// };