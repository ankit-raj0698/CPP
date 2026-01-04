class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> freq(1001,0);
        vector<int> ans;
        for(int ele: arr1)
            freq[ele]++;

        for(int ele: arr2){
            while(freq[ele]-- > 0)
                ans.push_back(ele);
        }

        for(int i = 0; i <= 1000; i++){
            while(freq[i]-- > 0)
                ans.push_back(i);
        }

        return ans;
    }
};