class FreqStack {
public:

    unordered_map<int, int> freq;
    // pq -> {freq, {pos, ele}}
    priority_queue<pair<int, pair<int, int>>> pq;
    int pos = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        pq.push({freq[val], {pos, val}});
        pos++;
    }
    
    int pop() {
        auto top = pq.top();
        pq.pop();
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