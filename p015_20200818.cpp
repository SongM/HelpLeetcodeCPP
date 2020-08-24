// this solution uses hashtables, achieving o(n^2) time complexity.
// for the search part, using t_res[0]<t_res[1]<t_res[2] to avoid duplicity.


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size()<3) return(res);
        unordered_map<int,int> m;
        for (auto n:nums)
        {
            if (m.find(n)!=m.end()) m[n]++;
            else m[n]=1;
        }
        // printMap(m);
        for (auto it=m.begin();it!=m.end();++it)
        {
            if (it->first==0 and it->second>=3) 
            {
                res.push_back({0,0,0});
                continue;
            }
            if (it->first!=0 and it->second>=2) 
            {
                if (m.find(-2*it->first)!=m.end()) res.push_back({it->first,it->first,-2*it->first});
            }
            // t_nums.push_back(it->first)
            if (it->first>=0) continue;
            for(auto iit=m.begin();iit!=m.end();iit++)
            {
                if (iit->first<=it->first) continue;
                int s = it->first + iit->first; 
                if (s+iit->first>=0) continue;
                if (m.find(-s)!=m.end())
                    res.push_back({it->first,iit->first,-s});
            }           
        }
        
        return(res);
    }

};
