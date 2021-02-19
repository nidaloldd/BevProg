#include "../std_lib_facilities.h"

int main()
{
	int birth_year = 2000;

	cout << showbase << dec << birth_year <<"\t decimal"<< endl 
		 << hex << birth_year <<"\t hexadecimal"<< endl 
		 << oct << birth_year <<"\t octal"<< endl;


	cout << dec << birth_year << endl;;
	
	cout << "---------------------\n";

	int a ,b , c ,d;

	cin >> a >> oct >> b >> hex >> c >> d;
	cout << a << '\t'<<b << '\t' << c << '\t'<<d<<'\n';	
	
//-----------------------------------
	cout << 1234567.89 << "\t(defaultfloat)\n"
	<< fixed << 1234567.89 << "\t (fixed)\n"
	<< scientific << 1234567.89 << "\t(scientific)\n";

	cout << "---------------------\n";

	cout << "first name\t" << "last name\t" << "email addres\t" << "telephone number\t" << endl
		<< "Kristőf\t"<< setw(16)<< "Kardos\t" << "valakemkai@gmail.com\t"<< setw(16) << "06505546894\t" << endl
		<< "Béla\t"<< setw(16) << "Kovács\t" << "valakemi@gmail.com\t"<< setw(16) << "06205546823\t" << endl
		<< "Traktor\t"<< setw(16) << "Győző\t" << "valamami@gmail.com\t"<< setw(16) << "06243554694\t" << endl
		<< "Szatyor\t"<< setw(16) << "Emese\t" << "valaclami@gmail.com\t"<< setw(16) << "06205546894\t" << endl;

	return 0;
}