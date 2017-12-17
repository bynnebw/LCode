//719. Find K-th Smallest Pair Distance
//这是参考的一份源码，具体细节目前还没有搞清楚，需要再研究一下。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), low = 0, high = 1000000;
        while (low < high) {
            int mid = (low + high)/2, cnt = 0;
            for (int i = 0, j = 0; i < n; i++) {
                while (j < n && nums[j]-nums[i] <= mid) j++;
                cnt += j-i-1;
            }
            if (cnt < k)
                low = mid+1;
            else
                high = mid;
        }
        return low;
    }
};

int main(){
    vector<int> nums = {1,3,1};
    int k = 1;

    int res = Solution().smallestDistancePair(nums,k);
    cout<<"The answer is:"<<res<<endl;

    return 0;
}