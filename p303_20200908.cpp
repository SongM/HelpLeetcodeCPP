class NumArray {
public:
    vector<int> data;
    NumArray(vector<int>& nums) {
        data.push_back(0);
        for (int n:nums)
            data.push_back(data.back()+n);
        
    }
    
    int sumRange(int i, int j) {
        return(data[j+1]-data[i]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */