class KthLargest {
public:
    int cnt;
    priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        for(auto it:nums){
            pq.push(it);
            if(pq.size()>k)pq.pop();
        }
        cnt=k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>cnt)pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */