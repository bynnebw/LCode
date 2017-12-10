//242.valid anagram
//使用查找表的方法，来判断两个字符串是否一致，不考虑顺序
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution{
public:
    bool isAnagram(string s, string t){
        if( s.length() != t.length() )
            return false;

        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for( char c:s )
            mp1[c] ++;

        for( char c:t )
            mp2[c] ++;

        if( mp1.size() == mp2.size() ){
            for( int i = 0; i < mp1.size(); i ++ )
                if( mp1[i] != mp2[i] )
                    return false;
            return true;
        }

        return false;
    }
};

int main(){
    string s = {"anagram"};
    string t = {"nagaram"};

    bool res = Solution().isAnagram(s,t);
    cout<<res<<endl;

    return 0;
}