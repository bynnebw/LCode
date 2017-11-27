//删除已经排好序的数组中，重复的元素，但是最大限度保留k个重复的元素
//eg: k = 2
//原数组为 : 1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,4,4,5
//结果为: 1,1,2,2,3,3,4,4,5
//返回长度是: 9
//trick : 想想一个数组，两个指针在移动。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums,int k) {
        int i = 0;
        for( int n : nums )
            if( i < k || n > nums[i-k] )
                nums[i++] = n;
        for( int j = i; j < nums.size(); j ++ )
            nums[j] = 0;

        return i;

    }
};

int main() {
    vector<int> arr = {1,1,1,1,2,2,3};
    int k = 3;
    int rs = Solution().removeDuplicates(arr,k);
    cout<<rs<<endl;

    for( int i = 0; i < arr.size(); i ++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}