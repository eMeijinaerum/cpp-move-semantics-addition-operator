// class_move_semantics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NewClass.h"
#include <vector>

using std::cout;

void separator() {
	cout << "\n===\n\n";
}

void printNew(const NewClass &nc) {
	cout << nc;
}



int main()
{
	{ // New block for running destructors before return
		NewClass cnew;		
		cout << cnew;

		NewClass cnew2(55);
		cout << cnew2;
		
		NewClass cnew3 = NewClass(10);
		cout << cnew3;

		NewClass cnew4(cnew3);

		separator();

		printNew(cnew);

		//cnew4 += NewClass(1);
		cnew4 = cnew2 + cnew + cnew2 + cnew;
		cout << cnew;
		cout << cnew2;
		cout << cnew4;
		
		separator();
	/*
		cnew = cnew3 = cnew2;
		cout << cnew;

		separator();

		std::vector<NewClass> v;
		v.push_back(NewClass(25));

		separator();
		cout << "S W A P\n";
		cout << "cnew = " << cnew;
		cout << "cnew4 = " << cnew4;

		NewClass T = std::move(cnew);
		cnew = std::move(cnew4);
		cnew4 = std::move(T);

		cout << "cnew = " << cnew;
		cout << "cnew4 = " << cnew4;
		cout << "T = " << T;


		separator();
	

		const NewClass cNC(33);
	*/
	}
    return 0;
}

