class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long evensum=1,oddsum=0;
        long long currsum=0;
        long long answer=0;
        for(int i=0;i<arr.size();i++){
            currsum+=arr[i];
            if(currsum%2==0){
                answer=(answer+oddsum)%1000000007;
                evensum++;
            }
            else{
                answer=(answer+evensum)%1000000007;
                oddsum++;
            }
        }
        return answer;
    }
};