check the size of s and t, if **size is not same** return false
create an unordered map<char,int>
find the frequency of every element of s
for each element of t, decrement the frequency of every element in map
In the end, check if there exists any value(map.second) in map which is not 0
if yes then return false