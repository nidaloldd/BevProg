#include "../std_lib_facilities.h"

class Date{
//	private:     nem kötelező kiirni!
		int year , month, day;
	public:
		class Invalid{};
		Date(int y, int m, int d) :year(y),month(m),day(d) {if (!is_valid()) throw Invalid{};}  //konstruktor azt határozza meg hogy hogyan nézzen ki egy adott példány
		bool is_valid();
		void add_day(int n);    // ez pedig ,hogy hogyan viselkedjen egy adott példány
		int get_year() {return year;}
		int get_month(){return month;}
		int get_day() {return day;}
};

bool Date:: is_valid()
{
	if(month < 1 ||month >12 ||year <0 || day < 1 || day>31) return false;

	return true;
}

/*
Date::Date(int y ,int m ,int d)
{
	if(y > 0)
		year=y;
	else 
		error("Invalid year");
	if(month <= 12 && m>0)
		month = m;
	else error("Invalid month");
	
	if(d>0 && d<=31)
		day = d;
	else error("Invalid day");
}
*/

void Date :: add_day(int n)
{
	day += n;
	if(day > 31)
	{
		month++;
		day -= 31;
		if(month > 12)
		{
			year++;
			month -= 12;
		}
	}
}

int main()
try{
		Date today {2020,8,31};

	/*
	cout << "Date: " << today.year << '.'
		<< today.month << '.' << today.day << '.' << endl;

	*/
	today.add_day(1);	
	
	cout << "Date: " << today.get_year() << '.'
			<< today.get_month() << '.' << today.get_day() << '.' << endl;

	return 0;

}catch(Date::Invalid){
	cout << "Invalid date\n" << endl;
	return 1;
}catch(exception& e){
	cout << e.what() << endl;
	return 1;
}