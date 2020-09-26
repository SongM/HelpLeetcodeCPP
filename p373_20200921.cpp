class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        int m = nums1.size();
        int n = nums2.size();
        if (k==0 or m==0 or n==0) return(res);
        vector<int> record(m);
        res.push_back({nums1[0],nums2[0]});
        k--;
        record[0]++;
        while(1)
        {
            if (k==0) break;
            int ii = -1;
            int current_min = nums1.back()+nums2.back()+1;
            for (int i=0;i<m;i++)
            {
                if(record[i]==n or current_min<nums1[i]+nums2[record[i]]) continue;
                ii = i;
                current_min = nums1[i]+nums2[record[i]];
            }
            
            if (ii==-1) break;
            res.push_back({nums1[ii],nums2[record[ii]]});
            record[ii]++;
            k--;
        }
        return(res);
    }
};