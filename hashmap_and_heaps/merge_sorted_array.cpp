// #include <bits/stdc++.h>
// using namespace std;

// class pair{
// public:
// int li,di,val;
// public:
//  pair(int x,int y,int z)
// {
//     this->li=x;
//     this->di= y;
//     this->val=z;
// }
// };
// struct CustomCompare
// {
//     bool operator()(const int& lhs, const int& rhs)
//     {
//         return lhs < rhs;
//     }
// };


// int main()
// {
//    int n,size,val;
//    cin>>n;
//    vector<int> ans;
//    vector<vector<int>>list;
//    for(int i=0;i<n;i++){
//        cin>>size;
//        for(int j=0;j<size;j++){
//            cin>>val;
//            list[i].push_back(val);
//        }
      

//     priority_queue<pair, vector<pair>, decltype(comp)> pq(comp);
//         //priority_queue<pair> pq;
//            for(int i=0;i<n;i++){
//                pq.push(pair(i,0,list[i][0]));
//            }
//            while(pq.size()>0){
//                pair temp;
//                temp=pq.top();
//                ans.push_back(temp.val);
//                temp.di++;
//                pq.pop();
//                if(temp.di<list[temp.li].size()){
//                    pq.push(pair(temp.li,temp.di,list[temp.li][temp.di]));
//                }
//            }
//            for(int i=0;i<ans.sizze();i++){
//                cout<<ans[i]<<endl;
//            }
//    }

