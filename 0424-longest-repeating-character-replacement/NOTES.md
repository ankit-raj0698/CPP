​
create a vector to count freq of each element on the go
track the maxFreqCount
**when windowsize - maxFreqCount <= k then calculate result that is find maxLength**
**otherwise update the left pointer to shrink sliding window**
for that decrement the freq of character at left and then increment the left pointer untill windowsize - maxFreqCount becomes
less than or equal to k
increment the right pointer everytime