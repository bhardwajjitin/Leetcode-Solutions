class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        long long sum=0;
        if(units[0].size()==1){
            for(int i=0;i<units.size();i++){
                sum+=units[i][0];
            }
            return sum;
        }
        int second_min=INT_MAX,smallest_ele=INT_MAX;
        for(int i=0;i<units.size();i++){
            sort(units[i].begin(),units[i].end());
            second_min=min(second_min,units[i][1]);
            smallest_ele=min(smallest_ele,units[i][0]);

            sum+=units[i][1];
        }

        return sum-second_min+smallest_ele;
    }
};