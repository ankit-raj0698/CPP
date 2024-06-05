​
use two pointer approach
start with i = 0 and j = n-1
use while loop i<j
calculate the area : length = j-i and breadth = min(height[i],height[j])
compare with max area and update accordingly
if(height[i] <= height[j])
increment i because we might get greater height to right of current index i
otherwise decrement j, because we might get greater height to left of current index j