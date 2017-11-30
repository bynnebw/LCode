//LC 76. Minimum Window Substring
//滑窗法，还是没有实现啊。。。再说吧。唉

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /*bool SContainsT(string s,string t){
        unordered_map<char,int> mp;
        for( int i = 0; i < s.size(); i ++ )
            mp[s[i]] ++;

        for( int j = 0; j < t.size(); j ++ ){
            if( mp[t[j]] == 0 )
                return false;
        }
        return true;
    }*/

    string minWindow(string s, string t) {
        unordered_map<char,int> mp_t;
        for(int i = 0; i < t.size(); i ++ )
            mp_t[t[i]] ++;

        int i = 0, j = 0, remain = t.size();
        unordered_map<string,int> mp_compare; //最后用于比较找到最小的字符串

        while( j < s.size() ){
            if( mp_t[s[j]] > 0 ) remain --;
            mp_t[s[j]]--;

            while ( mp_t[s[j]] < 0 ){
                mp_t[s[i]] ++;

            }

            if( remain == 0 ) mp_compare[s.substr(i,j-i+1)] = j-i+1;

            j++;
        }
    }
};

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";

    string res = Solution().minWindow(s,t);

    for( auto c : res )
        cout<<c<<" ";

    return 0;
}