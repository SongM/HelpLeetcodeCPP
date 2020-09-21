// could solve with two pointer, use O(2n) and O(1) space
// the method below is O(3n) with O(n) space
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size()<3) return(0);
        vector<int> left = {0};
        for (int i=0;i<height.size()-1;i++)
        {
            if (height[i]>left.back()) left.push_back(height[i]);
            else left.push_back(left.back());
        }
        vector<int> right = {0};
        for (int i=height.size()-1;i>0;i--)
        {
            if (height[i]>right.back()) right.push_back(height[i]);
            else right.push_back(right.back());
        }
        reverse(right.begin(),right.end());
        int sum=0;
        for (int i=0;i<height.size();i++)
        {
            int bank = left[i]<right[i]?left[i]:right[i];
            if (height[i]<bank) sum += bank-height[i];
        }
        return(sum);
        
        
    }
};