class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<vector<int>> m(26);
        string res;
        for (int i=s.size()-1;i>=0;i--)
            m[s[i]-'a'].push_back(i);
        int possible_max_pos;
        // for (int i=0;i<26;i++)
        // {
        //     cout<<'a'+i<<": ";
        //     for (auto ii:m[i]) cout<<ii<<",";
        //     cout<<endl;
        // }
        while(1)
        {
            possible_max_pos=s.size();
            for (int i=0;i<26;i++)
            {
                if (m[i].size()==0) continue;
                if (m[i][0]<possible_max_pos) possible_max_pos = m[i][0];
            }
          
            if (possible_max_pos==s.size()) break;
            int ii=-1;
            for (int i=0;i<26;i++)
            {
                if (m[i].size()==0 or m[i].back()>possible_max_pos) continue;
                ii = i;
                break;
            }
            for (int i=ii+1;i<26;i++)
            {
                if (m[i].size()==0) continue;
                while(m[i].back()<m[ii].back()) m[i].pop_back();
            }
            m[ii] = {};
            res += 'a'+ii;
        }
        return(res);
        

    }
};