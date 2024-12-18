class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>ans(prices.size());
        ans[prices.size()-1]=prices[prices.size()-1];
        for(int i=0;i<prices.size()-1;i++){
            int ind=-1;
            for(int j=i+1;j<prices.size();j++){
                if(prices[j]<=prices[i]){
                    ind=j;
                    break;
                }
            }
            if(ind!=-1){
                ans[i]=prices[i]-prices[ind];
            }
            else{
                ans[i]=prices[i];
            }
        }
        return ans;
    }
};