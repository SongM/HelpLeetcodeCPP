/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        if (guess(n)==0) return(n);
        int hi = n;
        int lo = 0;
        while(1)
        {
            int mi = lo + (hi-lo)/2;
            int res = guess(mi);
            if (res==0) return(mi);
            if (res==1) lo = mi+1;
            else hi = mi-1;
        }
        return(lo);
    }
};