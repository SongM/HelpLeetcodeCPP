class Solution {
public:

    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int curr = 1;
        for (int i=0;i<n;i++)
        {
            res.push_back(curr);
            curr = curr*10;
            if (curr<=n) continue;
            while(1)
            {
                curr = curr/10;
                curr++;
                if (curr<=n and curr%10!=0) break;
                curr--;
            }
        }
        return(res);
    }
};