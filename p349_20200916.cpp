class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m1;
        for (auto n:nums1) m1.insert(n);
        vector<int> res;
        for (auto n:nums2)
        {
            if (m1.find(n)==m1.end()) continue;
            res.push_back(n);
            m1.erase(n);
        }
        return(res);
    }
};