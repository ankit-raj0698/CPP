when size of s2 is less than s1 then it can't contain permutation of s1
create two vectors to store freq of two strings and initialize them with 0
m = size of s1
n = size of s2
find the freq of first m char in both s1 and s2
check if freq of char of s1 is same as in s2 for current window of size m
if yes then return true
otherwise check for other window from m to n and slide the window
remove the leftmost char of prev window so decrease the char count
add the current char to the window so increase the char count
check if two vector are equal
​
​
​