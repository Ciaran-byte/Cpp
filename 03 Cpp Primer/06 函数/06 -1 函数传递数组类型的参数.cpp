#include<iostream>

using namespace std;

//01 函数传递数组类型参数的三种定义方法

void f1(int* p)
{
	if (p != 0)
	{
		cout << p[0] << endl;
	}
}
void f2(int p[])
{
	if (p != 0)
	{
		cout << p[0] << endl;
	}
}
void f3(int p[10])  //注意这个地方的10是没有用的
{
	if (p != 0)
	{
		cout << p[0] << endl;
	}
}
//02 函数管理数组指针的三种方法
//02-1 特殊结束字符
void f_str(char* c)
{
	if (c)
	{
		while (*c != NULL)
		{
			cout << *c++ << " ";
		}
	}
	cout << endl;
}
//02-2 标准库的方法
void f_std(int* beg, int* ed)
{
	while (beg != ed)
	{
		cout << *beg++ <<" ";
	}
	cout << endl;
}
//02-3 加一个代表长度的形参
void f_int(int* a, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
//03 多维数组作为参数列表
void f_multiple(int(*p)[10], size_t row)
{
	cout << endl;
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
//04 数组的引用作为参数列表
void f_reference(int (&q)[10])
	{
	for (size_t i = 0; i < 10; ++i)
	{
		cout << q[i] << " ";

	}
	cout << endl;
}

int main()
{
	//例程1 函数传递数组类型参数的三种定义方法
	int a[3] = { 1,2,3 };
	f1(a);
	f2(a);
	f3(a);
	//例程2 函数管理数组指针的三种方法

	//02-1 适合字符串类型的，有特殊结束字符的
	char str[] = "hello";
	f_str(str);
	//02-2 使用标准库规范
	int A2[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int* beg = begin(A2);
	int* ed =end(A2);
	f_std(beg, ed);
	//02-3 附件数组长度的变量，一般对int类型数组使用
	int A3[10]= { 0,1,2,3,4,5,6,7,8,9 };
	size_t num = 10;
	f_int(A3, num);

	//例程3 多维数组的传入
	//多维数组本质就是指针数组的指针
	//比如 int （*p）[10]中，p表示指向一个有很多行的数组的第一行，这堆数组每一行都有10个元素

	//同样也要记住，*p必须加括号才能表示多维数组，因为不就括号 int *p[10]表示 p是个一维数组，里面存放
	//的是指针

	int B1[][10] =
	{
		{1,2,3,4,5,6,7,8,9,10},
		{1,2,3,4,5,6,7,8,9,10},
		{1,2,3,4,5,6,7,8,9,10},
		{1,2,3,4,5,6,7,8,9,10},
		{1,2,3,4,5,6,7,8,9,10}
	};
	f_multiple(B1, 5);

	//例程4 数组引用形参
	//数组引用就是说，这个引用类型是数组的别名，与多维数组比较类似
	// int(&q)[10]; 一定要加括号，不加括号说明q是个数组，里面放的全是引用，但是引用本身不能作为对象，所以是错误的数据类型
	// ；而加了括号以后，表示q是个引用，指向长度为10的数组，这个时候，函数参数列表里面的10就是一个有意义的数字了，
	//因为只有长度为10的数组才能赋值给这个参数列表，而普通的非引用数组里面的那个数字就没有用，因为只是个不定长度的指针而已。
	
	//函数中使用数组的引用作为参数列表很少用，因为灵活性太差了，必须输入长度为10的数组
	int B2[10] = { 0,1,2,3,4,5,6,7,8,9 };
	f_reference(B2);

	return 0;
}


