class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int curr_len;
        vector<string> res;
        string t_res;
        int i=0;
        int start_i=0;
        int space_num = 0;
        while(1)
        {
            curr_len = 0;
            
            while(i<words.size() and curr_len+words[i].size()<=maxWidth)
            {
                curr_len += words[i].size()+1;
                i++;
            }
            space_num = maxWidth-curr_len+i-start_i;
            t_res = "";
            if (i==words.size())
            {
                while(start_i<i-1)
                {
                    t_res += words[start_i++];
                    t_res+=" ";
                    space_num--;
                }
                t_res += words[start_i++];
                for (int i=0;i<space_num;i++) t_res+=" ";
                res.push_back(t_res);
                break;
                
            }
            if (i==start_i+1)
            {
                space_num = maxWidth-words[start_i].size();
                t_res = words[start_i++];
                for (int i=0;i<space_num;i++) t_res+=" ";
                res.push_back(t_res);
                continue;
            }
            while(start_i<i-1)
            {
                t_res += words[start_i++];
                int t_space_num = (space_num+i-start_i-1)/(i-start_i);
                for (int i=0;i<t_space_num;i++) {
                    t_res+=" ";
                }
                space_num -= t_space_num;
            }
            t_res += words[start_i++];
            res.push_back(t_res);
        }
        return(res);
        
    }
};