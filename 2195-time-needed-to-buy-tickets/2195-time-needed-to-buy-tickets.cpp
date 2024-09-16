class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        int time = 0;
        for (int i = 0; ; i = (i + 1) % tickets.size()) {
            if (tickets[i] > 0) {
                tickets[i]--;
                time++;
            }
            if (tickets[k] == 0) {
                break;
            }
        }
        return time;
    }
};