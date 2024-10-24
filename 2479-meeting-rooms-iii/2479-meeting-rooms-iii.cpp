class Solution {
public:
    typedef pair<long long,  int> P;
    int mostBooked(int n, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());

        vector<int> count(n, 0);
        priority_queue<P, vector<P>, greater<P>> used;
        priority_queue<int, vector<int>, greater<int>> available;

        for(int i = 0; i < n; i++){
            available.push(i);
        }

        for(auto meet: meetings){
            int start = meet[0];
            int end = meet[1];
            int duration =  end - start;

            while(!used.empty() && used.top().first <= start){
                int room = used.top().second;
                used.pop();
                available.push(room);                
            }

            if(!available.empty()){
                int room = available.top();
                available.pop();
                used.push({end, room});
                count[room]++;
            }
            else{
                auto  [endTime, room] = used.top();
                used.pop();
                used.push({endTime + duration, room});
                count[room]++;
            }
        }

        int maxIndex = 0;
        int maxi = 0;
        for(int i = 0; i < n; i++){
            if(count[i] > maxi){
                maxi = count[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }
};