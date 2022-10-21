#include <iostream>
using namespace std;


template<class T>
class MySharedPtr
{
	T* ptr;
	static int count;

public:
	MySharedPtr()
	{
		T* ptr = nullptr;
		count++;
	}
	MySharedPtr(T* p)
	{
		ptr = p;
		count++;
	}
	~MySharedPtr()
	{
		cout << "Destructor\n";
		if (count == 1)
		{
			delete[]ptr;
			count = 0;
			cout << "delete ptr\n";
		}
		else
		{
			count--;
			cout << "Count--\n";
		}
	}
	T* Get()
	{
		return ptr;
	}
	T GetCount()
	{
		return* ptr;
	}
};

template<class T>
int MySharedPtr<T>::count = 0;

int main()
{
	MySharedPtr<int> pt(new int(156));
	MySharedPtr<int> pt1 = pt;
	
	cout << pt1.Get() << " " << pt1.GetCount() << endl;
	cout << pt.Get() << " " << pt.GetCount() << endl;
	cout << endl;
}