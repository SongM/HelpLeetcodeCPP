// for situation that height[left]==height[right], it doesn't matter whether move left or right
// 34563 -> 3456 or 4563 -> 456
// 31203 -> 3120 or 1203: both case wont change res


class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int res = 0;
        while(left<right)
        {
            int h=height[right];
            if (height[left]<height[right]) {h=height[left];left++;}
            else right--;
            if (res<h*(right-left+1)) res = h*(right-left+1);
        }
        return(res);
    }
};