Use **two pointer approach** to solve this problem i=leftmost index and j=rightmost index
use a while loop till "i<j"
use another while loop to increment "i" till you don't encounter an alphanumeric character
use another while loop to decrement "j" till you don't encounter an alphanumeric character
our i and j are now pointing to alphanumeric character so compare them by converting them to lower
case first
if there is mismatch return false;