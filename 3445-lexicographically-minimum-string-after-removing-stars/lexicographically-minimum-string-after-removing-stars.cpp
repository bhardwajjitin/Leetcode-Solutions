class comp{
    public:
    bool operator()(const pair<char,int>&a,const pair<char,int>&b){
        if(a.first==b.first)return a.second<b.second;
        return a.first>b.first;
    }
};
class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,comp>pq;
        string temp="";
        unordered_map<int,int>umap;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch!='*'){
                pq.push({ch,i});
            }
            else{
                if(pq.size()>0){
                int ind=pq.top().second;
                pq.pop();
                umap[ind]++;
                umap[i]++;
                }
            }
        }
        for(int i=0;i<s.size();i++){
            if(umap.find(i)!=umap.end())continue;
            else{
                temp+=s[i];
            }
        }
        return temp;
    }
};