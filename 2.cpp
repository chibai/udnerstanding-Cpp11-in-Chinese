#include <iostream>
#include <cassert>
#include <string>
using namespace std;

//2-1
/*int main()
{
	cout << "Standard Clib: " << __STDC_HOSTED__ << endl;
	cout << "is thread supported: " <<  __STDCPP_THREADS__<< endl;
	cout << "compile time: " << __DATE__  << endl;
}
*/

//2-2
/*const char* hello() { return __func__; }
const char* world() { return __func__; }
int main()
{
	cout << hello() << ", " << world() << endl;
}*/

//2-3
/*struct TestStruct
{
	const char *name;
	TestStruct() : name(__func__) {}
};
int main()
{
	TestStruct ts;
	cout << ts.name << endl;
}*/

//2-4 __VA_ARGS__

//2-5
/*int main()
{
	long long ll_min = LLONG_MIN;
	long long ll_max = LLONG_MAX;
	unsigned long long ull_max = ULLONG_MAX;

	cout << "min of long long: " << ll_min << endl;
	cout << "max of long long: " << ll_max << endl;
	cout << "max of unsigned long long: " << ull_max << endl;
}*/

//2-6
/*char* ArrayAlloc(int n)
{
	assert(n > 0);
	return new char[n];
}
int main()
{
	char* a = ArrayAlloc(0);
}*/

//2-7
/*enum FeatureSupports
{
	C99      = 0x0001,
	ExtInt   = 0x0002,
	SAssert  = 0x0004,
	NoExcept = 0x0008,
	SMAX     = 0x0010,
};
struct Compiler 
{
	const char *name;
	int spp;
};
int main()
{
	assert((SMAX - 1) == (C99 | ExtInt | SAssert | NoExcept));
	Compiler a = { "abc", (C99 | SAssert) };
	if (a.spp & C99)
	{
		cout << "OK" << endl;
	}
}*/

//2-8
/*template <typename T, typename U> 
int bit_copy(T &a, U &b)
{
	assert(sizeof(b) == sizeof(a));
	memcpy(&a, &b, sizeof(b));
	return 0;
}
int main()
{
	int a = 0x2468;
	double b;
	bit_copy(a, b);
}*/

//2-9
/*#define assert_static(e) \
	do\
	{\
		enum { assert_static__ = 1 / (e) };\
	} while (0);
template <typename T, typename U> int bit_copy(T &a, U &b)
{
	//assert_static(sizeof(b) == sizeof(a));
	static_assert(sizeof(b) == sizeof(a), "the parameters of bit_copy must have same width");
	memcpy(&a, &b, sizeof(b));
}
int main()
{
	int a = 0x2468;
	double b;
	bit_copy(a, b);
}*/

//2-10
/*static_assert (sizeof(int) == 8, "This 64-bit machine should follow this!");
int main()
{
	return 0;
}*/

//2-11
/*int positvie(const int n)
{
	static_assert(n > 0, "value must > 0");
}*/

//2-12
/*void Throw() { throw 1; }
void NoBlockThrow() { Throw(); }
void BlockThrow() noexcept { Throw(); }
int main()
{
	try
	{
		Throw();
	}
	catch (...)
	{
		cout << "Found throw." << endl;
	}
	try
	{
		NoBlockThrow();
	}
	catch (...)
	{
		cout << "Throw is not blocked." << endl;
	}
	try
	{
		BlockThrow();
	}
	catch (...)
	{
		cout << "Found throw 1." << endl;
	}
}*/

//2-13
/*struct A { ~A() { throw 1; } };
struct B { ~B() noexcept { throw 2; } };
struct C { B b; };
int funA() { A a; return 0; }
int funB() { B b; return 0; }
int funC() { C c; return 0; }
int main()
{
	try
	{
		funB();
	}
	catch (...)
	{
		cout << "caught funB." << endl;
	}
	try
	{
		funC();
	}
	catch (...)
	{
		cout << "caught funC." << endl;
	}
	try
	{
		funA();
	}
	catch (...)
	{
		cout << "caught funA." << endl;
	}
}*/

//2-14
/*class Init
{
public:
	Init() :a(0) {}
	Init(int d) :a(d) {}
private:
	int a;
	const static int b = 0;
	int c = 1;
	static int d = 0;
	static const double e = 1.3;
	static const char * const f = "e";
};*/

//2-15
/*struct C
{
	C(int i) :c(i) {};
	int c;
};
struct init
{
	int a = 1;
	string b("hello");
	C c(1);
};*/

//2-16
/*struct Mem 
{
	Mem() { cout << "Mem default, num: " << num << endl; }
	Mem(int i) : num(i) { cout << "Mem, num: " << num << endl; }
	int num = 2;
};
class Group
{
public:
	Group() { cout << "Group default. val: " << val << endl; }
	Group(int i) :val('G'), a(i) { cout << "Group. val: " << val << endl; }
	void NumOfA() { cout << "number of A: " << a.num << endl; }
	void NumOfB() { cout << "number of B: " << b.num << endl; }
private:
	char val{ 'g' };
	Mem a;
	Mem b{ 19 };
};
int main()
{
	Mem member;
	Group group;
	group.NumOfA();
	group.NumOfB();
	Group group2(7);
	group2.NumOfA();
	group2.NumOfB();
	return 0;
}*/

//2-17
/*class Mem 
{
private:
	int m;
public:
	Mem(int i) :m(i) {}
};
class Group
{
private:
	int data = 1;
	Mem mem{ 0 };
	string name{ "Group" };
};*/

