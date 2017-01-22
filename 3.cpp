#include <iostream>
#include <cassert>
#include <string>
#include <list>
#include <vector>
#include <deque>
#include <utility>
#include <map>
#include <type_traits>
using namespace std;

//3-1
/*struct A { A(int i) {} };
struct B :A 
{
	B(int i) : A(i), d(i) {}
	int d;
};*/

//3-2
/*struct A
{
	A(int i) {}
	A(double d, int i) {}
	A(float f, int i, const char* c) {}
};
struct B :A
{
	B(int i) :A(i) {}
	B(double d, int i) :A(d, i) {}
	B(float f, int i, const char* c) :A(f, i, c) {}
	virtual void ExtraInterface() {}
};*/

//3-3
/*struct Base { void f(double i) { cout << "Base:" << i << endl; } };
struct Derived :Base
{
	using Base::f;
	void f(int i) { cout << "Derived:" << i << endl; }
};
int main()
{
	Base b;
	b.f(4.5);
	Derived d;
	d.f(4.5);
}*/

//3-4
/*struct A
{
	A(int i) {}
	A(double d, int i) {}
	A(float f, int i, const char* c) {}
};
struct B :A
{
	using A::A;
	virtual void ExtraInterface() {};
	int d{ 0 };
};
//3-5
int main()
{
	B b(356);
}*/

//3-6
/*struct A { A(int a = 3, double = 2.4) {} };
struct B :A { using A::A; };*/

//3-7
/*struct A { A(int) {} };
struct B { B(int) {} };
struct C :A, B
{
	using A::A;
	using B::B;
};*/

//3-8
/*struct A { A(int) {} };
struct B :A { using A::A; };
B b;*/

//3-9
/*class Info
{
private:
	void InitRest() {}
	int type;
	char name;
public:
	Info() :type(1), name('a') { InitRest(); }
	Info(int i) :type(i), name('a') { InitRest(); }
	Info(char e) :type(1), name(e) { InitRest(); }
};*/

//3-10
/*class Info
{
private:
	void InitRest() {}
	int type{ 1 };
	char name{ 'a' };
public:
	Info() { InitRest(); }
	Info(int i) :type(i) { InitRest(); }
	Info(char e) :name(e) { InitRest(); }
};*/

//3-11
/*class Info
{
private:
	void InitRest() {}
	int type{ 1 };
	char name{ 'a' };
public:
	Info() { InitRest(); }
	Info(int i) :Info() { type = i; }
	Info(char e) :Info() { name = e; }
};*/

//3-12
/*class Info
{
private:
	Info(int i, char e) :type(i), name(e) {}
	int type;
	char name;
public:
	Info() :Info(1, 'a') {}
	Info(int i) :Info(i, 'a') {}
	Info(char e) :Info(1, e) {}
};*/

//3-13
/*class Info
{
private:
	Info(int i, char e) :type(i), name(e) {}
	int type;
	char name;
public:
	Info() :Info(1) {}
	Info(int i) :Info(i, 'a') {}
	Info(char e) :Info(1, e) {}
};*/

//3-14
/*class TDConstructed
{
	list<int> l;
	template<typename T> TDConstructed(T first, T last) :l(first, last) {}
public:
	TDConstructed(vector<short> & v) :TDConstructed(v.begin(), v.end()) {}
	TDConstructed(deque<int> & d) :TDConstructed(d.begin(), d.end()) {}
};*/

//3-15
/*class DCExcept
{
private:
	int type;
	double data;
	DCExcept(int i, double d)
	{
		cout << "going to throw!" << endl;
		throw 0;
	}
public:
	DCExcept(double d)
	try:DCExcept(1, d)
	{
		cout << "Run the body." << endl;
	}
	catch (...)
	{
		cout << "caught exception." << endl;
	}
};
int main()
{
	DCExcept a(1.2);
	return 0;
}*/

