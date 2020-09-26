class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    vector<int> nums;
    unordered_map<int, unordered_set<int>> m;
    RandomizedCollection() {
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val)!=m.end()) 
        {
            m[val].insert(nums.size());
                    nums.push_back(val);

            return(false);
        }
        m[val] = {};
        m[val].insert(nums.size());
        nums.push_back(val);
        return(true);

    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        // cout<<endl;
        // for (int n:nums) cout<<n<<",";
        // cout<<endl;
        // for (auto key:m) 
        // {
        //     cout<<key.first<<": ";
        //     for (auto n:key.second) cout<<n<<",";
        //     cout<<endl;
        // }
        if (m.find(val)==m.end()) return(false);
        int remove_ind = *m[val].begin();
        // cout<<remove_ind<<nums.size();
        int last_element = nums.back();
        nums[remove_ind] = last_element;
        // cout<<"a";
        m[val].erase(remove_ind);
        m[last_element].insert(remove_ind);
        m[last_element].erase(nums.size()-1);
        if (m[val].size()==0) m.erase(val);
        nums.pop_back();
        
        // if (m[val].size()==0) m.erase(val);
        // nums[remove_ind] = last_element;
        // nums.pop_back();
        // m[last_element].back() = remove_ind;
        // sort(m[last_element].begin(),m[last_element].end());
        return(true);
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
                // for (int n:nums) cout<<n<<",";
        return nums[rand() % nums.size()];
        
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */