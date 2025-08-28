class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        unordered_map<int, int> mp;
        //store index of each element of arr2 in map
        for(int i = 0; i < arr2.size(); i++){
            mp[arr2[i]] = i;
        }

        // when element is not in arr2 but in arr1, store 1e9 as index
        for(int ele: arr1){
            if(mp.find(ele) == mp.end()){
                mp[ele] = 1e9;
            }
        }

        auto lambda = [&](int num1, int num2){

            // index will only match if no.is present only in arr1 so sort ascending
            if(mp[num1] == mp[num2]){
                return num1 < num2;
            }

            // sort acc to index of arr2
            return mp[num1] < mp[num2];
        };

        // implement custom sort
        sort(arr1.begin(), arr1.end(), lambda);

        return arr1;
        
    }
};