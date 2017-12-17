//149. Max Points on a Line
//给一堆点，判断这些点在一条直线上的最多的个数。
//本题当然还是使用查找表来进行编程，但是难点在于，如何求斜率的问题
//因为涉及到除法，又为了便于区分，所以采用了求最大公约数的方法
//及GCD的实现，之前一直没接触过。要注意。

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if( points.size() < 2 ) return points.size();

        int result = 0;

        for( int i = 0; i < points.size(); i ++ ){
            map<pair<int,int>,int> record;
            int localmax = 0, vertical = 0, overlap = 0;

            for( int j = i+1; j < points.size(); j ++ ){
                if( points[j].x == points[i].x && points[j].y == points[i].y ){
                    overlap ++;
                    continue;
                } else if (points[j].x == points[i].x)  vertical++;
                else{
                    int a = points[j].x - points[i].x;
                    int b = points[j].y - points[i].y;
                    int gcd = GCD(a,b);
                    a /= gcd;
                    b /= gcd;

                    record[make_pair(a,b)] ++;
                    localmax = max(record[make_pair(a,b)],localmax);
                }
                localmax = max(vertical,localmax);
            }
            result = max(result,localmax+overlap+1);
        }
        return result;
    }

private:
    int GCD(int a, int b){
        if( b == 0 ) return a;
        else return GCD(b,a%b);
    }
};

int main(){
    Point p1(0,0);
    Point p2(1,1);
    Point p3(2,2);
    Point p4(1,2);

    vector<Point> points = {p1,p2,p3,p4};

    int res = Solution().maxPoints(points);
    cout<<"The answer is :"<<res<<endl;

    return 0;
}