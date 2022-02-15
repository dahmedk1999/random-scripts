#include <vector>
using std::vector;
/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
 

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.

Runtime: 25 ms, faster than 54.92% of C++ online submissions for Single Number.
Memory Usage: 17 MB, less than 50.23% of C++ online submissions for Single Number.

Runtime: 12 ms, faster than 98.32% of C++ online submissions for Single Number.
Memory Usage: 17 MB, less than 19.26% of C++ online submissions for Single Number.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=nums[0];
        for(int i=1;i<nums.size();i++)
            x^=nums[i];
    return x;
    }
    int singleNumber2(vector<int>& nums) {
        int ret=0;
        for(int a:nums)
            ret^=a;
        return ret;
    }
};