class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        queue<int> q;
        unordered_set<int> visited;
        int level = 0;

        q.push(x);
        visited.insert(x); // mark the x as visited


        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                int num = q.front();
                q.pop();
                
                if(num == y)
                    return level;

                // try all 4 options
                // check num / 11 doesn't exist in set
                if(num % 11 == 0 && visited.find(num / 11) == visited.end()){
                    q.push(num/11);
                    visited.insert(num/11);

                }
                    
                if(num % 5 == 0 && visited.find(num / 5) == visited.end()){
                    q.push(num/5);
                    visited.insert(num/5);

                }

                int increment = num + 1;
                if(visited.find(increment) == visited.end()){
                    q.push(increment);
                    visited.insert(increment);
                }
                    

                int decrement = num - 1;
                if(visited.find(decrement) == visited.end()){
                    q.push(decrement);
                    visited.insert(decrement);
                }
                    

            }
            level++;
        }
        return level;
    }
};