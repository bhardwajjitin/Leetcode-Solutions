class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans=0;
        int n=rating.size();
        unordered_map<int,int>larger,smaller;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(rating[j]>rating[i])larger[rating[i]]++;
                else smaller[rating[i]]++;
            }
        }
        for(int i=0;i<n-2;i++){
            int currvalue=rating[i];
           
            for(int j=i+1;j<n-1;j++){
                int presvalue=rating[j];
                bool incflag=false,decflag=false;
                if(currvalue<presvalue){
                    incflag=true;
                }
                if(currvalue>presvalue){
                    decflag=true;
                }
                if(incflag)ans+=larger[presvalue];
                if(decflag)ans+=smaller[presvalue];
                }
            }
        return ans;
    }
};