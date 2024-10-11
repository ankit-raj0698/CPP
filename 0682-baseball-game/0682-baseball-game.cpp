class Solution {
public:

    int calPoints(vector<string>& operations) {
        
        stack<int> s;
        for(auto str: operations){
            if(!s.empty() && str == "C")
                s.pop();
            else if(!s.empty() && str == "D")
                s.push(s.top() * 2);
            else if(s.size() > 1 && str == "+"){
                int second = s.top();
                s.pop();
                int first = s.top();

                int sum = first + second;
                s.push(second);
                s.push(sum);
            }
            else 
                s.push(stoi(str));
            
        }

        if(s.empty())
            return 0;

        int sum = 0;
        while(!s.empty()){
            sum += s.top();
            s.pop();
        }
       return sum; 
    }
};