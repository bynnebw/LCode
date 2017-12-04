//<剑指offer>面试题3，找到数组中重复的数字

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> duplicate(int numbers[], int length){
        vector<int> res;
        if( numbers==NULL && length <= 0 )
            return res;
        for( int i = 0; i < length; i ++ ){
            if( numbers[i] < 0 || numbers[i] > length - 1 )
                return res;
        }

        for( int i = 0; i < length; i ++ ){
            if( numbers[i] != i ){
                if( numbers[i] == numbers[numbers[i]] ){
                    res.push_back(numbers[i]);
                }
                swap(numbers[i],numbers[numbers[i]]);
            }
        }
        return res;
    }
};

int main(){
    int numbers[9] = {8,2,3,1,0,2,5,3,8};
    vector<int> res = Solution().duplicate(numbers, sizeof(numbers)/ sizeof(int));
    for( int i = 0; i < res.size(); i ++ )
        cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}