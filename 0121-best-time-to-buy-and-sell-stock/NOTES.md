​
use sliding window left =0 and right = 1
iterate the loop until right pointer exceeds size of input array
if it is a profitable transaction then calculate profit and update maxprofit
**otherwise move the left pointer to right as we have got a day where left is smaller than prev value**
increment right everytime