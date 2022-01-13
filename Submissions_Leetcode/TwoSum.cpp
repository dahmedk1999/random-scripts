#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using std::cout;
using std::string;
using std::vector;
//naive method
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        /* Naive
        Runtime: 380 ms
        Memory Usage: 10.2 MB
        */
        #if 0
        // std::sort(nums.begin(),nums.end());
        vector<int> indices;
        // for(int i=0;i<nums.size();i++)cout<<nums[i]<<"\t";    
        for(int i=0;i<nums.size();i++)
            for (int j = i+1; j < nums.size(); j++)
                if(nums[i]+nums[j]==target)
                {
                    indices.push_back(i);
                    indices.push_back(j);
                    return indices;
                }      
        return indices;
        #endif

        /* Map
        Runtime: 30 ms, faster than 42.75% of C++ online submissions for Two Sum.
        Memory Usage: 11.2 MB, less than 17.68% of C++ online submissions for Two Sum.
        */
        #if 1
        vector<int> indices;
        std::map<int,int> m;
        for (int i=0;i<nums.size();i++)
        {
            if(m.end()!=m.find(target-nums[i]))
            {
                indices.push_back(i);
                indices.push_back(m[target-nums[i]]);
                break;
            }
            m[nums[i]]=i;
        }
        return indices;

        #endif

    }
};

int main()
{
    vector<int> num={1,4,6,7,12,24};
    int target =11;
    Solution a;
    
    auto ans=a.twoSum(num,target);
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<"\t";

}