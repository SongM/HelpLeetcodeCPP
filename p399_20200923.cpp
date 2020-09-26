class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, pair<double,double>>> m;
        for (int i=0;i<equations.size();i++)
        {
            m[equations[i][0]][equations[i][1]] = make_pair(values[i],1);
            m[equations[i][1]][equations[i][0]] = make_pair(1,values[i]);
        }
        vector<double> res;
        vector<string> variables;
        for (auto it:m)
            variables.push_back(it.first);
        for (auto q:queries)
        {   
            if (m.find(q[0])==m.end() or m.find(q[1])==m.end())
            {
                res.push_back(-1);
                continue;
            }
            if (q[0]==q[1]) 
            {
                res.push_back(1);
                continue;
            }

            if (m[q[0]].find(q[1])!=m[q[0]].end())
            {
                double t_res = m[q[0]][q[1]].first/m[q[0]][q[1]].second;
                res.push_back(t_res);
                continue;
            }
            
            // unordered_set<string> finished;
            vector<string> s;
            for (auto it:m[q[0]])
            {
                s.push_back(it.first);
            }
            while(s.size()>0)
            {
                string last = s.back();
                s.pop_back();
                for (auto it:m[last])
                {
                    if (it.first==q[0] or m[q[0]].find(it.first)!=m[q[0]].end()) continue;
                    s.push_back(it.first);
                    auto q_0__last = m[q[0]][last];
                    auto last__it_first = it.second;
                    double t1 = q_0__last.first*last__it_first.first;
                    double t2 = q_0__last.second*last__it_first.second;
                    m[q[0]][it.first] = make_pair(t1,t2);
                    m[it.first][q[0]] = make_pair(t2,t1);
                    if (it.first==q[1]) break;
                }
                if (m[q[0]].find(q[1])!=m[q[0]].end()) break;
            }
            if (m[q[0]].find(q[1])!=m[q[0]].end())
            {
                double t_res = m[q[0]][q[1]].first/m[q[0]][q[1]].second;
                res.push_back(t_res);
            }
            else res.push_back(-1);
                
        }
        return(res);
    }
};