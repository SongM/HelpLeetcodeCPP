class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.size()<2) return(nums.size());
        unordered_map<int,int> m;
        for (int i=0;i<nums.size();i++) m[nums[i]] = 1;
        int res = 1;
        for (auto n:nums)
        {
            if (m[n]==0) continue;
            while(m.find(n+m[n])!=m.end())
            {
                int t=n+m[n];
                m[n]+=m[t];
                m[t] = 0;
            }
            if (res<m[n]) res = m[n];
        }
        return(res);

    }
};