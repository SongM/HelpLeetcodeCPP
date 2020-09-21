class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = -1;
        int second = -1;

        for (int i=0;i<nums.size();i++)
        {
            if (first==-1 or nums[i]<=nums[first]) {first = i;continue;}
            if (second==-1 or nums[i]<=nums[second]) {second = i;continue;}
            return(true);
        }
        return(false);
    }
};