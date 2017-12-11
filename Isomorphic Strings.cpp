//205.Isomorphic Strings
//依然是利用查找表等数据结构来解决问题
//对于两种模式的相互匹配问题，“交叉对应”

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> hash,reflect;
        for( int i = 0; i < s.length(); ++i ){

            //如果hash与reflect中都没有s[i]与t[i]

            if( hash.find(s[i]) == hash.end() &&
                reflect.find(t[i]) == reflect.end()){
                hash[s[i]] = t[i];
                reflect[t[i]] = s[i];
            } else{
                if( hash[s[i]] != t[i] )
                    return false;
            }
        }

        return true;
    }
};

int main(){

    string s = "egg";
    string t = "add";

    bool res = Solution().isIsomorphic(s,t);
    cout<<res<<endl;

    return 0;
}