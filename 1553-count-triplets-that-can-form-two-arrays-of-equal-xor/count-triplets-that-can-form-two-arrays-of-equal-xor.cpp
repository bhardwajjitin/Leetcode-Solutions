class Solution {
public:
    int countTriplets(vector<int>& arr) {
      int cnt=0;
      int n=arr.size();
        for(int i=0;i<n-1;i++){
          int a=arr[i];
          for(int j=i+1;j<n;j++){
            int b=0;
            for(int k=j;k<n;k++){
                b^=arr[k];
                if(a==b)cnt++;
            }
            a^=arr[j];
          }
        }
        return cnt;
    }
};