//C++中经常使用的操作符重载
//操作符重载  复数加减
#include <iostream>

using namespace std;

class Complex{
    int a;
    int b;
public:
    Complex(int a = 0,int b = 0){
        this->a = a;
        this->b = b;
    }

    int getA(){
        return a;
    }
    int getB(){
        return b;
    }

    friend Complex operator+(const Complex& c1,const Complex& c2);
    friend ostream& operator<<(ostream& out, const Complex& c);
};
//如果直接这样写的话，因为在Complex类中，int a, int b都是private成员变量，外界实际上是拿不到的
//所以这时候需要使用友元关键字，走一个后门。
Complex operator+(const Complex& c1,const Complex& c2){
    Complex c3;
    c3.a = c1.a + c2.a;
    c3.b = c1.b + c2.b;
    return c3;
}

ostream& operator<<(ostream& out, const Complex& c){
    out<<c.a<<" + "<<c.b<<" i ";
}

int main(){
    Complex C1(1,2);
    Complex C2(3,4);
    Complex C3 = C1 + C2;

    cout<<"operator overload is brilliant"<<endl;
    cout<<C3<<endl;

    return 0;
}