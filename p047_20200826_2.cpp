//move the current working int to the end
//compare the next one to the previous current one, if the same, skip

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        dfs(nums,nums.size(),res);
        return res;
    }
    
    void dfs(vector<int> nums,int l,vector<vector<int>> &res){
        if(l==1) res.push_back(nums);
        
        for(int j = l-1;j>=0;j--){
            if(j<l-1 && nums[l-1] == nums[j]) continue; 
            swap(nums[l-1],nums[j]);
            dfs(nums,l-1,res);
        }
    }
};