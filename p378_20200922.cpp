// bool f(const vector<int> &a, const vector<int> &b) {return(a[0]>b[0]);}
class Solution {
public:
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int> v;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++) v.push_back(matrix[i][j]);
        }
        sort(v.begin(),v.end());
        return(v[k-1]);
//         int n = matrix.size();
//         int count = 1;
//         vector<vector<int>> r;
//         for (int i=0;i<n;i++) r.push_back({matrix[i][0],i,0});
//         for (int i=1;i<k;i++)
//         {
//             pop_heap(r.begin(),r.end(),f);

//             if (r.back()[2]==n-1) {r.pop_back();continue;}
//             r.back()={matrix[r.back()[1]][r.back()[2]+1],r.back()[1],r.back()[2]+1};
//             push_heap(r.begin(),r.end(),f);
//         }
//         return(r[0][0]);
    }
};