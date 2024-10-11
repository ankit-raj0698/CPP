class FreqStack {
public:

    unordered_map<int, int> freq;
    // pq -> {freq, {pos, ele}}
    priority_queue<pair<int, pair<int, int>>> pq;
    int ind = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        // find the freq of the element
        freq[val]++;
        // push {freq, {index, val}} into pq
        pq.push({freq[val], {ind, val}});
        // increment the index so that next element will be stored there
        ind++;
    }
    
    int pop() {
        // find the top of pq and pop
        auto top = pq.top();
        pq.pop();
        // find the top of stack val and update the freq of the element
        int val = top.second.second;
        freq[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */