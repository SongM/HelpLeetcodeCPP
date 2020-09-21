class Solution {
public:
    vector<int> divideNConquer(vector<int>& nums, vector<int>& smaller,  int lo, int hi)
    {
        if (lo==hi) return {lo};
        int mid = lo + (hi-lo)/2;
        vector<int> order_first_half = divideNConquer(nums,smaller,lo,mid);
        vector<int> order_second_half = divideNConquer(nums,smaller,mid+1,hi);
        vector<int> order;
        int i = 0;
        int j = 0;
        int count = 0;
        while(i<order_first_half.size() or j<order_second_half.size())
        {
            
            if (i==order_first_half.size())
            {
                order.push_back(order_second_half[j]);
                count++;
                j++;
                continue;
            }
            if (j==order_second_half.size())
            {
                order.push_back(order_first_half[i]);
                smaller[order_first_half[i]]+=count;
                i++;
                continue;
            }
            int n1 = nums[order_first_half[i]];
            int n2 = nums[order_second_half[j]];
            if (n2<n1)
            {
                order.push_back(order_second_half[j]);
                j++;
                count++;
                continue;
            }
            else
            {
                order.push_back(order_first_half[i]);
                smaller[order_first_half[i]]+=count;
                i++;                
            }
        }
        // for (int i:order) cout<<i<<",";
        // cout<<endl;
        return(order);
        
        
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        if (n==0) return(res);
        divideNConquer(nums,res,0,n-1);
        return(res);
    }
};