struct pair_hash
{
    size_t operator () (pair<int,int> const &p) const
    {
        // size_t h1 = p.first;
        // size_t h2 = p.second;
        return(p.first*7*13+p.second);
    }
};
class Solution {
public:

    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int min_x = rectangles[0][0];
        int min_y = rectangles[0][1];
        int max_x = rectangles[0][2];
        int max_y = rectangles[0][3];
        int area = 0;
        for (auto rec:rectangles)
        {
            min_x = min(min_x,rec[0]);
            min_y = min(min_y,rec[1]);
            max_x = max(max_x,rec[2]);
            max_y = max(max_y,rec[3]);
            area += (rec[2]-rec[0])*(rec[3]-rec[1]);
        }
    
        if (area!=(max_x-min_x)*(max_y-min_y)) return(false);
        unordered_map<pair<int,int>, int, pair_hash> m;
        m[make_pair(min_x,min_y)] = 1;
        m[make_pair(min_x,max_y)] = 1;
        m[make_pair(max_x,min_y)] = 1;
        m[make_pair(max_x,max_y)] = 1;
        for (auto rec:rectangles)
        {
            pair<int, int> p1 = make_pair(rec[0],rec[1]);
            if (m.find(p1)==m.end()) m[p1] = 1;
            else m[p1]++;
            pair<int, int> p2 = make_pair(rec[2],rec[1]);
            if (m.find(p2)==m.end()) m[p2] = 1;
            else m[p2]++;
            pair<int, int> p3 = make_pair(rec[0],rec[3]);
            if (m.find(p3)==m.end()) m[p3] = 1;
            else m[p3]++;
            pair<int, int> p4 = make_pair(rec[2],rec[3]);
            if (m.find(p4)==m.end()) m[p4] = 1;
            else m[p4]++;
        }

        for (auto elem:m)
        {
            if (elem.second==2 or elem.second==4) continue;
            return(false);
        }
        return(true);
       
    }
};