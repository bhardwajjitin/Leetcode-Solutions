class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        int temp=x;
        set<pair<int,int>>st;
        st.insert({0,temp});
        unordered_map<int,int>mp;
        while(!st.empty()){
          auto it=*st.begin();
          st.erase(*st.begin());
          int steps=it.first;
          int t=it.second;
          if(t==y)return steps;
          if(t%11==0){
            st.insert({steps+1,t/11});
          }
          if(t%5==0){
            st.insert({steps+1,t/5});
          }
          if(mp.find(t-1)==mp.end()){
          st.insert({steps+1,t-1});
          mp[t-1]++;
          }
          if(mp.find(t+1)==mp.end()){
          st.insert({steps+1,t+1});
          mp[t+1]++;
          }
        }
        return -1;
    }
};