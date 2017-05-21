#include "NewClass.h"

using namespace std;

//static
int NewClass::LastID = 0;

NewClass::NewClass(): res(new double(42)), id(LastID++) {
	cout << "  def CTOR; res = " << *res << " id = " << id << "\n";
} 

NewClass::NewClass(const double & d): res(new double(d)), id(LastID++) {
	cout << "  par CTOR; res = " << *res << " id = " << id << "\n";
}

NewClass::NewClass(const NewClass & nc): res(new double(*(nc.res))), id(LastID++) {
	cout << "  copy CTOR; res = " << *res << " id = " << id << "\n";
}

NewClass::NewClass(NewClass && nc): id(LastID++) {
	cout << "  move CTOR; res = " << *res << " id = " << id << "\n";
	res = nc.res;
	nc.res = nullptr;
}

NewClass & NewClass::operator=(const NewClass & nc) {
	cout << "  operator=(const NewClass &) - copy assignment; left id = " << id << ", right id = " << nc.id << "\n";
	if (this != &nc) {
		*res = *(nc.res);
	}
	return *this;
}

NewClass & NewClass::operator=(NewClass && nc) {
	cout << "  operator=(NewClass &&) - move assignment; left id = " << id << ", right id = " << nc.id << "\n";
	if (this != &nc) {
		delete res;
		res = nc.res;
		nc.res = nullptr;
	}
	return *this;
}

NewClass & NewClass::operator+=(const NewClass & nc) {
	cout << "  operator+=(const NewClass &) - copy add assignment; left id = " << id << ", right id = " << nc.id << "\n";
	*res += *(nc.res);
	return *this;
}

NewClass & NewClass::operator+=(NewClass && nc) {
	cout << "  operator+=(const NewClass &&) - move add assignment; left id = " << id << ", right id = " << nc.id << "\n";
	*res += *(nc.res);
	if (this != &nc) {
		//nc.res = nullptr; never deleting
	}

	return *this;
}

int NewClass::getLastID()
{
	return LastID;
}

//friend
NewClass operator+(const NewClass & l, const NewClass & r) {
	cout << "  operator+(&, &) - addition; left id = " << l.id << ", right id = " << r.id << "\n";
	return NewClass(*(l.res) + *(r.res));
}

//friend
NewClass && operator+(const NewClass & l, NewClass && r) {
	cout << "  operator+(&, &&) - move add; left id = " << l.id << ", right id = " << r.id << "\n";
	*(r.res) += *(l.res);
	return move(r);
}

//friend
NewClass && operator+(NewClass && l, const NewClass & r) {
	cout << "  operator+(&&, &) - move add; left id = " << l.id << ", right id = " << r.id << "\n";
	*(l.res) += *(r.res);
	return move(l);
}

//friend
NewClass && operator+(NewClass && l, NewClass && r) {
	cout << "  operator+(&&, &&) - move add; left id = " << l.id << ", right id = " << r.id << "\n";
	*(l.res) += *(r.res);
	return move(l);
}

NewClass::~NewClass() {	
	if (res) {
		cout << "  ~NewClass() - DR: res = " << *res << " id = " << id << "\n";
		delete res;
	} else {
		cout << "  ~NewClass() - DR: res = nullptr, nothing to delete; id = " << id << "\n";
	}

}

std::ostream & operator<<(std::ostream & os, const NewClass & nc) {
	if (nc.res) {
		os << "res = " << *(nc.res) << " (id = " << nc.id << " )\n";
	}
	else {
		os << "res = NULLPTR" << " (id = " << nc.id << " )\n";
	}
	return os;
}
