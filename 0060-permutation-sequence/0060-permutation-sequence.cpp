class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> res;

        for(int i = 1; i <= n-1; i++){
            res.push_back(i);
            fact *= i;
        }
        res.push_back(n);
        
        k--; // as we are using 0 based indexing
        string ans = "";

        while(true){
            ans += to_string(res[k/fact]);
            res.erase(res.begin() + k/fact);

            if(ans.size() == n)
                break;

            k = k % fact;
            fact = fact / res.size();
        }
        return ans;
    }
};