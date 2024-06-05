**Approach 1 : all non repeating char means all unique char**
create an unordered_map to count freq of char
when windowsize = mapsize then calculate the answer
when windowsize > mapsize then shrink the window
start deleting the char from left side of the window untill windowsize becomes less than or equal to
mapsize
**Note** : whenever freq of a char becomes 0, delete that char from map so that the size of map would
decrease.
​
**Approach 2: using unordered_set**
sliding window left and right = 0
use an unordered set to track unique elements seen till now
iterate till right reaches the last index of input string
if char "s[right]" is already in the set then shrink the window size from left
therefore delete the char at s[left] from set, increment left pointer untill we can insert the current char in the set
otherwise insert the current char s[right] in the set
increment the right pointer everytime
​
​
​
​