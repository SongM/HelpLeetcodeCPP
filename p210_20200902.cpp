class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> m(numCourses);
        for (auto p:prerequisites)
            m[p[0]].push_back(p[1]);
        vector<bool> visited(numCourses);
        vector<int> res;
        for (int i=0;i<numCourses;i++)
        {
            if (visited[i]==true) continue;
            vector<int> s={i};
            vector<bool> inLink(numCourses);
            inLink[i] = true;
            while(s.size()>0)
            {
                int ii = s.back();
                if (m[ii].size()==0) 
                {
                    inLink[ii] = false;
                    if (visited[ii]==false)
                    {
                        visited[ii] = true;
                        res.push_back(ii);
                    }
                    s.pop_back();
                    continue;
                }
                s.push_back(m[ii].back());
                m[ii].pop_back();
                if (inLink[s.back()]==true) return {};
                inLink[s.back()] = true;
            }
        }
        return(res);
    }
};