class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n);
        vector<int> t_res(n);
        for (int i=0;i<n;i++) res[i] = t_res;
        int count = 0;
        int s=1;
        while(1)
        {
            for (int i=count;i<n-count;i++) res[count][i] = s++;
            if (s>=n*n) break;
            for (int i=count+1;i<n-count;i++) res[i][n-count-1] = s++;
            for (int i=n-count-2;i>=count;i--) res[n-count-1][i] = s++;
            if (s>=n*n) break;
            for (int i=n-count-2;i>=count+1;i--) res[i][count] = s++;
            count++;
        }
        return(res);
    }
};