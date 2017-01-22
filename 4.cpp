#include <iostream>
#include <cassert>
#include <string>
#include <list>
#include <vector>
#include <deque>
#include <utility>
#include <map>
#include <type_traits>
#include <algorithm>
using namespace std;

//4-1
/*template <int i> class X {};
template <class T> class Y {};
Y<X<1> > x1;
Y<X<2>> x2;*/

//4-2
/*template <int i> class X {};
X < 1 >> 5 > x;*/

//4-3
/*int main()
{
	auto name = "word.\n";
	cout << "hello, " << name;

}*/

//4-4
/*int main()
{
	double foo();
	auto x = 1;
	auto y = foo();
	struct m { int i; }str;
	auto str1 = str;
	auto z;
	z = x;
}*/

//4-5 4-6
/*void loopover(vector<string> & vs)
{
	vector<string>::iterator i = vs.begin();
	for ( ; i < vs.end();i++)
	{
	}

	for (auto i = vs.begin(); i < vs.end(); i++)
	{

	}
}*/

//4-7
/*class PI
{
	const float val = 3.1415927f;
public:
	double operator* (float v) { return (double)val * v; }
};
int main()
{
	float radius = 1.7e10;
	PI pi;
	auto circumference = 2 * (pi * radius);
}*/

//4-8
/*int main()
{
	unsigned int a = 4294967295;
	unsigned int b = 1;
	auto c = a + b;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "a + b = " << c << endl;
	return 0;
}*/

//4-9
/*template<typename T1, typename T2>
double Sum(T1 & t1, T2 & t2)
{
	auto s = t1 + t2;
	return s;
}
int main()
{
	int a = 3;
	long b = 5;
	float c = 1.0f, d = 2.3f;

	auto e = Sum<int, long>(a, b);
	auto f = Sum<float, float>(c, d);
}*/

//4-10
/*#define Max1(a, b) ((a) > (b))?(a):(b)
#define Max2(a, b) ({ \
	auto _a = (a); \
	auto _b = (b); \
	(_a > _b)?_a:_b;})
int main()
{
	int m1 = Max1(1 * 2 * 3 * 4, 5 + 6 + 7 + 8);
	int m2 = Max2(1 * 2 * 3 * 4, 5 + 6 + 7 + 8);
}*/

//4-11
/*int x;
int *y = &x;
double foo();
int &bar();

auto *a = &x;
auto &b = x;
auto c = y;
auto *d = y;
auto *e = &foo(); \
auto &f = foo();
auto g = bar();
auto &h = bar;*/

//4-12
/*double foo();
float* bar();

const auto a = foo();
const auto &b = foo();
volatile auto *c = bar();

auto d = a;
auto &e = a;
auto f = c;
volatile auto &g = c;*/

//4-13
/*auto x = 1, y = 2;
const auto* m = &x, n = 1;
auto i = 1, j = 3.14f;
auto o = 1, &p = o, *q = &p;*/

//4-14
/*auto x = 1;
auto x1(1);

auto y{ 1 };
auto z = new auto(1);*/

//4-15
/*void fun(auto x = 1) {}
struct str { auto var = 10; };
int main()
{
	char x[3];
	auto y = x;
	auto z[3] = x;
	vector<auto> v = { 1 };
}*/

//4-16
/*class White {};
class Black {};
int main()
{
	White a;
	Black b;
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	White c;
	bool a_b_sametype = (typeid(a).hash_code() == typeid(b).hash_code());
	bool a_c_sametype = (typeid(a).hash_code() == typeid(c).hash_code());
	cout << "Same type? " << endl;
	cout << "A and B " << (int)a_b_sametype << endl;
	cout << "A and C " << (int)a_c_sametype << endl;
	return 0;
}*/

//4-17
/*int main()
{
	int i;
	decltype(i) j = 0;
	cout << typeid(j).name() << endl;

	float a;
	double b;
	decltype(a + b) c;
	cout << typeid(c).name() << endl;
}*/

//4-18
/*int main()
{
	vector<int> vec;
	typedef decltype(vec.begin()) vectype;
	for (vectype i = vec.begin(); i < vec.end(); i++)
	{

	}
	for (decltype(vec)::iterator i = vec.begin(); i < vec.end(); i++)
	{

	}
}*/

//4-19
/*enum class type{ K1, K2, K3, }anon_e;
union
{
	decltype(anon_e) key;
	char* name;
}anon_u;
struct
{
	int d;
	decltype(anon_u) id;
}anon_s[100];
int main()
{
	decltype(anon_s) as;
	as[0].id.key = decltype(anon_e)::K1;
}*/

//4-20
/*template<typename T1, typename T2>
void Sum(T1 &t1, T2 &t2, decltype(t1 + t2)&s) { s = t1 + t2; }
int main()
{
	int a = 3;
	long b = 5;
	float c = 1.0f, d = 2.3f;
	long e;
	float f;
	Sum(a, b, e);
	Sum(c, d, f);
}*/

//4-21
/*template<typename T1, typename T2>
void Sum(T1 &t1, T2 &t2, decltype(t1 + t2)&s) { s = t1 + t2; }
void Sum(int a[], int b[], int c[]) {}
int main()
{
	int a[5], b[5], c[5];
	Sum(a, b, c);

	int d, e, f;
	Sum(d, e, f);
}*/

//4-22
/*int hash(char*);
map<char*, decltype(hash)> dict_key;
map<char*, decltype(hash(nullptr))> dict_key1;*/

