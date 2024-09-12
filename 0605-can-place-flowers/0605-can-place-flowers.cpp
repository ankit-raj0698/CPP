class Solution {
public:
// approach 1 using extra space
/*
bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        vector<int> temp;
        temp.push_back(0);
        temp.insert(temp.end(), flowerbed.begin(), flowerbed.end());
        temp.push_back(0);

        for(int i = 1; i < temp.size() - 1; i++){
            if(temp[i] == 0 && temp[i - 1] == 0 && temp[i + 1] == 0){
                temp[i] = 1;
                n--;
            }
                
        }
        if(n <= 0)
            return true;
        return false;
    }
    */

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int  size = flowerbed.size();

        for(int i = 0; i < size; i++){
            if(flowerbed[i] == 0){
                //handle corner cases i.e i = 0 and i = size -1
                bool leftEmpty = (i == 0) || (flowerbed[i-1] == 0);
                bool rightEmpty = (i == size - 1) || (flowerbed[i + 1] == 0);

                if(leftEmpty && rightEmpty){
                    n--;
                    flowerbed[i] = 1;
                }
                    
            }
        }

        if(n <= 0)
            return true;
        
        return false;
    }
};