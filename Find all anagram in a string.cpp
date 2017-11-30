//LC 438. Find all anagram in a string
//采用滑窗的方法，另外一个创新点是，利用while的循环与map，
// 实现了将索引用皮筋拉回来的效果。

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        int i = 0,j = 0;
        unordered_map<char,int> mp;
        for( auto c : p )
            mp[c]++;

        int remain = p.size();

        while( j < s.size() ){
            if( mp[s[j]] >0 ) remain--;
            mp[s[j]] --;

            while( mp[s[j]] < 0 ){
                mp[s[i]] ++;
                if( mp[s[i]] > 0 ) remain++;
                i ++;
            }

            if( remain == 0 )
                result.push_back(i);
            j ++;
        }
        return result;
    }
};

int main(){

    string s = "adbceabcabc";
    string p = "abc";

    vector<int> res = Solution().findAnagrams(s,p);

    for( int i = 0; i < res.size();i ++ )
        cout<<res[i]<<" ";

    cout<<endl;
    return 0;
}