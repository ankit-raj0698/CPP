class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i = 0; i < numRows; i++){
            vector<int> temp;
            for(int j = 0; j < i+1; j++){
                if(j == 0 || i == j)
                    temp.push_back(1);
                else{
                    int sum = result[i-1][j] + result[i-1][j-1];
                    temp.push_back(sum);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};