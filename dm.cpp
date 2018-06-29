#include<iostream>
using namespace std;

class mystring
{
  private:
    int x;
    int y;
  public:
    mystring(int a,int b)
    {
      x=a;
      y=b;
    }
    mystring(const mystring &c)
    {
      x=c.x;
      y=c.y;
    }
    mystring& operator =(const mystring &c)
    {
       if (this==&c)
       {
       return *this;  
       }
       x=c.x;
       y=c.y;
       return *this;
    }
    int sum();
    int add();
    ~mystring()
    {

      cout<<"delelet class!"<<endl;
    }

};
int mystring::sum()
{
  return x-y;
}
int mystring::add()
{
return x+y;
}
 
int main() 
{
mystring A(3,1);
mystring B=A;
mystring C(10,20);
mystring* ptr=&C;
cout<<A.add()<<endl;
cout<<B.sum()<<endl;
cout << ptr->add() <<endl;
cout << ptr->sum() <<endl;
  return 0;
}
