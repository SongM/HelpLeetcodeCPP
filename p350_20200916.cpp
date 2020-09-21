class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1;
        for (auto n:nums1) m1[n]++;
        vector<int> res;
        for (auto n:nums2)
        {
            if (m1.find(n)==m1.end() or m1[n]==0) continue;
            res.push_back(n);
            m1[n]--;
        }
        return(res);
    }
};