#include <vector>
using std::vector;
#include <iostream>
using std::cout;
#include <unordered_map>
using std::unordered_map;
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
class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int sum=0,count=0;
        std::unordered_map<int,int> map={{0,1}};
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            count+=map[sum-k];
            map[sum]++;
        }
        return count;
    }
};

int main()
{
    Solution test;
    vector<int> v = {1,2,3,4,5,-6,6,6,7};
    cout<<test.subarraySum(v,5);

    Solution2 test2;
    cout<<test2.subarraySum(v,5);

}