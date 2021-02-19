#include "../../std_lib_facilities.h"

namespace x{
	int var;
	void print(){cout << var<<endl;};
};
namespace y{
	int var;
	void print(){cout << var<<endl;};
};
namespace z{
	int var;
	void print(){cout << var<<endl;};
};

int main()
{	
	x::var =7;
	x::print();
	//using namespace y;
	int var =9;
    y:: print();
	{
		 z::var =11;
		 z::print;
		z::print();
	}
	y:: print();
	x::print();


	return 0;
}