//4-23
/*typedef double(*func)();
int main()
{
	result_of<func()>::type f;
	return 0;
}*/

//4-24
/*int i;
decltype(i) a;
decltype((i)) b;*/

//4-25
/*int i = 4;
int arr[5] = { 0 };
int *ptr = arr;
struct s { double d; }s;
void Overloaded(int);
void Overloaded(char);
int && Rvalref();
const bool Func(int);
//rule 1
decltype(arr) var1;
decltype(ptr) var2;
decltype(s.d) var4;
decltype(Overloaded) var5;
//rule 2
decltype(Rvalref()) var6 = 1;
//rule 3
decltype(true ? i : i) var7 = i;
decltype((i)) var8 = i;
decltype(++i) var9 = i;
decltype(arr[3]) var10 = i;
decltype(*ptr) var11 = i;
decltype("lval") var12 = "lval";
//rule 4
decltype(1) var13;
decltype(i++) var14;
decltype((Func(1))) var15;*/

//4-26
/*int i = 4;
int arr[5] = { 0 };
int *ptr = arr;
int && RvalRef();
int main()
{
	cout << is_rvalue_reference<decltype(RvalRef())>::value << endl;
	
	cout << is_lvalue_reference<decltype(true ? i : i)>::value << endl;
	cout << is_lvalue_reference<decltype((i))>::value << endl;
	cout << is_lvalue_reference<decltype(arr[3])>::value << endl;
	cout << is_lvalue_reference<decltype(*ptr)>::value << endl;
	cout << is_lvalue_reference<decltype("lval")>::value << endl;

	cout << is_lvalue_reference<decltype(i++)>::value << endl;
	cout << is_rvalue_reference<decltype(i++)>::value << endl;
	return 0;
}*/

//4-27
/*const int ic = 0;
volatile int iv;
struct S { int i; };
const S a = { 0 };
volatile S b;
volatile S* p = &b;
int main()
{
	cout << is_const<decltype(ic)>::value << endl;
	cout << is_volatile<decltype(iv)>::value << endl;

	cout << is_const<decltype(a)>::value << endl;
	cout << is_volatile<decltype(b)>::value << endl;

	cout << is_const<decltype(a.i)>::value << endl;
	cout << is_volatile<decltype(p->i)>::value << endl;
}*/

//4-28
/*int i = 1;
int & j = i;
int * p = &i;
const int k = 1;
int main()
{
	decltype(i) var1 = i;
	decltype(j) & var2 = i;
	cout << is_lvalue_reference<decltype(var1)>::value << endl;
	cout << is_rvalue_reference<decltype(var2)>::value << endl;
	cout << is_lvalue_reference<decltype(var2)>::value << endl;
	decltype(p) *var3 = &i;
	decltype(p) *var3 = &p;
	auto* v3 = p;
	v3 = &i;
	const decltype(k) var4 = 1;
}*/

//4-29
/*class OuterType
{
	struct InnerType { int i; };
	InnerType GetInner();
	InnerType it;
};
auto OuterType::GetInner() -> InnerType { return it; }*/

//4-30
/*template<typename T1, typename T2>
auto Sum(const T1 & t1, const T2 & t2)->decltype(t1 + t2) { return t1 + t2; }
template<typename T1, typename T2>
auto Mul(const T1 & t1, const T2 & t2)->decltype(t1 + t2) { return t1 * t2; }
int main()
{
	auto a = 3;
	auto b = 4L;
	auto pi = 3.14;
	auto c = Mul(Sum(a, b), pi);
	cout << c << endl;
	return 0;
}*/

//4-31
/*int(*(*pf())())() { return nullptr; }
//auto (*)() -> int(*)()
//auto pf1()->auto(*)() -> int(*)()
auto pf1()->auto(*)()->int(*)() { return nullptr; }
int main()
{
	cout << is_same<decltype(pf), decltype(pf1)>::value << endl;
	return 0;
}*/

//4-32
/*double foo(int a) { return (double)a + 0.1; }
int foo(double b) { return (int)b; }
template <typename T> auto Forward(T t)->decltype(foo(t)) { return foo(t); }
int main()
{
	cout << Forward(2) << endl;
	cout << Forward(0.5) << endl;
	return 0;
}*/

//4-33
/*int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	int *p;
	for (p = arr; p < arr + sizeof(arr) / sizeof(arr[0]); p++)
	{
		*p *= 2;
	}
	for (p = arr; p < arr + sizeof(arr) / sizeof(arr[0]); p++)
	{
		cout << *p << '\t';
	}
	return 0;
}*/

//4-34
/*void action1(int &e) { e *= 2; }
void action2(int &e) { cout << e << '\t'; }
int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	for_each(arr, arr + sizeof(arr) / sizeof(arr[0]), action1);
	for_each(arr, arr + sizeof(arr) / sizeof(arr[0]), action2);
	return 0;
}*/

//4-35
/*int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	for (int &e:arr)
	{
		e *= 2;
	}
	for (int &e : arr)
	{
		cout << e << '\t';
	}
	return 0;
}*/

//4-36
/*int func(int a[])
{
	for (auto e : a)
		cout << e;
}
int main()
{
	int arr[] = { 1,2,3,4,5 };
	func(arr);
}*/

//4-37
/*int main()
{
	vector<int> v = { 1,2,3,4,5 };
	for (auto i = v.begin(); i != v.end(); i++)
		cout << *i << endl;
	for (auto e : v)
		cout << e << endl;
	return 0;
}*/
