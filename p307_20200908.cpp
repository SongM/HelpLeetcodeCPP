class NumArray {
public:
    vector<int> data;
    NumArray(vector<int>& nums) {
        data.push_back(0);
        for (auto n:nums) data.push_back(data.back()+n);
    }
    
    void update(int i, int val) {
        int diff = val-sumRange(i,i);
        cout<<diff;
        // for (auto n:data) cout<<n<<",";cout<<endl;
        i++;
        while(i<data.size())
            data[i++] += diff;
        // for (auto n:data) cout<<n<<",";cout<<endl;
    }
    
    int sumRange(int i, int j) {
        return(data[j+1]-data[i]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */