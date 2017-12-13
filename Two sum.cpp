//1.Two sum
//[*****?(target-#)*****#............]使用查找表

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for( int i = 0; i < nums.size(); i ++ ){
            int compliment = target - nums[i];
            if( mp.find(compliment) != mp.end() ){
                int res[2] = {mp[compliment],i};
                return vector<int>(res,res+2);
            }
            mp[nums[i]] = i;
        }
        throw invalid_argument("The input has no solution");
    }
};

int main(){

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = Solution().twoSum(nums,target);
    for( int i = 0; i < res.size();  i ++ )
        cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}