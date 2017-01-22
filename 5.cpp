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
using namespace std;

//5-1
/*namespace T { enum Type { General, Light, Medium, Heavy }; }
namespace { enum Category { General = 1, Pistol, MachineGun, Cannon }; }
int main()
{
	T::Type t = T::Light;
	if (General == t)
		cout << "General Weapon" << endl;
	return 0;
}*/

//5-2
/*enum  Type { General, Light, Medium, Heavy };
enum Category { Pistol, MachineGun, Cannon };
struct Killer
{
	Type type;
	Category category;
	Killer(Type t, Category c) :type(t), category(c) {}
};
int main()
{
	Killer cool(General, MachineGun);
	if (cool.type >= Pistol)
		cout << "It is not a pistol" << endl;
	cout << is_pod<Type>::value << endl;
	cout << is_pod<Category>::value << endl;
	return 0;
}*/

//5-3
/*class Type
{
public:
	enum type { general, light, medium, heavy };
	type val;
public:
	Type(type t) :val(t) {};
	bool operator >= (const Type &t) { return val >= t.val; }
	static const Type General, Light, Medium, Heavy;
};
const Type Type::General(Type::general);
const Type Type::Light(Type::light);
const Type Type::Medium(Type::medium);
const Type Type::Heavy(Type::heavy);
class Category
{
public:
	enum category { pistol, machineGun, cannon };
	category val;
public:
	Category(category c) :val(c) {}
	bool operator >= (const Category &c) { return val >= c.val; }
	static const Category Pistol, MachineGun, Cannon;
};
const Category Category::Pistol(Category::pistol);
const Category Category::MachineGun(Category::machineGun);
const Category Category::Cannon(Category::cannon);
struct Killer
{
	Type type;
	Category category;
	Killer(Type t, Category c) :type(t), category(c) {}
};
int main()
{
	Killer notCool(Type::General, Category::MachineGun);
	if (notCool.type >= Type::General)
		cout << "It is not general" << endl;
	if (notCool.category >= Category::pistol)
		cout << "It is not a pistol" << endl;
	cout << is_pod<Type>::value << endl;
	cout << is_pod<Category>::value << endl;
	return 0;
}*/

//5-4
/*enum C { C1 = 1, C2 = 2 };
enum D { D1 = 1, D2 = 2, Dbig = 0xFFFFFFF0U };
enum E { E1 = 1, E2 = 2, Ebig = 0xFFFFFFFFFLL };
int main()
{
	cout << sizeof(C1) << endl;
	cout << Dbig << endl;
	cout << sizeof(D1) << endl;
	cout << sizeof(Dbig) << endl;
	cout << Ebig << endl;
	cout << sizeof(E1) << endl;
	return 0;
}*/

//5-5
/*enum class Type { General, Light, Medium, Heavy };
enum class Category { General = 1, Pistol, MachineGun, Cannon };
int main()
{
	Type t = Type::Light;
	t = General;
	if (Category::General == t)
		cout << "General Weapon" << endl;
	if (t > Type::General)
		cout << "Not General Weapon" << endl;
	if (t > 0)
		cout << "Not General Weapon" << endl;
	if((int)t > 0)
		cout << "Not General Weapon" << endl;
	cout << is_pod<Type>::value << endl;
	cout << is_pod<Category>::value << endl;
	return 0;
}*/

//5-6
/*typedef unsigned int uint;
enum class C:char { C1 = 1, C2 = 2 };
enum class D:uint { D1 = 1, D2 = 2, Dbig = 0xFFFFFFF0U };
int main()
{
	cout << sizeof(C::C1) << endl;
	cout << (uint)D::Dbig << endl;
	cout << sizeof(D::D1) << endl;
	cout << sizeof(D::Dbig) << endl;
	return 0;
}*/

//5-7
/*enum class tmp { General, Light, Medium, Heavy }weapon;
int main()
{
	weapon = General;
	bool b = (weapon == weapon::General);
	return 0;
}*/

//5-8
/*int main()
{
	unique_ptr<int> up1(new int(11));
	unique_ptr<int> up2 = up1;
	cout << *up1 << endl;
	unique_ptr<int> up3 = move(up1);
	cout << *up3 << endl;
	cout << *up1 << endl;
	up3.reset();
	up1.reset();
	cout << *up3 << endl;

	shared_ptr<int> sp1(new int(22));
	shared_ptr<int> sp2 = sp1;
	cout << *sp1 << endl;
	cout << *sp2 << endl;
	sp1.reset();
	cout << *sp2 << endl;
}*/

//5-9
/*void Check(weak_ptr<int> & wp)
{
	shared_ptr<int> sp = wp.lock();
	if (nullptr != sp)
		cout << "stll " << *sp << endl;
	else
		cout << "pointer is invalid." << endl;
}
int main()
{
	shared_ptr<int> sp1(new int(22));
	shared_ptr<int> sp2 = sp1;
	weak_ptr<int> wp = sp1;

	cout << *sp1 << endl;
	cout << *sp2 << endl;
	Check(wp);

	sp1.reset();
	cout << *sp2 << endl;
	Check(wp);

	sp2.reset();
	Check(wp);
	return 0;
}*/

//5-10
/*int main()
{
	int *p = new int;
	p += 10;
	p -= 10;
	*p = 10;
}*/

//5-11
/*int main()
{
	int *p = new int;
	int *q = (int*)(reinterpret_cast<long long>(p) ^ 2012);
	q = (int*)(reinterpret_cast<long long>(q) ^ 2012);
	*q = 10;
}*/

//5-12
/*int main()
{
	int *p = new int;
	declare_reachable(p);
	int *q = (int*)((long long)p ^ 2012);
	q = undeclare_reachable<int>((int*)((long long)q ^ 2012));
	*q = 10;
}*/









