class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid = (nums.size()+1)/2;
        vector<int> t_nums=nums;
        for (int i=0;i<mid-1;i++)
        {
            nums[2*i] = t_nums[mid-i-1];
            nums[2*i+1] = t_nums[nums.size()-i-1];
            // cout<<2*i<<2*i+1<<nums.size()<<endl;
        }
        nums[2*mid-2]=t_nums[0];
        if (nums.size()%2==0) nums[2*mid-1] = t_nums[mid];
        return;
    }
};