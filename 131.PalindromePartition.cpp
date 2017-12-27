//131.Palindrome Partitioning
//完整版
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<string>> res;
    bool isPalindrome(const string& str, int start, int end){
        while (start <= end){
            if(str[start++] != str[end--])
                return false;
        }
        return true;
    }

    void dfs(const string& s,int index, vector<string>& temp ,vector<vector<string>>& res){
        if( index == s.size() ){
            res.push_back(temp);
            return;
        }

        for( int i = index; i < s.size(); i ++ ){
            if( isPalindrome(s,index,i) ){
                temp.push_back(s.substr(index,i-index+1));
                dfs(s,i+1,temp,res);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        res.clear();
        vector<string> temp;
        if( s.empty() )
            return res;
        dfs(s,0,temp,res);
        return res;
    }
};

int main(){
    string s = "aab";
    vector<vector<string>> res = Solution().partition(s);
    for( int i = 0; i < res.size(); i ++ ){
        for( int j = 0; j < res[i].size(); j ++ )
            cout<<res[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}