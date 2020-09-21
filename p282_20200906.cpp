class Solution {
public:
    void helper(vector<string>& res, string t_res, long curr_val, long prev_num, int i, string& num, int& target)
    {
        if (i==num.size())
        {
            if (curr_val==target) res.emplace_back(t_res);
            return;
        }
        for (int j=i;j<num.size();j++)
        {
            if (num[i]=='0' and j>i) return;
            string str_curr_num = num.substr(i,j-i+1);
            long long_curr_num = stol(str_curr_num);
            if (i==0) {
                helper(res,str_curr_num, long_curr_num, long_curr_num, j+1, num, target);
                continue;
            }
            helper(res,t_res+"+"+str_curr_num,curr_val+long_curr_num,long_curr_num,j+1,num,target);
            helper(res,t_res+"-"+str_curr_num,curr_val-long_curr_num,-long_curr_num,j+1,num,target);
            helper(res,t_res+"*"+str_curr_num,curr_val-prev_num+prev_num*long_curr_num,prev_num*long_curr_num,j+1,num,target);
        }
        return;
    }
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        helper(res, "", 0, 0, 0, num, target);
        return(res);
    }
};