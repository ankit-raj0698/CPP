class Solution {
public:
    int solve(int n, int k){
        if(n == 1)
            return 0;
        
        int ind = solve(n - 1, k);
        ind = (ind + k) % n;

        return ind;
    }
    int findTheWinner(int n, int k) {
        int ind = solve(n, k);
        return ind + 1;
    }
};