//3-16 3-17
/*class HasPtrMem
{
public:
	int *d;
	HasPtrMem() :d(new int(0)) {}
	HasPtrMem(const HasPtrMem &h) :d(new int(*h.d)) {}
	~HasPtrMem() { delete d; }
};
int main()
{
	HasPtrMem a;
	HasPtrMem b(a);
	cout << *a.d << endl;
	cout << *b.d << endl;
	return 0;
}*/

//3-18
/*class HasPtrMem
{
public:
	int *d;
	static int n_cstr;
	static int n_dstr;
	static int n_cptr;
	HasPtrMem() :d(new int(0)) { cout << "Construct: " << ++n_cstr << endl; }
	HasPtrMem(const HasPtrMem & h) :d(new int(*h.d)) { cout << "Copy construct: " << ++n_cptr << endl; }
	~HasPtrMem() { cout << "Destruct: " << ++n_dstr << endl; }
};
int HasPtrMem::n_cptr = 0;
int HasPtrMem::n_dstr = 0;
int HasPtrMem::n_cstr = 0;
HasPtrMem GetTemp() { return HasPtrMem(); }
int main()
{
	HasPtrMem a = GetTemp();
	return 0;
}*/

//3-19
/*class HasPtrMem
{
public:
	int *d;
	static int n_cstr;
	static int n_dstr;
	static int n_cptr;
	static int n_mvtr;
	HasPtrMem() :d(new int(3)) { cout << "Construct: " << ++n_cstr << endl; }
	HasPtrMem(const HasPtrMem & h) :d(new int(*h.d)) { cout << "Copy construct: " << ++n_cptr << endl; }
	HasPtrMem(HasPtrMem && h) :d(h.d) 
	{ 
		h.d = nullptr;
		cout << "Move construct:  " << ++n_mvtr << endl; 
	}
	~HasPtrMem() 
	{ 
		delete d;
		cout << "Destruct: " << ++n_dstr << endl; 
	}
};
int HasPtrMem::n_cptr = 0;
int HasPtrMem::n_dstr = 0;
int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_mvtr = 0;
HasPtrMem GetTemp() 
{ 
	HasPtrMem h;
	cout << "Resource from" << __func__ << ": " << hex << h.d << endl;
	return h; 
}
int main()
{
	HasPtrMem a = GetTemp();
	cout << "Resource from " << __func__ << ": " << hex << a.d << endl;
	return 0;
}*/

//3-20
/*struct Copyable
{
	Copyable() {}
	Copyable(const Copyable &o) { cout << "Copied" << endl; }
};
Copyable ReturnRvalue() { return Copyable(); }
void AcceptVal(Copyable) {}
void AcceptRef(const Copyable &) {}
int main()
{
	cout << "Pass by value: " << endl;
	AcceptVal(ReturnRvalue());
	cout << "Pass by reference: " << endl;
	AcceptRef(ReturnRvalue());
	return 0;
}*/

//3-21
/*class Moveable
{
public:
	int *i;
	Moveable() :i(new int(3)) {}
	~Moveable() { delete i; }
	Moveable(const Moveable & m) :i(new int(*m.i)) {}
	Moveable(Moveable && m) :i(m.i) { m.i = nullptr; }
};
int main()
{
	Moveable a;
	Moveable c(move(a));
	cout << *a.i << endl;
	return 0;
}*/

//3-22
/*class HugeMem
{
public:
	int *c, sz;
	HugeMem(int size) :sz(size > 0 ? size : 1) { c = new int[sz]; }
	~HugeMem() { delete[] c; }
	HugeMem(HugeMem && hm) :sz(hm.sz), c(hm.c) { hm.c = nullptr; }
};
class Moveable
{
public:
	int *i;
	HugeMem h;
	Moveable() :i(new int(3)), h(1024) {}
	~Moveable() { delete i; }
	Moveable(Moveable && m) :i(m.i), h(move(m.h)) { m.i = nullptr; }
};
Moveable GetTemp()
{
	Moveable tmp = Moveable();
	cout << hex << "Huge Mem from " << __func__ << " @ " << tmp.h.c << endl;
	return tmp;
}
int main()
{
	Moveable a(GetTemp());
	cout << hex << "Huge Mem from " << __func__ << " @ " << a.h.c << endl;
	return 0;
}*/

//3-23
/*struct Maythrow
{
	Maythrow() {};
	Maythrow(const Maythrow&) { cout << "Maythrow copy constructor." << endl; }
	Maythrow(Maythrow&&) { cout << "Maythorow move constructor." << endl; }
};
struct Nothrow
{
	Nothrow() {};
	Nothrow(const Maythrow&) { cout << "Nothrow copy constructor." << endl; }
	Nothrow(Nothrow&&) noexcept { cout << "Nothorow move constructor." << endl; }
};
int main()
{
	Maythrow m;
	Nothrow n;
	Maythrow mt = move_if_noexcept(m);
	Nothrow nt = move_if_noexcept(n);
	return 0;
}*/

//3-24
/*void RunCode(int && m) { cout << "rvalue ref" << endl; }
void RunCode(int &m) { cout << "lvalue ref" << endl; }
void RunCode(const int && m) { cout << "const rvalue ref" << endl; }
void RunCode(const int &m) { cout << "const lvalue ref" << endl; }
template <typename T> 
void PerfectForward(T &&t) { RunCode(forward<T>(t)); }
int main()
{
	int a, b;
	const int c = 1, d = 0;
	PerfectForward(a);
	PerfectForward(move(b));
	PerfectForward(c);
	PerfectForward(move(d));
}*/

//3-25
/*template <typename T, typename U>
void PefectForward(T &&t, U &&Func)
{
	cout << t << "\tforwarded..." << endl;
	Func(forward<T>(t));
}
void RunCode(double &&m) {}
void RunHome(double &&h) {}
void RunComp(double &&c) {}
int main()
{
	PefectForward(1.5, RunComp);
	PefectForward(8, RunCode);
	PefectForward(1.5, RunHome);
}*/

//3-26
/*struct Rational1
{
	int num, den;
	Rational1(int n = 0, int d = 1) :num(n), den(d) { cout << __func__ << "(" << num << "/" << den << ")" << endl; }
};
struct Rational2
{
	int num, den;
	explicit Rational2(int n = 0, int d = 1) :num(n), den(d) { cout << __func__ << "(" << num << "/" << den << ")" << endl; }
};
void Display1(Rational1 ra) { cout << "Numerator: " << ra.num << " Denominator: " << ra.den << endl; }
void Display2(Rational2 ra) { cout << "Numerator: " << ra.num << " Denominator: " << ra.den << endl; }
int main()
{
	Rational1 r1_1 = 11;
	Rational2 r1_2(12);
	Rational2 r2_1 = 21;
	Rational2 r2_2(22);
	Display1(1);
	Display2(2);
	Display2(Rational2(2));
	return 0;
}*/

//3-27
/*template <typename T>
class Ptr
{
public:
	Ptr(T* p) :_P(p) {}
	operator bool() const 
	{
		if (0 != _P)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	T* _P;
};
int main()
{
	int a;
	Ptr<int> p(&a);
	if (p)
	{
		cout << "valid pointer. " << endl;
	}
	else
	{
		cout << "invalid pointer." << endl;
	}
	Ptr<double> pd(0);
	cout << p + pd << endl;
	return 0;
}*/

//3-28
/*class ConverTo {};
class Convertable
{
public:
	explicit operator ConverTo()const { return ConverTo(); }
};
void Func(ConverTo ct) {}
void test()
{
	Convertable c;
	ConverTo ct(c);
	ConverTo ct2 = c;
	ConverTo ct3 = c;
	ConverTo ct3 = static_cast<ConverTo>(c);
	Func(c);
}*/

//3-29
/*int a[] = { 1, 3, 5 };
int b[]{ 2,4,6 };
vector<int> c{ 1,3,5 };
map<int, float> d = { {1,1.0f},{2,2.0f},{5,3.2f} };*/

//3-30
/*enum Gender {boy, girl};
class People
{
private:
	vector<pair<string, Gender>> data;
public:
	People(initializer_list<pair<string, Gender>> l)
	{
		for (auto i = l.begin(); i != l.end(); ++i)
			data.push_back(*i);
	}
};
People ship2012 = { {"Garfield", boy},{"HelloKitty", girl } };*/

//3-31
/*void Fun(initializer_list<int> iv) {}
int main()
{
	Fun({ 1, 2 });
	Fun({});
	return 0;
}*/

//3-32
/*class Mydata
{
private:
	vector<int> idx;
	vector<int> d;
public:
	Mydata & operator [] (initializer_list<int> l) 
	{
		for (auto i = l.begin(); i != l.end(); ++i)
			idx.push_back(*i);
		return *this;
	}
	Mydata & operator = (int v)
	{
		if (!idx.empty())
		{
			for (auto i = idx.begin(); i != idx.end(); i++)
			{
				d.resize((*i > d.size()) ? *i : d.size());
				d[*i - 1] = v;
			}
			idx.clear();
		}
		return *this;
	}
	void Print()
	{
		for (auto i = d.begin(); i != d.end(); ++i)
			cout << *i << " ";
		cout << endl;
	}
};
int main()
{
	Mydata d;
	d[{2, 3, 5}] = 7;
	d[{1, 4, 5, 8}] = 4;
	d.Print();
	return 0;
}*/

//3-33
/*const int x = 1024;
const int y = 10;
char a = x;
char* b = new char(1024);
char c = { x };
char d = { y };
unsigned char e{ -1 };
float f{ 7 };
int g{ 2.0f };
float * h = new float{ 1e48 };
float i = 1.2l;*/

//3-34
/*struct Trivial1 {};
struct Trivial2
{
public:
	int a;
private:
	int b;
};
struct Trivial3
{
	Trivial1 a;
	Trivial2 b;
};
struct Trivial4 { Trivial2 a[23]; };
struct Trivial5
{
	int x;
	static int y;
};
struct NonTrivial1
{
	NonTrivial1() :z(42) {}
	int z;
};
struct NonTrivial2
{
	NonTrivial2();
	int w;
};
NonTrivial2::NonTrivial2() = default;
struct NonTrivial3
{
	Trivial5 c;
	virtual void f();
};
int main()
{
	cout << is_trivial<Trivial1>::value << endl;
	cout << is_trivial<Trivial2>::value << endl;
	cout << is_trivial<Trivial3>::value << endl;
	cout << is_trivial<Trivial4>::value << endl;
	cout << is_trivial<Trivial5>::value << endl;
	cout << is_trivial<NonTrivial1>::value << endl;
	cout << is_trivial<NonTrivial2>::value << endl;
	cout << is_trivial<NonTrivial3>::value << endl;
	return 0;
}*/

//3-35
/*struct B1 {};
struct B2 {};
struct D1 :B1
{
	B1 b;
	int i;
};
struct D2 :B1
{
	B2 b;
	int i;
};
int main()
{
	D1 d1;
	D2 d2;
	cout << hex;
	cout << reinterpret_cast<long long>(&d1) << endl;
	cout << reinterpret_cast<long long>(&(d1.b)) << endl;
	cout << reinterpret_cast<long long>(&(d1.i)) << endl;

	cout << reinterpret_cast<long long>(&d2) << endl;
	cout << reinterpret_cast<long long>(&(d2.b)) << endl;
	cout << reinterpret_cast<long long>(&(d2.i)) << endl;
	return 0;
}*/

//3-36
/*struct SLayout1 {};
struct SLayout2
{
private:
	int x, y;
};
struct SLayout3 :SLayout1
{
	int x, y;
	void f();
};
struct SLayout4 :SLayout1
{
	int x;
	SLayout1 y;
};
struct SLayout5 :SLayout1, SLayout3 {};
struct SLayout6 { static int y; };
struct SLayout7 :SLayout6 { int x; };
struct NonSLayout1 :SLayout1
{
	SLayout1 x;
	int i;
};
struct NonSLayout2 :SLayout2 { int z; };
struct NonSLayout3 :NonSLayout2 {};
struct NonSLayout4
{
public:
	int x;
private:
	int y;
};
int main()
{
	cout << is_standard_layout<SLayout1>::value << endl;
	cout << is_standard_layout<SLayout2>::value << endl;
	cout << is_standard_layout<SLayout3>::value << endl;
	cout << is_standard_layout<SLayout4>::value << endl;
	cout << is_standard_layout<SLayout5>::value << endl;
	cout << is_standard_layout<SLayout6>::value << endl;
	cout << is_standard_layout<SLayout7>::value << endl;

	cout << is_standard_layout<NonSLayout1>::value << endl;
	cout << is_standard_layout<NonSLayout2>::value << endl;
	cout << is_standard_layout<NonSLayout3>::value << endl;
	return 0;
}*/

//3-37
/*union U {};
union U1 { U1() {} };
enum E {};
typedef double *DA;
typedef void(*PF)(int, double);
int main()
{
	cout << is_pod<U>::value << endl;
	cout << is_pod<U1>::value << endl;
	cout << is_pod<E>::value << endl;
	cout << is_pod<int>::value << endl;
	cout << is_pod<DA>::value << endl;
	cout << is_pod<PF>::value << endl;
	return 0;
}*/

//3-38
/*struct Student
{
	bool gender;
	int age;
	Student(bool g, int a) :gender(g), age(a) {}
};
union T
{
	Student s;
	int id;
	char name[10];
};*/

//3-39
/*union T { static long Get() { return 32; } };
int main()
{
	cout << T::Get() << endl;
	return 0;
}*/

//3-40
/*union T
{
	int x;
	double d;
	char b[sizeof(double)];
};
T t = { 0 };*/

//3-41 3-42
/*union T
{
	string s;
	int n;
public:
	T() { new (&s) string; }
	~T() { s.~basic_string(); }
};
T t;*/

//3-43
/*struct Student
{
	bool gender;
	int age;
	Student(bool g, int a) : gender(g), age(a) {}
};
class Singer
{
public:
	enum Type{STUDENT, NATIVE, FOREIGNER};
	Singer(bool g, int a) :s(g, a) { t = STUDENT; }
	Singer(int i) : id(i) { t = NATIVE; }
	Singer(const char* n, int s)
	{
		int size = (s > 9) ? 9 : s;
		memcpy(name, n, size);
		name[s] = '\0';
		t = FOREIGNER;
	}
private:
	Type t;
	union
	{
		Student s;
		int id;
		char name[10];
	};
};
int main()
{
	Singer(true, 13);
	Singer(310217);
	Singer("J Michael", 9);
}*/

//3-44
/*typedef unsigned char uint8;
struct RGBA
{
	uint8 r, g, b, a;
	RGBA(uint8 R, uint8 G, uint8 B, uint8 A = 0) :r(R), g(G), b(B), a(A) {}
};
std::ostream & operator << (std::ostream & out, RGBA & col)
{
	return  out << "r: " << (int)col.r
		<< ", g: " << (int)col.g
		<< ", b: " << (int)col.b
		<< ", a: " << (int)col.a << endl;
}
void blend(RGBA & col1, RGBA & col2) { cout << "blend" << endl << col1 << col2 << endl; }
int main()
{
	RGBA col1(255, 240, 155);
	RGBA col2({ 15,255,10, 7 });
	blend(col1, col2);
	return 0;
}*/

//3-45
/*typedef unsigned char uint8;
struct RGBA
{
	uint8 r, g, b, a;
	RGBA(uint8 R, uint8 G, uint8 B, uint8 A = 0) :r(R), g(G), b(B), a(A) {}
};
RGBA operator "" _C(const char* col, size_t n)
{
	const char *p = col, *end = col + n, *r, *g, *b, *a;
	r = g = b = a = nullptr;
	for (; p != end; p++)
	{
		if ('r' == *p) r = p;
		else if ('g' == *p) g = p;
		else if ('b' == *p) b = p;
		else if ('a' == *p) a = p;
	}
	if ((nullptr == r) || (nullptr == g) || (nullptr == b))
		throw;
	else if (nullptr == a)
		return RGBA(atoi(r + 1), atoi(g + 1), atoi(b + 1));
	else
		return RGBA(atoi(r + 1), atoi(g + 1), atoi(b + 1), atoi(b + 1));
}
std::ostream & operator << (std::ostream & out, RGBA & col)
{
	return  out << "r: " << (int)col.r
		<< ", g: " << (int)col.g
		<< ", b: " << (int)col.b
		<< ", a: " << (int)col.a << endl;
}
void blend(RGBA & col1, RGBA & col2) { cout << "blend" << endl << col1 << col2 << endl; }
int main()
{
	blend("r255 g250 b155"_C, "r15 g255 b10 a7"_C);
	return 0;
}*/

//3-46
/*struct Watt { unsigned int v; };
Watt operator "" _w(unsigned long long v) { return  { (unsigned int)v }; }
int main()
{
	Watt capacity = 1024_w;
	return 0;
}*/

//3-47
/*namespace Jim
{
	namespace Basic
	{
		struct Knife { Knife() { cout << "Knife in Basic." << endl; } };
		class CorkScrew {};
	}
	namespace Toolkit { template<typename T> class SwissArmyKnife {}; }
	namespace Other
	{
		Knife b;
		struct Knife { Knife() { cout << "Knife in Other" << endl; } };
		Knife c;
		Basic::Knife k;
		
	}
}
using namespace Jim;
int main()
{
	Toolkit::SwissArmyKnife<Basic::Knife> sknife;
	return 0;
}*/

//3-48
/*namespace Jim
{
	namespace Basic
	{
		struct Knife { Knife() { cout << "Knife in Basic." << endl; } };
		class CorkScrew {};
	}
	namespace Toolkit { template<typename T> class SwissArmyKnife {}; }
	namespace Other {}
	using namespace Basic;
	using namespace Toolkit;
}
namespace Jim { template<> class SwissArmyKnife<Knife> {}; }
using namespace Jim;
int main()
{
	SwissArmyKnife<Knife> sknife;
	return 0;
}*/

//3-49
/*namespace Jim
{
	inline namespace Basic
	{
		struct Knife { Knife() { cout << "Knife in Basic." << endl; } };
		class CorkScrew {};
	}
	inline namespace Toolkit { template<typename T> class SwissArmyKnife {}; }
	namespace Other
	{
		Knife b;
		struct Knife { Knife() { cout << "Knife in Other" << endl; } };
		Knife c;
		Basic::Knife k;

	}
}
namespace Jim { template<> class SwissArmyKnife<Knife> {}; }
using namespace Jim;
int main()
{
	SwissArmyKnife<Knife> sknife;
	return 0;
}*/

//3-50
/*namespace Jim
{
#if __cplusplus == 201103L
	inline
#endif // __cplusplus == 201103L
		namespace cpp11
	{
		struct Knife { Knife() { cout << "Knife in c++11." << endl; } };
	}
#if __cplusplus < 201103L
	inline
#endif // __cplusplus < 201103L
		namespace oldcpp
	{
		struct Knife { Knife() { cout << "Knife in old c++." << endl; } };
	}
}
using namespace Jim;
int main()
{
	Knife a;
	cpp11::Knife b;
	oldcpp::Knife c;
	return 0;
}*/

//3-51
/*using uint = unsigned int;
typedef unsigned int UINT;
using sint = int;
int main()
{
	cout << is_same<uint, UINT>::value << endl;
	return 0;
}*/

//3-52
/*struct Test { typedef int foo; };
template <typename T>
void f(typename T::foo) {}
template <typename T>
void f(T) {}
int main()
{
	f<Test>(10);
	f<int>(10);
	return 0;
}*/

//3-53
/*template<int I> struct A {};
char xxx(int);
char xxx(float);
template<class T> A<sizeof(xxx((T)0))> f(T) {}
int main()
{
	f(1);
	return 0;
}*/


