class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>umap;
        for(int i=0;i<bills.size();i++){
          if(bills[i]==5){
            umap[5]++;
          }
          else if(bills[i]==10){
            if(umap[5]==0)return false;
            umap[5]--;
            umap[10]++;
            if(umap[5]==0){
              umap.erase(5);
            }
          }
          else{
            if(umap[5]==0)return false;
            if(umap[10]==0 && umap[5]*5<15)return false;
            if(umap[10]==0 && umap[5]*5>=15){
                umap[5]-=3;
            }
            else{
            umap[5]--;
            umap[10]--;
            }
            umap[20]++;
            if(umap[5]==0){
              umap.erase(5);
            }
            if(umap[10]==0){
              umap.erase(10);
            }
          }
        }
        return true;
    }
};