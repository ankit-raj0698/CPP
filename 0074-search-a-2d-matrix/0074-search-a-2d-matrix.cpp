class Solution {
public:
    int n,m;
    bool binarySearch(vector<int> &arr, int target){
        int low = 0, high = m - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(arr[mid] == target)
                return true;
            else if(target < arr[mid])
                high =  mid - 1;
            else 
                low = mid + 1;
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        n = matrix.size();
        m = matrix[0].size();

        /*
        // this approach will take O(n + log m)
        for(int i = 0; i < n; i++){
            if(target >= matrix[i][0] && target <= matrix[i][m-1])
                return binarySearch(matrix[i], target);
        }
        */

        int low = 0, high = n*m - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;

            // convert the 1D coordinate to 2d coordinate
            int row = mid / m;
            int col = mid % m;

            // matrix[row][col] is our actual mid value

            if(matrix[row][col] == target)
                return true;
            else if(target < matrix[row][col])
                high = mid - 1;
            else 
                low = mid + 1;
        }

        return false;
    }
};