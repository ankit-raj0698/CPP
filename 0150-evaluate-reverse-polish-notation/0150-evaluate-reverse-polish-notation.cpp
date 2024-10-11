class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> s;
        for(auto str: tokens){
            
            if(str == "+" || str == "-" || str == "*" || str == "/"){
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();

                if(str == "+")
                    s.push(first + second);
                else if(str == "-")
                     s.push(first - second);
                else if(str == "*")
                     s.push(first * second);
                else if(str == "/")
                     s.push(first / second);
            }           
            else 
                s.push(stoi(str));
        }
        return s.top();
    }
};