class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> m(numCourses);
        for (auto p:prerequisites)
            m[p[0]].push_back(p[1]);
        vector<bool> visited(numCourses);
        for (int i=0;i<numCourses;i++)
        {
            if (visited[i]==true) continue;
            visited[i] = true;
            vector<int> s={i};
            vector<bool> inLink(numCourses);
            inLink[i] = true;
            while(s.size()>0)
            {
                int ii = s.back();
                if (m[ii].size()==0) 
                {
                    inLink[ii] = false;
                    visited[ii] = true;
                    s.pop_back();
                    continue;
                }
                s.push_back(m[ii].back());
                m[ii].pop_back();
                if (inLink[s.back()]==true) return(false);
                inLink[s.back()] = true;
            }
        }
        return(true);
        
        
    }
};