//2-18
/*struct  People
{
public:
	int hand;
	static People * all;
};
int main()
{
	People p;
	cout << sizeof(p.hand) << endl;
	cout << sizeof(People::all) << endl;
	cout << sizeof(People::hand) << endl;
	cout << sizeof(People) << endl;
	return 0;
}*/

//2-19
/*class Poly;
typedef Poly P;
class LiLei
{
	friend class Poly;
};
class Jim
{
	friend Poly;
};
class HanMeiMei
{
	friend P;
};*/

//2-20
/*class P;
template <typename T> class  People
{
	friend T;
};
People<P> PP;
People<int> Pi;*/

//2-21
/*#ifdef UNIT_TEST
#define private public
#endif
class Defender
{
public:
	void Defence(int x, int y) {}
	void Tackle(int x, int y) {}
private:
	int pos_x = 15;
	int pos_y = 0;
	int speed = 2;
	int stamina = 120;
};
class Attacker
{
public:
	void Move(int x, int y) {}
	void SpeedUp(float ratio) {}
private:
	int pos_x = 0;
	int pos_y = -30;
	int speed = 3;
	int stamina = 100;
};
#ifdef UNIT_TEST
class Validator
{
public:
	void Validate(int x, int y, Defender & d) {}
	void Validate(int x, int y, Attacker & a) {}
};
int main()
{
	Defender d;
	Attacker a;
	a.Move(15, 30);
	d.Defence(15, 30);
	a.SpeedUp(1.5f);
	d.Defence(15, 30);
	Validator v;
	v.Validate(7, 0, d);
	v.Validate(1, -10, a);
	return 0;
}
#endif // UNIT_TEST*/

//2-22
/*template <typename T> class DefenderT
{
public:
	friend T;
	void Defence(int x, int y) {}
	void Tackle(int x, int y) {}
private:
	int pos_x = 15;
	int pos_y = 0;
	int speed = 2;
	int stamina = 120;
};
template <typename T> class AttackerT
{
public:
	friend T;
	void Move(int x, int y) {}
	void SpeedUp(float ratio) {}
private:
	int pos_x = 0;
	int pos_y = -30;
	int speed = 3;
	int stamina = 100;
};
using Defender = DefenderT<int>;
using Attacker = AttackerT<int>;
using DefenderTest = DefenderT<Validator>;
using AttackerTest = AttackerT<Validator>;
class Validator
{
public:
	void Validate(int x, int y, DefenderTest & d) {}
	void Validate(int x, int y, AttackerTest & a) {}
};
int main()
{
	DefenderTest d;
	AttackerTest a;
	a.Move(15, 30);
	d.Defence(15, 30);
	a.SpeedUp(1.5f);
	d.Defence(15, 30);
	Validator v;
	v.Validate(7, 0, d);
	v.Validate(1, -10, a);
	return 0;
}*/

//2-23
/*class MathObject
{
public:
	virtual double Arith() = 0;
	virtual void Print() = 0;
};
class Printable :public MathObject
{
public:
	double Arith() = 0;
	void Print() { cout << "Output is: " << Arith() << endl; }
};
class Add2 :public Printable
{
public:
	Add2(double a, double b) :x(a), y(b) {}
	double Arith() { return x + y; }
private:
	double x, y;
};
class Mul3 :public Printable
{
private:
	double x, y, z;
public:
	Mul3(double a, double b, double c) :x(a), y(b), z(c) {}
	double Arith() { return x * y * z; }
};*/

//2-24
/*struct Object
{
	virtual void fun() = 0;
};
struct Base :public Object
{
	void fun() final;
};
struct Derived :public Base
{
	void fun();
};*/

//2-25
/*struct Base
{
	virtual void Turing() = 0;
	virtual void Dijkstra() = 0;
	virtual void VNeumann(int g) = 0;
	virtual void DKnuth() const;
	void Print();
};
struct DerivedMid :public Base
{
	void VNeumann(double g);
};
struct DerivedTop :public DerivedMid
{
	void Turing() override;
	void Dikjstra() override;
	void VNeumann(double g) override;
	void DKnuth() override;
	void Print() override;
};*/

//2-26
/*template <typename T> void TempFun(T a) { cout << a << endl; }
int main()
{
	TempFun(1);
	TempFun("1");
}*/

//2-27
/*void DefParm(int m = 3) {}
template <typename T = int>
class DefCkass {};
template <typename T = int>
void DefTempParm() {};*/

//2-28
/*template<typename T1, typename T2 = int> class DefClass1;
template<typename T1 = int, typename T2> class DefClass2;
template<typename T, int i = 0> class DefClass3;
template<int i = 0, typename T> class DefClass4;
template<typename T1 = int, typename T2> void DefFunc1(T1 a, T2 b);
template<int i = 0, typename T> void DefFimc2(T a);*/

//2-29
/*template <class T, class U = double>
void f(T t = 0, U u = 0);
void g()
{
	f(1, 'c');
	f(1);
	f();
	f<int>();
	f<int, char>();
}*/

//2-30
/*template <typename T> class X {};
template <typename T> void TempFun(T t) {};
struct A {} a;
struct { int i; }b;
typedef struct { int i; }B;
void Fun()
{
	struct C {} c;
	X<A> x1;
	X<B> x2;
	X<C> x3;
	TempFun(a);
	TempFun(b);
	TempFun(c);
}
//2-31
template <typename T> struct MyTemplate {};
int main()
{
	MyTemplate<struct { int a; } > t;
	return 0;
}*/