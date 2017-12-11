//290. word pattern
//注意string输入流的用法istringstream

#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char,int> p2i;
        map<string,int> w2i;

        istringstream in(str);
        int i = 0, n = pattern.size();

        for( string word; in >> word; ++ i ){
            //这个内部循环是什么意思呢？
            if( i == n || p2i[pattern[i]] != w2i[word] )
                return false;
            p2i[pattern[i]] = w2i[word] = i + 1;
        }
        return i == n;
    }
};

int main(){

    string pattern = {"abba"};
    string str = {"dog cat cat dog"};
    bool res = Solution().wordPattern(pattern,str);
    cout<<res<<endl;

    return 0;
}