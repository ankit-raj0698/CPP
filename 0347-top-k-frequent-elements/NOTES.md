Approach 1 : using MIN HEAP
create an unordered map to count freq of each element in input array
create a min heap to store **{freq,element}** of k elements
iterate over the count map and insert {freq,element} in min heap
if size of min heap exceeds k, pop from heap
iterate through the min heap of k elements and store the elements in answer
​
​
Using 2D vector
create an unordered map to store freq of each element
create a 2D bucket vector to store freq of element as index "i" and index "j"
as vector of elements with freq "i"
iterate through the bucket vector from right to left
if bucket[i] is not empty and k > 0 push the element in answer and decrement k and pop that element from bucket[i]
​