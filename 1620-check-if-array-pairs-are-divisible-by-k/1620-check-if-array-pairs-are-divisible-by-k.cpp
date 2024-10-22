class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        unordered_map<int, int> freq;
        for(auto ele: arr){
            int rem = (ele % k + k) % k;
            freq[rem]++;
        }

        // rem can be 0 to k - 1
        for(auto [rem, count] : freq){

            // when rem is 0 it can only be paired with element 
            // whose rem is 0 so freq of this has to be even
            if( rem == 0 ){
                if(count % 2 != 0)
                    return false;
            }        
            // check if rem = x then rem = k - x exist 
            // and their freq is same
            // otherwise pair can't be formed
            else{
                if(freq[rem] != freq[k - rem])
                return false;
            } 
        }
        return true;
    }
};