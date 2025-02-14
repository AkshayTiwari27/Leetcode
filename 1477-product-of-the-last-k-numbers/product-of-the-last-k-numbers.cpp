class ProductOfNumbers {
public:
    vector<int>nums;
    int n;
    ProductOfNumbers() {
        nums.clear();
        n=0;
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int n=nums.size();
        int ans=1;
        for(int i=n-k;i<n;i++){
            ans*= nums[i];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */