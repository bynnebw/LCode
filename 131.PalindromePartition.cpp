//131.Palindrome Partitioning
//The program is not finished and it remains of the recursion procedure.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<string>> res;
    bool isPalindrome(const string& str){
        if( str == "" )
            return true;
        for( int i = 0; i < str.size(); i ++ )
            if( str[i] != str[str.size()-i-1] )
                return false;
        return true;
    }

    void dfs(const string& s,int index, vector<vector<string>> res){
        if( index == s.size() && )
    }
public:
    vector<vector<string>> partition(string s) {
        res.clear();
        if( s == "")
            return res;
        dfs(s,0,res);
        return res;
    }
};

int main(){
    string s = "aab";
    vector<vector<string>> res = Solution().partition(s);
    for( int i = 0; i < res.size(); i ++ )
        for( int j = 0; j < res[i].size(); j ++ )
            cout<<res[i][j]<<" ";
    cout<<endl;

    return 0;
}