class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto ele: stones){
            pq.push(ele);
        }

        while(pq.size() >= 2){
            int x = pq.top();
            pq.pop();

            int y = pq.top();
            pq.pop();

            if(x == y)
                continue;
            else if(x < y)
                pq.push(y - x);
            else
                pq.push(x - y);
        }
        return pq.empty() ? 0 : pq.top();
    }
};