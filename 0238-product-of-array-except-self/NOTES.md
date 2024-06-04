**WITH DIVISION**
find the product of all element and divide with current element)
find product of all elements , product of all non zero element , count of zeros
if count of zeros is greater than equal to 2, return answer with all zeros
if current element is zero, answer will be (product of all non zero element)
else answer is (product of all element)/(current element)
​
​
**WITHOUT DIVISION but using extra space**
create a left vector to store product of all elements to the left of current element
create a right vector to store product of all elements to the right of current element
Note: declare size of each vector(nums.size()) otherwise you will get runtime error
multiply left[i] and right[i] and store it in answer
​
**OPTIMAL SOLUTION **
​
declare answer vector with size n
Store left product directly in answer
initialize right product = 1
iterate through the answer vector starting from "n-1" and do below
ans[i] = ans[i] * rightProduct;
rightProduct = rightProduct * nums[i];
​
​
​
​
multiply current element with right product and update right product everytime