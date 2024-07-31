class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>ans;
        for(int i=lo;i<=hi;i++){
            set<pair<int,int>>st;
            st.insert({0,i});
            while(true){
                auto it=*st.begin();
                st.erase(*st.begin());
                int step=it.first;
                int val=it.second;
                if(val==1){
                    ans.push_back({step,i});
                    break;
                }
                if(val%2==0){
                    st.insert({step+1,val/2});
                }
                else{
                    st.insert({step+1,3*val+1});
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans[k-1].second;
    }
};