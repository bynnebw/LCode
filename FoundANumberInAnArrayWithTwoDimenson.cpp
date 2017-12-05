//<剑指offer>面试题4：二维数组中的查找
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool Find(int* matrix, int rows, int columns, int number){
        bool found = false;

        //从二维矩阵的右上角开始，不断缩减寻找区域范围.
        if( matrix!=NULL && rows > 0 && columns > 0 ){
            int row = 0;
            int column = columns - 1;
            while( row < rows && column >= 0 ){
                if( matrix[row*columns + column] == number ){
                    found = true;
                    break;
                }
                else if( matrix[row*columns+column] > number )
                    --column;
                else
                    ++row;
            }
        }
        return found;
    }
};

int main(){
    int matrix[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    bool res = Solution().Find(*matrix,4,4,7);
    cout<<res<<endl;
    return 0;
}