class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        unordered_map<int,int>umap,isskipped;
        int i=0;
        int j=0;
        int cnt=0;
        while(j<arrivals.size()){
            if(j-i+1>w){
                if (isskipped.find(i) == isskipped.end()) {  
                    umap[arrivals[i]]--;
                    if (umap[arrivals[i]] == 0) {
                        umap.erase(arrivals[i]);
                    }
                }
                i++;
            }
            umap[arrivals[j]]++;
            if(umap[arrivals[j]]>m){
                cnt++;
                isskipped[j]++;
                umap[arrivals[j]]--;
            }
            j++;
        }
        return cnt;
    }
};