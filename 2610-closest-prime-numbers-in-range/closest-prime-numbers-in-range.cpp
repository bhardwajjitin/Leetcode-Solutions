class Solution {
    bool isprime(int number) {
        if (number <= 1)
            return false;
        if (number == 2 || number == 3)
            return true;
        if (number % 2 == 0 || number % 3 == 0)
            return false;
        int limit = sqrt(number);
        for (int i = 5; i <= limit; i += 6) {
            if (number % i == 0 || number % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }

public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> myprimes;
        for (int range = left; range <= right; range++) {
            if (isprime(range)) {
                myprimes.push_back(range);
            }
        }
        if(myprimes.size()<2)return {-1,-1};
        int mindiff=INT_MAX;
        vector<int>ans;
        for(int i=1;i<myprimes.size();i++){
            int currdiff=myprimes[i]-myprimes[i-1];
            if(currdiff<mindiff){
                mindiff=currdiff;
                ans={myprimes[i-1],myprimes[i]};
            }
        }
        return ans;
    }
};