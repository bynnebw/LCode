//LC 75. Sorted colors
//采用三路快排的思想，对于整个数组只遍历一次就可以了

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = -1, r = nums.size();  //这个数组是这样的：nums[l,,,,,i,,,,,r]
        for( int i = 0; i < r; ){
            if( nums[i] == 1 )
                i ++;
            else if ( nums[i] == 2 )
                swap( nums[i],nums[--r] );
            else{
                assert( nums[i] == 0 );
                swap( nums[++l] , nums[i++]);
            }
        }
    }
};

int main(){

    vector<int>arr = {1,1,0,0,2,0,2,1,0,2};
    Solution().sortColors(arr);
    for( int i = 0; i < arr.size(); i ++ )
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}