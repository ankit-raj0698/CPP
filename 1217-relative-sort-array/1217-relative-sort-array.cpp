class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> freq;
        for(int ele: arr1){
            freq[ele]++;
        }
        
        int k = 0;
        for(int ele: arr2){
            while(freq[ele] > 0){
                arr1[k++] = ele;
                freq[ele]--;
            }
        }

        for(auto &it: freq){
            while(it.second > 0){
                arr1[k++] = it.first;
                it.second--;
            }
        }
        return arr1;
    }
};