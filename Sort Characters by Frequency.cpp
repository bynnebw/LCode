//451.Sort characters by frequency
//未完成
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for( auto c:s )
            mp[c] ++;
        // map : key ==> value

        //如何针对value的大小，对key进行排序呢？
    }
};

int main(){
    string s = "tree";
    string t = Solution().frequencySort(s);
    for( auto c:t )
        cout<<c<<endl;

    return 0;
}
