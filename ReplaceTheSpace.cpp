//<剑指offer>面试题5, 替换空格（字符串）
//这个代码在测试的时候实际上有点问题，需要再修正一下。

#include <iostream>

using namespace std;

class Solution{
public:
    //参数length是最大值(限制)
    void replaceBlank(char string[], int length){
        if( string == NULL || length <= 0 )
            return;

        //先统计一下字符串的长度，以及空格的个数
        int originalLength = 0;
        int numberOfBlank = 0;
        int i = 0;
        while( string[i] != '\0' ){
            ++originalLength;
            if( string[i] == ' ' )
                ++numberOfBlank;
            ++i;
        }

        //将新的数组长度扩大，倒序遍历，替换空格
        int newLength = originalLength + numberOfBlank*2;
        if( newLength > length )
            return;

        int indexOfOriginal = originalLength;
        int indexOfNew = newLength;
        while( indexOfOriginal>=0 && indexOfNew > indexOfOriginal ){
            if( string[indexOfOriginal] == ' '){
                string[indexOfNew--] = '0';
                string[indexOfNew--] = '2';
                string[indexOfNew--] = '%';
            }
            else{
                string[indexOfNew--] = string[indexOfOriginal];
            }
            --indexOfOriginal;
        }
    }
};

int main(){
    char string[] = "We are happy.";
    Solution().replaceBlank(string,20);
    for( int i = 0; i < 19; i ++ ){
        cout<<string[i];
    }
    cout<<endl;

    return 0;
}