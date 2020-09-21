class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size()==1) return(nums[0]);
        nums.push_back(0);
        int res = nums[0];
        int t_res = 1;
        int prev_i = -1;
        
        for (int i=0;i<nums.size();i++)
        {
            // cout<<nums[i]<<","<<t_res<<","<<res<<endl;
            if (nums[i]==0)
            {   
                res = max(res,0);
                if (prev_i+2==i) res = max(res,nums[i-1]);
                else if (t_res<0)
                {
                    for(int j=prev_i+1;j<i;j++)
                    {
                        t_res = t_res/nums[j];
                        if (t_res>0) break;
                    }
                    res = max(res,t_res);
                }
                prev_i = i;
                t_res = 1;
                continue;
            }
            t_res = t_res*nums[i];
            res = max(res,t_res);
        }
        return(res);
    }
};