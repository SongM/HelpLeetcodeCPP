class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> hi;
    vector<int> lo;
    MedianFinder() {
    }
    
    void addNum(int num) {
        lo.push_back(num);
        push_heap(lo.begin(),lo.end());
        pop_heap(lo.begin(),lo.end());
        int n = lo.back();
        lo.pop_back();

        hi.push_back(-n);
        push_heap(hi.begin(),hi.end());
        if (lo.size()+1<hi.size())
        {
            pop_heap(hi.begin(),hi.end());
            n = -hi.back();
            hi.pop_back();
            lo.push_back(n);
            push_heap(lo.begin(),lo.end());
        }
        
        // for (auto n:lo)
        //     cout<<n<<"->";
        // cout<<endl;
        // for (auto n:hi)
        //     cout<<n<<"->";
        // cout<<endl;
        // cout<<"-------"<<endl;
    }
    
    double findMedian() {
        if (lo.size()==hi.size())
            return(float(lo.front()-hi.front())/2);
        return(float(-hi.front()));
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */