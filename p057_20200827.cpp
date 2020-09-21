class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size()==0 or newInterval[0]>intervals.back()[1])
        {
            intervals.push_back(newInterval);
            return(intervals);
        }
        if (newInterval[1]<intervals[0][0])
        {
            intervals.insert(intervals.begin(),newInterval);
            return(intervals);
        }
        if (newInterval[1]<=intervals[0][1])
        {
            intervals[0][0] = intervals[0][0]<newInterval[0]?intervals[0][0]:newInterval[0];
            return(intervals);
        }
        if (newInterval[0]>=intervals.back()[0])
        {
            intervals.back()[1] = intervals.back()[1]>newInterval[1]?intervals.back()[1]:newInterval[1];
            return(intervals);
        }
        int i=0;
        while(i<intervals.size() and intervals[i][0]<=newInterval[0]) i++;
        int j=i;
        while(j<intervals.size() and intervals[j][1]<=newInterval[1]) j++;
        if (i>0 and intervals[i-1][1]>=newInterval[0]) i--;
        if (j<intervals.size() and intervals[j][0]<=newInterval[1]) j++;
        newInterval[0] = intervals[i][0]<newInterval[0]?intervals[i][0]:newInterval[0];
        newInterval[1] = intervals[j-1][1]>newInterval[1]?intervals[j-1][1]:newInterval[1];        
        intervals.erase(intervals.begin()+i,intervals.begin()+j);
        intervals.insert(intervals.begin()+i,newInterval);
        return(intervals);
        
    }
};