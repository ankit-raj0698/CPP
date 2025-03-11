class Solution {
public:
    int solve(int n, int k){
        if(n == 1)
            return 0; // when only element left
        
        int ind = solve(n - 1, k);
        ind = (ind + k) % n; // to find the index of the winner after deletion

        return ind;
    }
    int findTheWinner(int n, int k) {
        int ind = solve(n, k);
        return ind + 1; // as we have 0 based indexing
    }
};