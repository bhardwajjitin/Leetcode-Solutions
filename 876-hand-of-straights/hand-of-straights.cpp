class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
         set<int>ml;
         if(hand.size()%groupSize!=0)return false;
         unordered_map<int,int>umap;
         for(int i=0;i<hand.size();i++){
            ml.insert(hand[i]);
            umap[hand[i]]++;
         }
         int k=groupSize;
         while(!ml.empty()){
            int top=*ml.begin();
            umap[top]--;
            if(umap[top]==0){
                ml.erase(top);
                umap.erase(top);
            }
            k-=1;
            while(!ml.empty() && k!=0){
            if(ml.find(top+1)!=ml.end()){
                umap[top+1]--;
                if(umap[top+1]==0){
                    ml.erase(top+1);
                    umap.erase(top+1);
                }
                top++;
            }
            else{
                return false;
            }
            k--;
            }
            k=groupSize;
         }
         return true;
    }
};