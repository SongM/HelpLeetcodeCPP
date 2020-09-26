bool f(const vector<int> &a, const vector<int> &b) {return(a[0]>b[0]);}

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        int m = nums1.size();
        int n = nums2.size();
        if (k==0 or m==0 or n==0) return(res);
        vector<vector<int>> record;
        for (int i=0;i<m;i++) record.push_back({nums1[i]+nums2[0],i,0});
        make_heap(record.begin(),record.end(),f);
        vector<int> record_back = record.back();

        while(record.size()>0)
        {
            pop_heap(record.begin(),record.end(),f);


            res.push_back({nums1[record.back()[1]],nums2[record.back()[2]]});
            if (record.back()[2]+1 == nums2.size()) record.pop_back();
            else 
            {
                record.back() = {nums1[record.back()[1]]+nums2[record.back()[2]+1],record.back()[1],record.back()[2]+1};
                push_heap(record.begin(),record.end(),f);
                
            }
            k--;
            if (k==0) break;
        }
        return(res);
    }
};