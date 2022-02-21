#include <vector>
using std::vector;
#include <unordered_map>
using std::unordered_map;
#include <algorithm>
using std::sort;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int maj=n/2;
        unordered_map<int,int> mymap;
        for(int x: nums)
            mymap[x]++;
        for(auto x: mymap)
            if(x.second > maj) return x.first;
        return -1;
    }
    int majorityElement2(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    return nums[nums.size()/2];
    }
};