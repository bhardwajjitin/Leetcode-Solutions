class Solution {
    private:
    bool check(int mid,vector<int>arr,int n){
        int i=0;
        int cnt=0;
        while(i<arr.size()){
           cnt+=arr[i]/mid;
           if(arr[i]%mid>0){
            cnt+=1;
           }
           i++;
        }
        return cnt<=n;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        sort(quantities.begin(),quantities.end());
        int low=1;
        int high=quantities[quantities.size()-1];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,quantities,n)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};