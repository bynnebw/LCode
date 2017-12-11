//202. Happy number
//eg. 19 is a happy number.
// 32 = 3^2 + 2^2 = 13
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution{
public:
    bool isHappy(int n){
        int num = 0;
        unordered_map<int,bool> mp;
        mp[n] = 1;
        while( n != 1 ){

            //不断对n进行拆解，计算n的每个数字的平方和
            while( n ){
                num += (n%10) * (n%10);
                n /= 10;
            }

            if( mp[num] ) break;
            else mp[num] = 1;   //用于记录之前不断进行拆解计算的过程中，有没有出现重复的数字.
            //如果出现重复数字，那么就没有必要继续进行下去了.

            n = num; num = 0;   //继续新一轮的循环.
        }

        return 1 == n;
    }
};

int main(){

    int number = 19;
    bool res = Solution().isHappy(number);
    cout<<res<<endl;

    return 0;
}