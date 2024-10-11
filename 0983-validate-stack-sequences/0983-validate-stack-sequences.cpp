class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j = 0;
        for(int ele: pushed){
            s.push(ele);
            while(!s.empty() && j < popped.size() && s.top() == popped[j]){
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};