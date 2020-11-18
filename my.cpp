#include "my.h"
#include "../../std_lib_facilities.h"

void print_foo() {cout << foo << endl;};

void print(int i) {cout << i << endl;};

int swap_v(int a,int b)
{
	int temp; temp=a; a=b; b= temp; return a;}

int swap_r(int& a ,int& b)
{
	int temp; temp=a; a=b; b= temp;return a;}

int swap_cr(const int& a ,const int& b)
{
	//int temp; temp=a; a=b; b= temp;return a;
	return a;
}

