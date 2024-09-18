class Solution {
public:
    string frequencySort(string s) {

        // map to count freq of each char
        unordered_map<char, int> mp;
        for(char ch: s)
            mp[ch]++;

        // use max heap {freq, char}
        priority_queue<pair<int, char>> pq;
        for(auto it: mp){
            char ch = it.first;
            int freq = it.second;
            pq.push({freq, ch});
        }

        // create the resultant string based on freq
        string res = "";
        while(!pq.empty()){
            int freq =  pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            while(freq--)
                res += ch;
        }

        return res;    
        
    }
};