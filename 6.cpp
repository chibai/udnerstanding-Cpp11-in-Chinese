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
#include <memory>
#include <cstdarg>
#include <windows.h>
#include <tuple>
#include <thread>
#include <atomic>
using namespace std;

//6-1
/*const int GetConst() { return 1; }
void Constless(int cond)
{
	int arr[GetConst()] = { 0 };
	enum {e1 = GetConst(), e2 };
	switch (cond)
	{
	case GetConst():break;
	default:
		break;
	}
}*/

//6-2
/*enum BitSet
{
	V0 = 1 << 0,
	V1 = 1 << 1,
	V2 = 1 << 2,
	VMAX = 1 << 3
};
const BitSet operator | (BitSet x, BitSet y) { return static_cast<BitSet>(((int)x | y)&(VMAX - 1)); }
template<int i = V0 | V1> void LikeConst() {}*/

//6-3
/*constexpr int f();
int a = f();
const int b = f();
constexpr int c = f();
constexpr int f() { return 1; }
constexpr int d = f();*/

//6-4
/*struct MyType
{
	constexpr MyType(int x) :i(x) {}
	int i;
};
constexpr MyType mt = { 0 };*/

//6-5
/*struct Data
{
	constexpr Data(int y, int m, int d) : year(y), month(m), day(d) {}
	constexpr int GetYear() { return year; }
	constexpr int GetMonth() { return month; }
	constexpr int GetDay() { return day; }
private:
	int year, month, day;
};
Data PRCfound(1949, 10, 1);
int foundmonth = PRCfound.GetMonth();
int main()
{
	cout << foundmonth << endl;
	return 0;
}*/

//6-6
/*struct NotLiteral
{
	NotLiteral() { i = 5; }
	int i;
};
NotLiteral nl;
template<typename T> 
constexpr T ConstExp(T t) { return t; }
void g()
{
	NotLiteral nl;
	NotLiteral nl1 = ConstExp(nl);
	constexpr NotLiteral nl2 = ConstExp(nl);
	constexpr int a = ConstExp(1);
}*/

//6-7
/*constexpr int Fibonacci(int n)
{
	return (1 == n) ? 1 : ((2 == n) ? 1 : Fibonacci(n - 1) + Fibonacci(n - 2));
}
int main()
{
	int fib[] = { Fibonacci(11),Fibonacci(12),Fibonacci(13) ,Fibonacci(14) ,Fibonacci(15) ,Fibonacci(16) };
	for (int i : fib) cout << i << endl;
	return 0;
}*/

//6-8
/*template <long num>
struct Fibonacci { static const long val = Fibonacci<num - 1>::val + Fibonacci<num - 2>::val; };
template<>struct Fibonacci<2> { static const long val = 1; };
template<>struct Fibonacci<1> { static const long val = 1; };
template<>struct Fibonacci<0> { static const long val = 0; };
int main()
{
	int fib[] = { Fibonacci<11>::val, Fibonacci<12>::val,Fibonacci<13>::val,Fibonacci<14>::val,Fibonacci<15>::val,Fibonacci<16>::val };
	for (int i : fib) cout << i << endl;
	return 0;
}*/

//6-9
/*double SumOfFloat(int count, ...)
{
	va_list ap;
	double sum = 0;
	va_start(ap, count);
	for (int i = 0; i < count; i++)
		sum += va_arg(ap, double);
	va_end(ap);
	return sum;
}
int main()
{
	printf("%f\n", SumOfFloat(3, 1.2f, 3.4, 5.6));
	return 0;
}*/

//6-10
/*template<typename... Elements> class tuple;
template<typename Head, typename... Tail>
class tuple<Head, Tail...> :private tuple<Tail...> { Head head; };
template<> class tuple<> {};*/

//6-11
/*template <long... nums> struct Multiply;
template <long first, long... last>
struct Multiply<first, last...> { static const long val = first * Multiply<last...>::val; };
template<>
struct Multiply <> { static const long val = 1; };
int main()
{
	cout << Multiply<2, 3, 4, 5>::val << endl;
	cout << Multiply<22, 44, 66, 88, 9>::val << endl;
	return 0;
}*/

//6-12
/*void Printf(const char* s)
{
	while (*s)
	{
		if (('%' == *s) && ('%' != *++s))
			throw runtime_error("invalid format string: missing arguments");
		cout << *s++;
	}
}
template<typename T, typename... Args>
void Printf(const char*s, T value, Args... args)
{
	while (*s)
	{
		if (('%' == *s) && ('%' != *++s))
		{
			cout << value;
			return Printf(++s, args...);
		}
		cout << *s++;
	}
	throw runtime_error("extra arguments provided to Printf");
}
int main()
{
	Printf("hello %s\n", string("world"));
	return 0;
}*/

//6-13
/*template<typename ... T> void DummyWrapper(T... t) {}
template<typename T> T pr(T t)
{
	cout << t;
	return t;
}
template<typename... A>
void VTPrint(A... a) { DummyWrapper(pr(a)...); }
int main()
{
	VTPrint(1, ", ", 1.2, ", abc\n");
	return 0;
}*/

//6-14
/*template<class...A> void Print(A...arg) { assert(false); }
void Print(int a1, int a2, int a3, int a4, int a5, int a6)
{
	cout << a1 << ", " << a2 << ", " << a3 << ", " 
		<< a4 << ", " << a5 << ", " << a6 << endl;
}
template<class...A> int Vaargs(A...args)
{
	int size = sizeof...(A);
	switch (size)
	{
	case 0: Print(99, 99, 99, 99, 99, 99); break;
	case 1: Print(99, 99, args..., 99, 99, 99); break;
	case 2: Print(99, 99, args..., 99, 99); break;
	case 3: Print(args..., 99, 99, 99); break;
	case 4: Print(99, args..., 99); break;
	case 5: Print(99, args...); break;
	case 6: Print(args...); break;
	default: Print(0, 0, 0, 0, 0, 0);  break;
	}
	return size;
}
int main(void)
{
	Vaargs();
	Vaargs(1);
	Vaargs(1, 2);
	Vaargs(1, 2, 3);
	Vaargs(1, 2, 3, 4);
	Vaargs(1, 2, 3, 4, 5);
	Vaargs(1, 2, 3, 4, 5, 6);
	Vaargs(1, 2, 3, 4, 5, 6, 7);
	return 0;
}*/

//6-15
/*template<typename I, typename<typename>class... B> struct {};
template<typename I, template<typename>class A, template<typename>class... B>
struct Container<I, A, B...>
{
	A<I> a;
	Container<I, B...> b;
};
template<typename I> struct Container<I> {};*/

//6-16
/*template<typename A, typename B> struct S {};
template<template<typename...>class T, typename... TArgs, template<typename...>class U, typename... UArgs>
int main()
{
	S<int, float> p;
	S<std::tuple<int, char>, std::tuple<float>> s;
}*/

//6-17
/*struct A
{
	A() {}
	A(const A &a) { cout << "Copy Constructed" << __func__ << endl; }
	A(A&& a) { cout << "Move Constructed" << __func__ << endl; }
};
struct B
{
	B() {}
	B(const B &b) { cout << "Copy Constructed" << __func__ << endl; }
	B(B&& b) { cout << "Move Constructed" << __func__ << endl; }
};
template<typename... T> struct MultiTypes;
template<typename T1, typename... T>
struct MultiTypes<T1, T...> :public MultiTypes<T...>
{
	T1 t1;
	MultiTypes<T1, T...>(T1 a, T... b) : t1(a), MultiTypes<T...>(b...)
	{
		cout << "MultiTypes<T1, T...>(T1 a, T... b)" << endl;
	}
};
template<> struct MultiTypes<> { MultiTypes() { cout << "MultiTypes<>()" << endl; } };
template<template<typename...>class VariadicType, typename... Args>
VariadicType<Args...> Build(Args&&... args)
{
	return VariadicType<Args...>(std::forward<Args>(args)...);
}
int main()
{
	A a;
	B b;
	Build<MultiTypes>(a, b);
	return 0;
}*/

//6-18

//6-19
/*atomic_llong total{ 0 };
void func(int)
{
	for (long long i = 0; i < 100000000LL; ++i)
		total += i;
}
int main()
{
	thread t1(func, 0);
	thread t2(func, 0);
	t1.join();
	t2.join();
	cout << total << endl;
	return 0;
}*/

//6-20
/*std::atomic_flag lock = ATOMIC_FLAG_INIT;
void f(int n)
{
	while (lock.test_and_set(std::memory_order_acquire))
		cout << "Waiting from thread " << n << endl;
	cout << "Thread " << n << "starts working" << endl;
}
void g(int n)
{
	cout << "Thread " << n << " is going to start." << endl;
	lock.clear();
	cout << "Thread " << n << "starts working" << endl;
}
int main()
{
	lock.test_and_set();
	thread t1(f, 1);
	thread t2(g, 2);

	t1.join();
	Sleep(0.0001);
	t2.join();
	return 0;
}*/

//6-21
/*atomic<int> a{ 0 };
atomic<int> b{ 0 };
void ValueSet(int)
{
	int t = 1;
	a = t;
	b = 2;
}
void Observer(int) { cout << "(" << a << "," << b << ")" << endl; }
int main()
{
	thread t2(Observer, 0);
	thread t1(ValueSet, 0);

	t1.join();
	t2.join();
	cout << "Got (" << a << "," << b << ")" << endl;
	return 0;
}*/

//6-22
/*atomic<int> a;
atomic<int> b;
void Thread1(int)
{
	int t = 1;
	a = t;
	b = 2;
}
void Thread2(int)
{
	while (b != 2)
		;
	cout << a << endl;
}
int main()
{
	thread t1(Thread1, 0);
	thread t2(Thread2, 0);
	t1.join();
	t2.join();
	return 0;
}*/

//6-23
/*atomic<int> a{ 0 };
atomic<int> b{ 0 };
void ValueSet(int)
{
	int t = 1;
	a.store(t, memory_order_relaxed);
	b.store(2, memory_order_relaxed);
}
void Observer(int) { cout << "(" << a << "," << b << ")" << endl; }
int main()
{
	thread t1(ValueSet, 0);
	thread t2(Observer, 0);
	
	t1.join();
	t2.join();
	cout << "Got (" << a << "," << b << ")" << endl;
	return 0;
}*/

//6-24
/*atomic<int> a;
atomic<int> b;
void Thread1(int)
{
	int t = 1;
	a.store(t, memory_order_relaxed);
	b.store(2, memory_order_relaxed);
}
void Thread2(int)
{
	while (b.load(memory_order_relaxed) != 2)
		;
	cout << a.load(memory_order_relaxed) << endl;
}
int main()
{
	thread t1(Thread1, 0);
	thread t2(Thread2, 0);
	t1.join();
	t2.join();
	return 0;
}*/

//6-25
/*atomic<int> a;
atomic<int> b;
void Thread1(int)
{
	int t = 1;
	a.store(t, memory_order_relaxed);
	b.store(2, memory_order_release);
}
void Thread2(int)
{
	while (b.load(memory_order_acquire) != 2)
		;
	cout << a.load(memory_order_relaxed) << endl;
}
int main()
{
	thread t1(Thread1, 0);
	thread t2(Thread2, 0);
	t1.join();
	t2.join();
	return 0;
}*/

//6-26
/*atomic<string*> ptr;
atomic<int> Adata;
void Producer()
{
	string *p = new string("Hello");
	Adata.store(42, memory_order_relaxed);
	ptr.store(p, memory_order_release);
}
void Consumer()
{
	string* p2;
	while (!(p2 = ptr.load(memory_order_consume)))
		;
	assert("Hello" == *p2);
	assert(42 == Adata.load(memory_order_relaxed));
}
int main()
{
	thread t1(Producer);
	thread t2(Consumer);
	t1.join();
	t2.join();
	return 0;
}*/

//6-27
/*int errorCode = 0;
int input_a = 1;
int input_b = 2;
void MaySetError(int *input)
{
	if (1 == *(int*)input)
		errorCode = 1;
	else if (2 == *(int*)input)
		errorCode = -1;
	else
		errorCode = 0;
}
int main()
{
	thread t1(MaySetError,&input_a);
	thread t2(MaySetError,&input_b);
	t1.join();
	t2.join();
	return 0;
}*/

//6-28
/*void openDevice() { cout << "device is opened." << endl; }
void resetDeviceStat() { cout << "device stat is reset." << endl; }
void closeDevice() { cout << "device is closed." << endl; }
int main()
{
	atexit(closeDevice);
	atexit(resetDeviceStat);
	openDevice();
	exit(0);
}*/

//6-29
/*struct A { ~A() { cout << "Destruct A." << endl; } };
void closeDevice() { cout << "device is closed." << endl; }
int main()
{
	A a;
	at_quick_exit(closeDevice);
	quick_exit(0);
}*/
