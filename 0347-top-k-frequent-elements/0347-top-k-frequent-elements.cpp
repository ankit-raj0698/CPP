class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        typedef pair<int,int> P;
        //create a map and store freq of each element
        unordered_map<int,int> count;
        for(auto ele:nums){
            count[ele]++;
        }
        
        //create a min heap to store freq and element
        //But we want to store freq as well as element so use pair
        priority_queue<P,vector<P>,greater<P>> pq;
        for(auto ele:count){
            int value = ele.first;
            int freq = ele.second;
            //in the min heap push {freq,value} first so that min heap is created on freq
            pq.push({freq,value});
            //when size of min heap exceeds k, pop 
            if(pq.size()>k){
                pq.pop();
            }
        }
        
       //store answer
       vector<int> res;
       while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
       return res;
    }
};