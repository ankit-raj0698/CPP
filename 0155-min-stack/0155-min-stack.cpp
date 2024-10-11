class MinStack {
public:
    stack<int> st;
    stack<int> minst;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        // when min stack is empty directly push in min stack
        if(minst.empty()){
            minst.push(val);
        }
        else{
            // find the min till now and push in min stack
            int minVal = min(val, minst.top());
            minst.push(minVal);
        }
    }
    
    void pop() {
        // since we are inserting curr element in normal stack
        // and min till now in min stack every time
        // pop from both stack
        st.pop();
        minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */