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
#include <cuchar>
#include <locale>
#include <fstream>
#include <iomanip>
#include <codecvt>
#include <cvt/wstring>
using namespace std;

//8-1
/*struct HowManyBytes
{
	char a;
	int b;
};
int main()
{
	cout << "sizeof(char): " << sizeof(char) << endl;
	cout << "sizeof(int): " << sizeof(int) << endl;
	cout << "sizeof(HowManyBytes):" << sizeof(HowManyBytes) << endl;
	cout << endl;
	cout << "offset of char a: " << offsetof(HowManyBytes, a) << endl;
	cout << "offset of int b:" << offsetof(HowManyBytes, b) << endl;
	return 0;
}*/

//8-2 8-3
/*struct alignas(32) ColorVector
{
	double r;
	double g;
	double b;
	double a;
};
int main()
{
	cout << "alignof(ColorVector): " << alignof(ColorVector) << endl;
	return 0;
}*/

//8-4
/*class InComplete;
struct Completed {};
int main()
{
	int a;
	long long b;
	auto &c = b;
	char d[1024];
	cout << alignof(int) << endl << alignof(Completed) << endl;
	cout << alignof(a) << endl << alignof(b) << endl << alignof(c) << endl << alignof(d) << endl;
	//cout << alignof(InComplete) << endl;
	return 0;
}*/

//8-5
/*alignas(double) void f();
alignas(double) unsigned char c[sizeof(double)];
extern unsigned char c[sizeof(double)];
alignas(float) extern unsigned char c[sizeof(double)];*/

//8-6
/*struct alignas(alignof(double) * 4) ColorVector
{
	double r;
	double g;
	double b;
	double a;
};
template<typename T> class FixedCapacityArray
{
public:
	void push_back(T t);
	char alignas(T) data[1024] = { 0 };
};
int main()
{
	FixedCapacityArray<char> arrCh;
	cout << "alignof(char): " << alignof(char) << endl;
	cout << "alignof(arrCh.data): " << alignof(decltype(arrCh.data)) << endl;
	FixedCapacityArray<ColorVector> arrCV;
	cout << "alignof(colorVector): " << alignof(ColorVector) << endl;
	cout << "alignof(arrCV.data): " << alignof(decltype(arrCV.data)) << endl;
	return 0;
}*/

//8-7
/*struct ColorVector
{
	double r;
	double g;
	double b;
	double a;
};
int main()
{
	size_t const size = 100;
	ColorVector * const vec = new ColorVector[size];
	void *p = vec;
	size_t sz = size;
	void *aligned = align(alignof(double) * 4, size, p, sz);
	if (aligned != nullptr)
		cout << alignof(decltype(p)) << endl;
	return 0;
}*/

//8-8
/*struct IntAligned
{
	int a;
	char b;
};
typedef aligned_storage<sizeof(IntAligned), alignof(long double)>::type StrictAligned;
int main()
{
	StrictAligned sa;
	IntAligned *pia = new (&sa) IntAligned;
	cout << alignof(IntAligned) << endl;
	cout << alignof(StrictAligned) << endl;
	cout << alignof(decltype(*pia)) << endl;
	cout << alignof(decltype(sa)) << endl;
	return 0;
}*/

//8-9
/*extern int area(int n) __attribute__((const));
int main()
{
	int i, areas = 0;
	for (i = 0; i < 10; i++)
		areas += area(3) * i;
}*/

//8-10
/*__declspec(align(32)) struct Struct32
{
	int i;
	double d;
};*/

//8-11
/*void DoSomething1();
void DoSomething2();
[[noreturn]] void ThrowAway() { throw "expection"; }
void Func()
{
	DoSomething1();
	ThrowAway();
	DoSomething2();
}*/

//8-12
/*[[noreturn]] void Func(int i)
{
	if (i < 0)
		throw "negative";
	else if (i > 0)
		throw "positive";
}
int main()
{
	Func(0);
	cout << "Returned" << endl;
	return 0;
}*/

//8-13
/*atomic<int*> p1;
atomic<int*> p2;
atomic<int*> p3;
atomic<int*> p4;
void func_in1(int * val) { cout << *val << endl; }
void func_in2([[carries_dependency]] int* val)
{
	p2.store(val, memory_order_release);
	cout << *p2 << endl;
}
[[carries_dependency]] int* func_out()
{
	return (int *)p3.load(memory_order_consume);
}
void Thread()
{
	int *p_ptr1 = (int *)p1.load(memory_order_consume);
	cout << *p_ptr1 << endl;
	func_in1(p_ptr1);
	func_in2(p_ptr1);
	int *p_ptr2 = func_out();
	p4.store(p_ptr2, memory_order_release);
	cout << *p_ptr2 << endl;
}*/

//8-14
/*int main()
{
	char utf8[] = u8"\u4F60\u597D\u554A";
	char16_t utf16[] = u"hello";
	char32_t utf32[] = U"hello equals \u4F60\u597D\u554A";
	cout << utf8 << endl;
	cout << utf16 << endl;
	cout << utf32 << endl;
	//char  --------- u8
	//char16_t --------------u
	//char32_t ----------- U
	return 0;
}*/

//8-15
/*int main()
{
	char utf8[] = u8"\u4F60\u597D\u554A";
	char16_t utf16[] = u"\u4F60\u597D\u554A";
	cout << sizeof(utf8) << endl;
	cout << sizeof(utf16) << endl;
	cout << utf8[1] << endl;
	cout << utf16[1] << endl;
	return 0;
}*/

//8-16
/*int main()
{
	char16_t utf16[] = u"\u4F60\u597D\u554A";
	char mbr[sizeof(utf16) * 2] = { 0 };
	mbstate_t s;
	c16rtomb(mbr, *utf16, &s);
	cout << mbr << endl;
	return 0;
}*/

//8-17
/*int main()
{
	locale lc("en_US.UTF-8");
	bool can_cvt = has_facet<codecvt<wchar_t, char, mbstate_t>>(lc);
	if (!can_cvt)
		cout << "Do not support char-wchar_t facet!" << endl;
	can_cvt = has_facet<codecvt<char16_t, char, mbstate_t>>(lc);
	if (!can_cvt)
		cout << "Do not support char-char16 facet!" << endl;
	can_cvt = has_facet<codecvt<char32_t, char, mbstate_t>>(lc);
	if (!can_cvt)
		cout << "Do not support char-char32 facet!" << endl;
	can_cvt = has_facet<codecvt<char, char, mbstate_t>>(lc);
	if (!can_cvt)
		cout << "Do not support char-char32 facet!" << endl;
	return 0;
}*/

//8-18
/*int main()
{
	ofstream("text.txt") << u8"z\u00df\u6c34\U0001d10b";
	wifstream fin("text.txt");
	fin.imbue(locale("en_US.UTF-8"));
	cout << "The UTF-8 file contains the following wide characters: \n";
	for (wchar_t c; fin >> c;)
		cout << "U+" << hex << setw(4) << setfill('0') << c << '\n';
	return 0;
}*/

//8-19
/*int main()
{
	wstring_convert<codecvt_utf8<wchar_t>> myconv;
	string mbstring = myconv.to_bytes(L"Hello\n");
	cout << mbstring << endl;
	return 0;
}*/

//8-20
/*int main()
{
	cout << R"(hello, \n
		world)" << endl;
	return 0;
}*/

//8-21
/*int main()
{
	cout << u8R"(\u4F60. \n
	\u597D)" << endl;
	cout << u8R"(ÄãºÃ)" << endl;
	cout << sizeof(u8R"(hello)") << "\t" << u8R"(hello)" << endl;
	cout << sizeof(uR"(hello)") << "\t" << uR"(hello)" << endl;
	cout << sizeof(UR"(hello)") << "\t" << UR"(hello)" << endl;
	return 0;
}*/

//8-22
int main()
{
	char u8string[] = u8R"(ÄãºÃ)""=hello";
	cout << u8string << endl;
	cout << sizeof(u8string) << endl;
	return 0;
}