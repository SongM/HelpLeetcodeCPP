class SummaryRanges {
public:
    /** Initialize your data structure here. */

    unordered_set<int> data;
    unordered_set<int> start;
    unordered_set<int> end;
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if (data.find(val)!=data.end()) return;
        data.insert(val);
        if (end.find(val-1)==end.end() and start.find(val+1)==start.end())
        {
            end.insert(val);
            start.insert(val);
        }
        else if(start.find(val+1)==start.end())
        {
            end.erase(val-1);
            end.insert(val);
        }
        else if(end.find(val-1)==end.end())
        {
            start.erase(val+1);
            start.insert(val);
        }
        else
        {
            end.erase(val-1);
            start.erase(val+1);
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<int> v_start(start.begin(),start.end());
        vector<int> v_end(end.begin(),end.end());
        sort(v_start.begin(),v_start.end());
        sort(v_end.begin(),v_end.end());
        // for (auto i:v_start) cout<<i<<endl;
        vector<vector<int>> res;
        for (int i=0;i<v_start.size();i++)
            res.push_back({v_start[i],v_end[i]});
        return(res);
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */