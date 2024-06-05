**Approach: using 2 sum approach**
**Note: Solution must not contains duplicate triplets**
sort the input array so that two sum concept can be used
nums[i] + nums[j] + nums[k] = 0 ==> nums[j] + nums[k] = -nums[i] **(target)**
iterate i from 0 to n-2 to ensure that there are at least two more elements for j and k
j = i + 1 and k = n - 1 and apply two sum now
to handle duplicate triplets compare the adjacent elements for i,j,k