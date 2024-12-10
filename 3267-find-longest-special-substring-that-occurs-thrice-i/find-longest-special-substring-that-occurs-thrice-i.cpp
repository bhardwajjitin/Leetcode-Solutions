class Solution {
    private:
    bool solve(string&temp){
        for(int i=1;i<temp.size();i++){
            if(temp[i]!=temp[i-1])return false;
        }
        return true;
    }
    bool check(int length,string s){
      
       for(int i=0;i<s.size()-length;i++){
         unordered_map<string,int>umap;
           int k=i;
           int j=i;
           string temp="";
           while(j<s.size()){
             temp+=s[j];
             if(j-k+1<length){
                j++;
             }
             else if(j-k+1==length){
                if(solve(temp)){
                umap[temp]++;
                if(umap[temp]>=3){
                    return true; 
                }
                }
                temp.erase(temp.begin()+0);
                k++;
                j++;
             }
           }
       }
       return false;
    }
public:
    int maximumLength(string s) {
        int low=1,high=s.size()-2;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,s)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};