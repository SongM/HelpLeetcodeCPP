class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int min_count = 1;
        vector<int> count_count(nums.size()+1);
        
        for (int n:nums)
        {
            if (m.find(n)==m.end()) m[n]=1;
            else m[n]++;
            count_count[m[n]-1]--;
            count_count[m[n]]++;
            if (m[n]==min_count) k--;
            if (k<0) 
            {
                k+=count_count[min_count];
                min_count++;
            }
            // cout<<n<<","<<m[n]<<", k="<<k<<", "<<min_count<<endl;
        }
        vector<int> res;
        for (auto it=m.begin();it!=m.end();it++)
        {
            // cout<<it->first<<":"<<it->second<<endl;
            if (m[it->first]>=min_count)
            res.push_back(it->first);
        }
        return(res);
    }
};