//15.Three sum
//使用双指针的方法，并没有使用查找表来进行
//注意本实现中，避开重复元素的方法

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() <= 2) return {};
        vector<vector<int>> rtn;
        sort(nums.begin(), nums.end()); //O(nlogn)

        for(int i = 0; i < nums.size();){
            int start = i+1, end = nums.size()-1;

            while(start < end){
                if(nums[i]+nums[start]+nums[end] == 0){
                    rtn.push_back({nums[i],nums[start],nums[end]});
                    start++;
                    end--;
                    while((start < end) && nums[start] == nums[start-1]) start++;   //绕过相同的元素
                    while((start < end) && nums[end] == nums[end+1]) end--;         //绕过相同的元素

                }else if(nums[i]+nums[start]+nums[end]<0){
                    start++;
                    while((start < end) && nums[start] == nums[start-1]) start++;   //绕过相同的元素
                }else{
                    end--;
                    while((start < end) && nums[end] == nums[end+1]) end--; //绕过相同的元素
                }
            }
            i++;
            while((i < nums.size()) && nums[i] == nums[i-1])    //绕过相同的元素
                i++;
        }
        return rtn;
    }
};

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = Solution().threeSum(nums);
    for( int i = 0; i < res.size(); i ++ ){
        for( int j = 0; j < res[i].size(); j ++ ){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}