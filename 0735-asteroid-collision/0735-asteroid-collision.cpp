class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(auto ele: asteroids){
            // collision only happens when s.top is +ve and curr ele is -ve
            if(s.empty() || ele > 0)
                s.push(ele);
            // now we have negative no
            else{
                // if we have +ve no at top of stack and it is less than curr ele
                while(!s.empty() && s.top() > 0 && s.top() < abs(ele))
                    s.pop();
                // stack top wt is same wt as curr ele but diff sign
                if(!s.empty() && s.top() == abs(ele))
                    s.pop();
                else if(s.empty() || s.top() < 0)
                    s.push(ele);
            }
        }

            vector<int> ans;
            while(!s.empty()){
                ans.push_back(s.top());
                s.pop();
            }
            reverse(ans.begin(), ans.end());
            return ans;            
        }
};