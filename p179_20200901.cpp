void printVector(std::vector <int> const &a) {
    std::cout << "The vector elements are : ";

    for (int i=0; i < a.size(); i++)
 	cout << a[i] << ',';
    cout<<endl;
}

class Solution {
public:
    bool isSmallerNumberLarger(int small_number, int n, unordered_map<int, vector<int>>& m)
    {
        long long_small_number = small_number;
        long long_n = n;
        for (int i=0;i<m[n].size();i++) long_small_number *= 10;
        long_small_number+=n;
        for (int i=0;i<m[small_number].size();i++) long_n *= 10;
        long_n+=small_number;
        // cout<<long_small_number<<","<<long_n;
        return(long_small_number>long_n);
    }
    string helper(vector<int>& nums, int digit_i, unordered_map<int, vector<int>>& m)
    {
        if (nums.size()==0) return("");
        // printVector(nums);
        // if (nums.size()==1) return(to_string(nums[0]));
        if (nums[0]==nums.back())
        {
            string res = "";
            for (int n:nums) res+=to_string(n);
            return(res);
        }
        vector<vector<int>> v(10);
        vector<int> small_number;
        for (int n:nums)
        {
            // cout<<n<<","<<m[n].size()<<","<<digit_i<<endl;
            if (m[n].size()<digit_i) 
            {
                small_number.push_back(n);
                continue;
            }
            int digit = m[n][m[n].size()-digit_i];
            v[digit].push_back(n);
        }
        string res = "";
        bool b_small_used = false;
        if (small_number.size()==0) b_small_used=true;
        for (int i=9;i>=0;i--)
        {
            if (v[i].size()==0) continue;
            
            if (b_small_used==false and isSmallerNumberLarger(small_number[0],v[i][0],m))
            {
                res+=helper(small_number,digit_i+1,m);  
                b_small_used = true;
            }
            res += helper(v[i],digit_i+1,m);
        }
        if (b_small_used==false and small_number[0])
            res+=helper(small_number,digit_i+1,m);  
        return(res);        
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int, vector<int>> m;
        m[0] = {0};
        for (auto n:nums)
        {
            if (m.find(n)!=m.end()) continue;
            int t_n = n;
            while(t_n>0)
            {
                m[n].push_back(t_n%10);
                t_n = t_n/10;
            }
        }
        string res = helper(nums,1,m);
        if (res[0]=='0') return("0");
        return(res);
        
    }
};