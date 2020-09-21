// every iteration, the starting position moves one character left.
// use a queue to store the list.
// remember to empty the queue after each iteration.


unordered_map<string, int> generateMap(vector<string> v){
    unordered_map<string, int> m;
    for (auto vv:v)
    {
        if (m.find(vv)==m.end()) m[vv]=1;
        else m[vv]+=1;
    }
    // printMap(m);
    return(m);
}

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.size()==0 or s.size()==0) return(res);
        unordered_map<string,int> m=generateMap(words);
        int wl = words[0].size();
        int sl = s.size();
        queue<string> q;
        for (int i=0;i<wl;i++)
        {   
            for (int k=0;k<words.size();k++) q.push("");
            for (int j=0;i+j<sl;j+=wl)
            {
                if(q.front()!="") m[q.front()]++;
                q.pop();
                string sub_string = s.substr(i+j,wl);
                if (m.find(sub_string)!=m.end())
                {
                    m[sub_string]--;
                    q.push(sub_string);
                    bool isARes=true;
                    for (auto it:m)
                    {
                        if (it.second!=0)
                        {
                            isARes = false;
                            break;
                        }
                    }
                    if (isARes) res.push_back(i+j-(words.size()-1)*wl);
                }
                else q.push("");
            }
            while(q.size()>0)
            {
                if(q.front()!="") m[q.front()]++;
                q.pop();                
            }
        }
        return(res);
    }
};