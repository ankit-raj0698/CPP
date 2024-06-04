**Sorting the array**
take a lastSmaller = INT_MIN and initial length to be 1
sort the array
iterate through the array starting from "0" to "n-1"
check if "arr[i] - 1" is less than lastSmaller then it is part of consecutive sequence
so update the length that is length++ and lastSmaller to be current element i.e.. arr[i]
if "arr[i] == lastSmaller" then no need to do anything simply skip
if "arr[i] != lastSmaller" so it means that we are getting a new sequence
so update the length = 1 and lastSmaller to be current element i.e.. arr[i]
​
**Approach 2 : Using unordered set**
​
insert all the elements of input array in an unordered set
iterate through all the elements of unordered set
if current element is nums[i] and nums[i] - 1 is present in the set Then
it means that this is not the starting point of the sequence so skip it
if current element is nums[i] and "nums[i] - 1 is not present" in the set then
assign length = 1 and use a while loop
iterate in the loop until nums[i] + length does not exist in the set or check consecutive elements i.e.."ele + 1" are present in the set
in the while loop increment the length by 1
check the maxLength and update accordingly