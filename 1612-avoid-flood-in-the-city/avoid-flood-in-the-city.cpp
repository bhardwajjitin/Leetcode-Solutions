class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int,int>umap;
        unordered_map<int,vector<int>>index;
    for(int i=0;i<rains.size();i++){
        if(rains[i]!=0){
        umap[rains[i]]++;
        index[rains[i]].push_back(i);
        }
    }
    multiset<pair<pair<int,int>,int>>ml;
    set<int>st;
    vector<int>ans;
    for(int i=0;i<rains.size();i++){
        if(rains[i]!=0){
            umap[rains[i]]--;
            vector<int>res=index[rains[i]];
            int ind=-1;
            if(res.size()>0){
            res.erase(res.begin()+0);
            if(res.size()>0)ind=res[0];
            }
            if(st.find(rains[i])!=st.end())return {};
            st.insert(rains[i]);
            if(umap[rains[i]]>0){
            ml.insert({{ind,umap[rains[i]]},rains[i]});
            }
            ans.push_back(-1);
        }
        else{
           if(ml.size()==0)ans.push_back(1);
           else{
            auto it=*ml.begin();
            int node=it.second;
            ans.push_back(node);
            ml.erase(*ml.begin());
            st.erase(node);
           }
        }
    }
    return ans;
    }
};