class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for(int i = 0; i < arr2.size(); i++)
            mp[arr2[i]] = i;

        for(int ele: arr1){
            if(mp.find(ele) == mp.end())
                mp[ele] = 1e9;
        }
            
        
        sort(arr1.begin(), arr1.end(), [&](int x, int y){
            if(mp[x] == mp[y])
                return x < y;
            return mp[x] < mp[y];
        });

        return arr1;
    }
};