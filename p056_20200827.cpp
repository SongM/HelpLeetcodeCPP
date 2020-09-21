class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> res;
        if (intervals.size()<2) return(intervals);
        sort(intervals.begin(),intervals.end());
        vector<int> curr=intervals[0];
        for (auto interval:intervals)
        {
            if (interval[0]<=curr[1]) curr[1]=interval[1]>curr[1]?interval[1]:curr[1];
            else
            {
                res.push_back(curr);
                curr = interval;
            }
        }
        res.push_back(curr);
        return(res);
    }
};