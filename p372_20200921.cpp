class Solution {
    int helper(int a, int k) //a^k mod 1337 where 0 <= k <= 10
    {
        int res = 1;
        while(k>0)
        {
            if (k%2==1) 
            {
                k = k-1;
                res = (res*a)%1337;
            }
            else
            {
                k = k/2;
                a = (a*a)%1337;
            }
        }
        return res;
    }
public:
    int superPow(int a, vector<int>& b) {
        a = a%1337;
        if (a==0) return(0);
        if (a==1) return(1);
        if (b.empty()) return 1;
        int last_digit = b.back();
        b.pop_back();
        return(helper(superPow(a, b), 10) * helper(a, last_digit) % 1337);
    }
};

// class Solution {
// public:
//     // int helper(int &a,vector<int>& b)
//     // {
//     //     if (a==0) return(0);
//     //     if (a==1) return(1);
//     //     if (b.size()==1 and b[0]==1) return(a);
//     //     if (b.back()%2==1) 
//     //     { 
//     //         b.back()--;
//     //         return((a*helper(a,b))%1337);
//     //     }
//     //     int carry = 0;
//     //     for (int i=0;i<b.size();i++)
//     //     {
//     //         b[i] = b[i]+carry*10;
//     //         carry = b[i]%2;
//     //         b[i] = b[i]/2;
//     //     }
//     //     if (b[0]==0) b.erase(b.begin());
//     //     a = (a*a)%1337;
//     //     return(helper(a,b));
//     // }
//     int helper2(int a, int digit)
//     {
//         if (digit==0) return(a);
//         int res = 1;
//         a = (a*a)%1337;
//         res = (res*a)%1337;
//         a = (a*a)%1337;
//         a = (a*a)%1337;
//         res = (res*a)%1337;
//         return(helper2(res,digit-1));
        
//     }
//     int helper1(int a, int b_i)
//     {
//         int res = 1;
//         while(b_i>0)
//         {
//             if (b_i%2==1) 
//             {
//                 res = (res*a)%1337;
//                 b_i -= 1;
//                 continue;
//             }
//             a = (a*a)%1337;
//             b_i = b_i/2;
//         }
//         return(res);
//     }
//     int superPow(int a, vector<int>& b) {
//         // a = a%1337;
//         // return(helper(a,b));
//         a = a%1337;
//         if (a==0) return(0);
//         if (a==1) return(1);
//         int res = 1;
//         for (int i=0;i<b.size();i++)
//         {
//             res = (res*helper2(helper1(a,b[i]),b.size()-i-1))%1337;
//             cout<<res<<endl;
//         }
//         return(res);

//     }
// };