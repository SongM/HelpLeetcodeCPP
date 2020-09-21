class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = nums[0];
        int count = 0;
        for (auto n:nums)
        {
            if (n==vote) count++;
            else
            {
                count--;
                if (count<0)
                {
                    vote = n;
                    count = 1;
                }
            }
        }
        return(vote);
    }
};