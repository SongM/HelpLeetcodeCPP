class Solution {
public:
    // unordered_map<int,vector<int>> m;
    vector<int> data;
    Solution(vector<int>& nums) {
        data = nums;
    }
    
    int pick(int target) {
        vector<int> ind;
        for (int i=0;i<data.size();i++)
            if(data[i]==target) ind.push_back(i);

        return(ind[rand()%ind.size()]);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */