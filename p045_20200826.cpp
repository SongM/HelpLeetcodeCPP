class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size()==1) return(0);
        vector<int> v;
        v.push_back(nums.size()-1);
        nums.back() = 0;
        for (int i=nums.size()-2;i>=0;i--)
        {
            if (nums[i]==0) 
            {
                nums[i] = nums.size();
                continue;
            }
            if (nums[i]<v.size())
            {
                int t_res = nums[i+1];
                for (int j=2;j<=nums[i];j++)
                {
                    if (t_res>nums[i+j]) t_res = nums[i+j];
                }
                nums[i] = t_res+1;
                if (nums[i]==v.size()) v.push_back(i);
                else if(nums[i]<nums.size()) v[nums[i]] = i;
            }
            else
            {
                for (int j=0;j<v.size();j++)
                {
                    if (i+nums[i]>=v[j])
                    {
                        if (j+1>=v.size()) v.push_back(i);
                        else v[j+1] = i;
                        nums[i] = j+1;
                        break;
                    }
                }
            }
        }
        return(nums[0]);
    }
};