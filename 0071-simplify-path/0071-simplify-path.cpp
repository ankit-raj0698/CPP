class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string token = "";
        stringstream ss(path);

        while(getline(ss,token,'/')){
            if(token == "" || token == ".")
                continue;
            if(token != "..")
                s.push(token);
            else if(!s.empty())
                s.pop();             
        }

        if(s.empty())
            return "/";

        string res = "";
        while(!s.empty()){
            res = "/" + s.top() + res;
            s.pop();
        }
       return res; 
    }
};