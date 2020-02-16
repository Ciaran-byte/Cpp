#include<iostream>
using namespace std;
class A
{
private:
	int i;
public:
	A(int m)
	{
		 i = m;
	}
	void f(A* p)
	{
		cout << p->i << endl; //创建了一个函数，能够传递A类型的指针，用来访问私有的成员变量
		p->i = this->i; //利用类里面的函数，能够成功的修改其他变量的私有变量
		cout << p->i << endl;

	}
};
int main()
{

	A a(0);
	A b(10);
	//cout << a.i;//根据注解1，private属性的i只能被类的函数访问，因此这句话会报错
	b.f(&a); //根据注解2，通过在类里面设置相关的函数，可以访问其他对象中的变量
	return 0;
}



//注解1：访问级别
//public:表示任何东西都可以直接访问这个类的这些东西
//private:表示只有类内部的函数才能够访问private级别的变量
//protected:表示只有这个类和它的子类才能够访问这些变量

//注解2：private
// c++对类的访问级别限制仅仅存在与编译的时候，运行的时候就没有访问限制了。因此才会有上面程序的写法，我们通过函数f，可以访问其他对象的内部变量。
//当程序编译的时候，发现main函数里面没有直接访问类中变量的东西，编译通过。而后运行的时候，通过类里面的函数去访问其他对象的变量就是无人检查的了。
//简单来说，private在class类定义中是没有限制的，类中的函数可以访问这个类的变量，即使这个变量是像本程序所写的那样，是一个新的实例的变量。
