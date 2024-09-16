class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        int res = students.size();
        unordered_map<int, int> mp;
        for(int stu: students)
            mp[stu]++;
        
        // order of sandwiches matter, so traverse them
        for(int preference: sandwiches){
            if(mp.find(preference) != mp.end()){
                res--;
                mp[preference]--;

                if(mp[preference] == 0)
                    mp.erase(preference);
            }
            else
                return res;
        }

        return res;
        
    }
};