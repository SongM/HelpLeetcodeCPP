// find i and j so that (i+j)==(nums1.len()+nums2.len())//2 and all nums1 elements before i 
// and all nums2 elements before j are not greater than nums1[i] and nums2[j]
//
// to avoid one vector are all greater than the other one.
// add a ghost small element to the front of both nums1 and nums2
// to balance the vectors (so that the median of the new vecotrs 
// is still the median of the old vectors), add a ghost large element to the back
// 
// switch nums1 and nums2 so that nums1 is shorter
//
// use binary search to find i and j
//
// notice that i and j satisfies nums1[0:i-1] and nums2[0:j-1] <= (nums1[i],nums2[j])
// but doesn't necessarily mean nums1[i+1:] and nums2[j+1] >= (nums1[i],nums2[j])
// need to identify the correct median from nums1[i], nums1[i+1], nums2[j], nums2[j+1]


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()>nums2.size())
        {
            vector<int> nums = nums1;
            nums1 = nums2;
            nums2 = nums;
        }
        int a = nums2[0]-1;
        int b = nums2.back()+1;
        if (nums1.size()>0) 
        {
            if (nums1[0]-1<a) a = nums1[0]-1;
            if (nums1.back()+1>b) b = nums1.back()+1;
        }
        nums1.insert(nums1.begin(),a);
        nums2.insert(nums2.begin(),a);
        nums1.push_back(b);
        nums2.push_back(b);
        int m = nums1.size();
        int n = nums2.size();

        int lo = 0;
        int hi = m-1;
        while(1)
        {
            int i = (lo+hi)/2;
            int j = (m+n)/2-i-1;
            if (j>0 and nums1[i]<nums2[j-1])
            {
                lo = i+1;
                continue;
            }
            if (i>0 and nums1[i-1]>nums2[j])
            {
                hi = i-1;
                continue;
            }
            int n1 = nums1[i]<nums2[j]?nums1[i]:nums2[j];
            int n2 = nums1[i]<nums2[j]?nums2[j]:nums1[i];
            int n3 = 0;
            if (i==m-1) n3 = nums2[j+1];
            else if (j==n-1) n3 = nums1[i+1];
            else n3 = nums2[j+1]<nums1[i+1]?nums2[j+1]:nums1[i+1];
            n2 = n2<n3?n2:n3;
            if ((m+n)%2==1) return(n2);
            return(float(n1+n2)/2);
        }
        
        
        return(0);
    }
};