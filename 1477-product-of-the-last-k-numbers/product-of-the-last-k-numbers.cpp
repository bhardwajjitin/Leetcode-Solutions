class ProductOfNumbers {
public:
    vector<int>ans;
    vector<int>pre;
    ProductOfNumbers() {
      pre.resize(1e5);
      pre[0]=1;
    }
    
    void add(int num) {
        ans.push_back(num);
        for(int i=ans.size();i>=1;i--){
            pre[i]=pre[i-1]*num;
        }
    }
    
    int getProduct(int k) {
        int res=pre[k];
        return res;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */