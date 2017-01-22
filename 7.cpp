#include <iostream>
#include <cassert>
#include <numeric>
#include <string>
#include <list>
#include <vector>
#include <deque>
#include <utility>
#include <map>
#include <type_traits>
#include <algorithm>
#include <memory>
#include <cstdarg>
#include <windows.h>
#include <tuple>
#include <thread>
#include <atomic>
using namespace std;

//7-1 7-2
/*void f(char* c) { printf("invoke f(char*)\n"); }
void f(int i) { printf("invoke f(int)\n"); }
int main()
{
	f(0);
	f(NULL);
	f((char*)0);
	f(nullptr);
	return 0;
}*/

//7-3
/*int main()
{
	char *cp = nullptr;
	//int n1 = nullptr;
	//int n2 = reinterpret_cast<int>(nullptr);
	nullptr_t nptr = nullptr;
	if (nullptr == nptr)
		cout << "nullptr_t nuptr == nullptr" << endl;
	else
		cout << "nullptr_t nuptr != nullptr" << endl;
	if (nullptr > nptr)
		cout << "nullptr_t nuptr < nullptr" << endl;
	else
		cout << "nullptr_t nuptr !< nullptr" << endl;
	//if (0 == nullptr)
	//if (nullptr)
	//nullptr +=1 *=2
	sizeof(nullptr);
	typeid(nullptr);
	throw(nullptr);
	return 0;
}*/

//7-4
/*template<typename T> void g(T*t) {}
template<typename T> void h(T t) {}
int main()
{
	//g(nullptr);
	g((float*)nullptr);
	h(0);
	h(nullptr);
	h((float*)nullptr);
}*/

//7-5
/*int *px = (void*)0;
int* py = nullptr;*/

//7-6
/*int main()
{
	nullptr_t my_null;
	printf("%x\n", &my_null);
	//printf("%x", &nullptr);
	printf("%d\n", my_null == nullptr);
	const nullptr_t && default_nullptr = nullptr;
	printf("%x\n", &default_nullptr);
	return 0;
}*/

//7-7 7-8
/*class TwoCstor
{
private:
	int data;
public:
	TwoCstor() = default;
	TwoCstor(int i) :data(i) {}
};
int main()
{
	cout << is_pod<TwoCstor>::value << endl;
	return 0;
}*/

//7-9
/*class NoCopyCstor
{
public:
	NoCopyCstor() = default;
private:
	NoCopyCstor(const NoCopyCstor&);
};
int main()
{
	NoCopyCstor a;
	NoCopyCstor b(a);
	return 0;
}*/

//7-10
/*class NoCopyCstor
{
public:
	NoCopyCstor() = default;
	NoCopyCstor(const NoCopyCstor&) = delete;
};
int main()
{
	NoCopyCstor a;
	NoCopyCstor b(a);
	return 0;
}*/

//7-11
/*class DefaultedOptr
{
public:
	DefaultedOptr() = default;
	DefaultedOptr & operator = (const DefaultedOptr&);
};
inline DefaultedOptr &
DefaultedOptr::operator =(const DefaultedOptr &) = default;*/

//7-12 7-13
/*class ConvType
{
public:
	ConvType(int i) {};
    explicit ConvType(char c) = delete;
};
void Func(ConvType) {}
int main()
{
	Func(3);
	Func('a');
	ConvType ci(3);
	ConvType cc('a');
}*/

//7-14
/*void Func(int i) {};
void Func(char c) = delete;
int main()
{
	Func(3);
	Func('c');
	return 0;
}*/

//7-15
/*class NoHeapAlloc
{
public:
	void *operator new(std::size_t) = delete;
};
int main()
{
	NoHeapAlloc nha;
	NoHeapAlloc *pnha = new NoHeapAlloc;
	return 0;
}*/

//7-16
/*extern void* p;
class NoStackAlloc
{
public:
	~NoStackAlloc() = delete;
}
int main()
{
	NoStackAlloc nsa;
	new (p) NoStackAlloc();
	return 0;
}*/

//7-17
/*int main()
{
	int girls = 3, boys = 4;
	auto totalChild = [](int x, int y)->int {return x + y; };
	return totalChild(girls, boys);
}*/

//7-18
/*int main()
{
	[] {};
	int a = 3;
	int b = 4;
	[=] {return a + b; };
	auto fun1 = [&](int c) {b = a + c; };
	auto fun2 = [=, &b](int c)->int {return b += a + c; };
	return 0;
}*/

//7-19 7-20
/*int main()
{
	int boys = 4, int girls = 3;
	auto totalChild = [girls, &boys]()->int {return girls + boys; };
	auto total = [=]()->int {return girls + boys; };
	return totalChild();
}*/

//7-21
/*class _functor
{
public:
	int operator() ( int x, int y ) {return x + y; }
};
int main()
{
	int girls = 3, boys = 4;
	_functor totalChild;
	return totalChild(5, 6);
}*/

//7-22
/*class AirportPrice
{
private:
	float _dutyfreerate;
public:
	AirportPrice(float rate) :_dutyfreerate(rate) {}
	float operator()(float price) { return price*(1 - _dutyfreerate / 100); }
};
int main()
{
	float tax_rate = 5.5f;
	AirportPrice changi(tax_rate);
	auto changi2 = [tax_rate](float price)->float {return price*(1 - tax_rate / 100); };
	float purchased = changi(3699);
	float purchased2 = changi2(2899);
	return 0;
}*/

//7-23
/*extern int z;
extern float c;
void Calc(int&, int, float&, float);
void TestCalc()
{
	int x, y = 3;
	float a, b = 4.0;
	int success = 0;
	auto validate = [&]()->bool
	{
		if ((x == y + z) && (a == b + c))
			return 1;
		else
			return 0;
	};
	Calc(x, y, a, b);
	success += validate();
	y = 1024;
	b = 1e13;
	Calc(x, y, a, b);
	success += validate();
}*/

//7-24
/*int Prioritize(int);
int AllWorks(int times)
{
	int i;
	int x;
	try
	{
		for (i = 0; i < times; i++)
			x += Prioritize(i);
	}
	catch (...)
	{
		x = 0;
	}
	const int y = [=]
	{
		int i, val;
		try
		{
			for ( i = 0; i < times; i++)
				val += Prioritize(i);
		}
		catch (...)
		{
			val = 0;
		}
		return val;
	}();
}*/

//7-25
/*int main()
{
	int j = 12;
	auto by_val_lambda = [=] {return j + 1; };
	auto by_ref_lambda = [&] {return j + 1; };
	cout << "by_val_lambda: " << by_val_lambda() << endl;
	cout << "by_ref_lambda: " << by_ref_lambda() << endl;
	j++;
	cout << "by_val_lambda: " << by_val_lambda() << endl;
	cout << "by_ref_lambda: " << by_ref_lambda() << endl;
	return 0;
}*/

//7-26
/*int main()
{
	int girls = 3, boys = 4;
	auto totalChild = [](int x, int y)->int {return x + y; };
	typedef int(*allChild)(int x, int y);
	typedef int(*oneChild)(int x);
	allChild p = totalChild;
	//oneChild q= totalChild;
	decltype(totalChild) allPeople = totalChild;
	//decltype(totalChild) totalPeople = p;
	return 0;
}*/

//7-27
/*int main()
{
	int val;
	auto const_val_lambda = [=]() {val = 3; };
	auto mutable_val_lambda = [=]()mutable {val = 3; };
	auto const_ref_lambda = [=] {val = 3; };
	auto const_param_lambda = [&](int v) {v = 3; };
	const_param_lambda(val);
	return 0;
}*/

//7-28
/*class const_val_lambda
{
public:
	const_val_lambda(int v) :val(v) {}
	void operator()()const { val = 3; }
private:
	int val;
};*/

//7-29
/*vector<int> nums;
vector<int> largeNums;
const int ubound = 10;
inline void LargeNumsFunc(int i)
{
	if (i > ubound)
		largeNums.push_back(i);
}
void Above()
{
	for (auto itr = nums.begin(); itr != nums.end(); itr++)
	{
		if (*itr >= ubound)
			largeNums.push_back(*itr);
	}
	for_each(nums.begin(), nums.end(), LargeNumsFunc);
	for_each(nums.begin(), nums.end(), [=](int i)
	{
		if (i > ubound)
		{
			largeNums.push_back(i);
		}
	});
}*/

//7-30
/*vector<int> nums;
vector<int> largeNums;
class LNums
{
private:
	int ubound;
public:
	LNums(int u) :ubound(u) {}
	void operator()(int i)const
	{
		if (i > ubound)
		{
			largeNums.push_back(i);
		}
	}
};
void Above(int ubound)
{
	for (auto itr = nums.begin(); itr != nums.end(); itr++)
	{
		if (*itr >= ubound)
			largeNums.push_back(*itr);
	}
	
	for_each(nums.begin(), nums.end(), LNums(ubound));
	for_each(nums.begin(), nums.end(), [=](int i)
	{
		if (i > ubound)
		{
			largeNums.push_back(i);
		}
	});
}*/

//7-31
/*extern vector<int> nums;
void OneCond(int val)
{
	for (auto i = nums.begin(); i != nums.end(); i++)
		if (*i == val) break;
	find_if(nums.begin(), nums.end(), bind2nd(equal_to<int>(), val));
	find_if(nums.begin(), nums.end(), [=](int i) {return val == i; });
}*/

//7-32
/*extern vector<int> nums;
void TwoCond(int low, int high)
{
	for (auto i = nums.begin(); i != nums.end(); i++)
		if (*i >= low && *i < high) break;
	//find_if(nums.begin(), nums.end(), compose2(logical_and<bool>(), bind2nd(less<int>(), high), bind2nd(greater_equal<int>(), low)));
	find_if(nums.begin(), nums.end(), [=](int i) {return i >= low && i < high; });
}*/

//7-33
/*vector<int> nums;
void Add(const int val)
{
	auto print = [&]
	{
		for (auto s : nums) { cout << s << '\t'; }
		cout << endl;
	};
	for (auto i = nums.begin(); i != nums.end(); ++i) *i = *i + val;
	print();
	for_each(nums.begin(), nums.end(), bind2nd(plus<int>(), val));
	print();
	transform(nums.begin(), nums.end(), nums.begin(), bind2nd(plus<int>(), val));
	for_each(nums.begin(), nums.end(), [=](int &i) {i += val; });
	print();
}
int main()
{
	for (int i = 0; i < 10; i++)
		nums.push_back(i);
	Add(10);
	return 1;
}*/

//7-34
/*void Stat(vector<int> &v)
{
	int errors, score;
	auto print = [&] {cout << "Errors: " << errors << endl << "Score: " << score << endl; };
	errors = accumulate(v.begin(), v.end(), 0);
	score = accumulate(v.begin(), v.end(), 100, minus<int>());
	print();
	errors = 0;
	score = 100;
	for_each(v.begin(), v.end(), [&](int i) {errors += i; score -= i; });
	print();
}
int main()
{
	vector<int> v(10);
	generate(v.begin(), v.end(), [] {return rand() % 10; });
	Stat(v);
	return 0;
}*/

//7-35
/*int d = 0;
void TryCapture() { auto ill_lambda = [d] {}; }*/

//7-36
/*int d = 0;
class healthyFunctor
{
private:
	int data;
public:
	healthyFunctor(int d) :data(d) {}
	void operator()()const {}
};
int TryCapture() { healthyFunctor hf(d); }*/