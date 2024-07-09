class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long starttime=0;
        long long ans=0;
        for(int i=0;i<customers.size();i++){
          int arrival=customers[i][0];
          int delay=customers[i][1];
          if(arrival>=starttime){
            ans+=delay;
            starttime=delay+arrival;
          }
          else{
            ans+=starttime-arrival+delay;
            starttime+=delay;
          }
        }
        return (double)ans/customers.size();
    }
};