class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int, int> mp;
        int left = 0, right = 0, maxlen = 0;
        while(right < fruits.size()){

            mp[fruits[right]]++;

            while(mp.size() > 2){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0)
                    mp.erase(fruits[left]);
                left++;
            }

            if(mp.size() <= 2){
                maxlen = max(maxlen, right - left + 1);
            }

            right++;

        }
        return maxlen;
    }
};