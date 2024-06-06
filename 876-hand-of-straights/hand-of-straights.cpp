class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        multiset<int>ml;
        for(auto it:hand){
            ml.insert(it);
        }
        while(!ml.empty()){
          int node=*ml.begin();
          auto it=ml.find(node);
          if(it!=ml.end()){
            ml.erase(it);
          } 
          int cnt=1;
          while(cnt<groupSize){
            auto it=ml.find(node+1);
            if(it==ml.end())return false;
            if(it!=ml.end()){
              ml.erase(it);
              node++;
              cnt++;
            }
          }
        }
        return true;
    }
};