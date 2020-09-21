/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    bool b_workedOnCurr;
    NestedIterator* curr;
    vector<NestedInteger>::iterator curr_it;
    vector<NestedInteger>::iterator end_it;
    int ret_val;
    NestedIterator(vector<NestedInteger> &nestedList) {
        curr_it = nestedList.begin();
        end_it = nestedList.end();
        b_workedOnCurr = false;
    }
    
    int next() {
        return(ret_val);
    }
    
    bool hasNext() {
        // if (b_currNested==false) return(true);
        while(1)
        {
            if (curr_it==end_it) return(false);
            if (curr_it->isInteger()) 
            {
                ret_val = curr_it->getInteger();
                curr_it++;
                return(true);
            }
            if (b_workedOnCurr==false)
            {
                curr = new NestedIterator(curr_it->getList());
                b_workedOnCurr = true;
            }
            if (curr->hasNext()) 
            {
                ret_val = curr->next();
                return(true);
            }
            curr_it++;
            b_workedOnCurr = false;

        }        
        return(true);
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */