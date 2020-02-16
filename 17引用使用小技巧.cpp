
#include<iostream>
using namespace std;

class A
{
public:
	int i;
public:
	A() :i(10){}
	virtual ~A(){}
	 void print(void)
	{
		cout << i << endl;
	}

};

class B
{
public:
	B(int& m) :i(m) {};
	virtual ~B() {};

private:
	int& i;

};

void f(const A& a)
{
	cout <<a.i << endl;
	
}

const A& ff(int m)
{
	A a;
	a.i = m;
	return a;
}

int main()
{
	
	
	//程序示例1：类中含有引用类型的变量时的使用方法
	int i;
	B b(i); 

	//程序示例2：用常量引用做函数传递变量，f中传递的变量为常量引用，这样既能够减少创建类的开销，又能防止在函数体内部修改了变量。
	A a;
	f(a);

	//程序示例3：用常量引用做函数的返回变量，如果我们不希望返回的对象被修改，也可以使用引用的方法

	const A& aa = ff(20);
	cout << aa.i << endl;
	

}





//   注解1：有时候我们使用函数做数据传递的时候，很可能需要把一个类作为传递的对象，但是一个类往往很庞大，如果我们在函数里面，新建一个类来接受外部的类，对内存是一种巨大的
//开销，因为需要重新构建栈堆，使用完毕之后再释放栈堆，这个时候，我们就可以考虑使用引用作为数据传递的方法。因为引用实际上就是一种指向内存地址不允许改变的指针，
//使用引用能够通过直接指向变量内存的方法，而不需要创建新的类对象，极大的提高的运算速度。同时，也具有简介明了的优点，因为引用里面不会出现*这个符号。
//   注解2：但是使用引用就要考虑一个风险，如果我们把数据送入函数，函数内部这个变量如果发生改变，函数外的这个变量也会改变。为了保护变量在函数内不发生修改，我们使用
//const A& a 的方法，来在函数内部接受变量，因为这样的引用对象，在函数体内部是不可以修改的。
//   注解3：如果类中含有引用类型的变量，必须要在类的构造函数中绑定变量才能使用。如class B
