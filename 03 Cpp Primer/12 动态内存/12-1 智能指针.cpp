#include<iostream>
#include<memory>
using namespace std;
int main()
{
	//01 通过我们使用的指针都是位于栈区或者全局数据区的，有一定的生存域。但是有时候我们会需要一些动态内存管理
	//使用new关键词创建对象，对象位于堆区，只有显式的delete指针，才会释放内存地址，但是这样会出现野指针的问题
	//就是两个对象同时指向一个内存，删去其中一个指针，其他所有指针都指向区域为空，如下所示
	int *a = new int(42);
	int *c(a);
	
	delete(a);
	cout << *c << endl;

	//02 因此就产生了智能指针这种技术。智能指针是采用计算原理管理动态内存，有指针被创建时，计数器+1，这个指针指向其他
	//位置或者被删除时，计数器-1，当没有对象指向内存空间时，才会释放内存，因此就能够避免野指针的产生
	
	//使用make_shared创建智能指针
	shared_ptr<int> p1 = make_shared<int>(42);

	
	return 0;
}

