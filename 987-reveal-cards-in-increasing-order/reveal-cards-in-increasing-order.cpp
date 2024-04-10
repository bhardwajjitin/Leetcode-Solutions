class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        vector<int>res(2*n-1,0);
        sort(deck.begin(),deck.end());
        for(int i=0;i<n;i++){
            res[2*i]=deck[i];
        }
        int i=res.size()-1;
        while(i!=0){
            int j=i;
            while(j>0 && res[j]!=0){
                j--;
            }
            if(j>0)
            res[j]=res[i];
            i--;
        }
        vector<int>ans(n);
        for(int i=0;i<deck.size();i++){
            ans[i]=res[i];
        }
        return ans;
    }
};