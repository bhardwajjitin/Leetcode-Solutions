class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(),sat.end());
        int maxi=0;
        int i=0;
        int j=sat.size()-1;
        while(i<=j){
            int sum=0;
            int time=1;
            for(int k=i;k<=j;k++){
                sum+=(sat[k]*time);
                time++;
            }
            maxi=max(maxi,sum);
            i++;
        }
        return maxi;
    }
};