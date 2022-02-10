#include <vector>
using std::vector;
#include <iostream>
using std::cout;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int ret=0;
        int left=0,right=0; // [left-window   right-window]
        int sum=0;
        for(left=0;left<nums.size();left++)
        {
            sum=0;//reset sum on Lwindow change
            for(right=left;right<nums.size();right++)
            {
                sum+=nums[right];
                if(sum==k)
                {
                    ret++;//break; cannot break since negative numbers can exist in array...
                }
            }
        }
        return ret;
    }
};


int main()
{
    Solution test;
    vector<int> v = {1,2,3,4,5,-6,6,6,7};
    cout<<test.subarraySum(v,5);
}