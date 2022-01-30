#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
/* 
Given an array, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?



    void rotate(vector<int>& nums, int k) 
        {
            for(int i=0;i<k;i++)
            {
                int size=nums.size();
                int lastNum=nums[size-i-1];
                nums.emplace(nums.begin(),lastNum);
            }
            for(int i=0;i<k;i++)
                nums.erase(nums.end()-1);
        }
    37/38 Pass
    Time limit exceeded
    */
class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        
        for(int i=0;i<k;i++)
        {
            int size=nums.size();
            int lastNum=nums[size-i-1];
            nums.emplace(nums.begin(),lastNum);
        }
        for(int i=0;i<k;i++)
            nums.erase(nums.end()-1);
    

    }
};


int main()
{
    Solution Test;
    vector<int> vec = {0,1,2,3,4,5,6,7};
    // vector<int> case38= {2^31 -1 indices }
    Test.rotate(vec,0);
    for(int i=0;i<vec.size();i++)
        cout<<vec[i];
    cout<<endl;
}