#include "../std_lib_facilities.h"

const vector<string> months =
{
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

enum class Month{
	jan,feb,mar,apr,may,jun,july,aug,sept,oct,nov,dec
};

Month operator++(Month& m)
{				//egyszerüsített if
	m = (m == Month::dec) ? Month::jan: Month(int(m)+1); // kérdés m egyenő e dec el ha igen akkor az elő ha nem akkor a második
	return m; // itt vissza kell adni az eredményt
}

ostream& operator<<(ostream& os,Month m)   // ostream referencia pl:cout
{
	return os << months[int(m)];
}


class Date{
//	private:     nem kötelező kiirni!
		int year ;
		Month month;
		int day;
	public:
		class Invalid{};
		Date(int y, Month m, int d) :year(y),month(m),day(d) {if (!is_valid()) throw Invalid{};}  //konstruktor azt határozza meg hogy hogyan nézzen ki egy adott példány
		
		bool is_valid();
		void add_day(int n);    // ez pedig ,hogy hogyan viselkedjen egy adott példány
		
		int get_year() {return year;}
		Month get_month(){return month;}
		int get_day() {return day;}
};

bool Date:: is_valid()
{
	if(year <0 || day < 1 || day>31) return false;

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
		++month;
		day -= 31;
		if(month == Month::jan)
		{
			year++;
		}
	}
}

int main()
try{
		Date today {2020,Month::aug,31};

	/*
	cout << "Date: " << today.year << '.'
		<< today.month << '.' << today.day << '.' << endl;

	*/
	today.add_day(1);	
	
	cout << "Date: " << today.get_year() << ". "
			<< today.get_month() << ' ' << today.get_day() << '.' << endl;


	return 0;

}catch(Date::Invalid){
	cout << "Invalid date\n" << endl;
	return 1;
}catch(exception& e){
	cout << e.what() << endl;
	return 1;
}