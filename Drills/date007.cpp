#include "../std_lib_facilities.h"

namespace UDChrono{

class Year{

	static constexpr int min = 1800;
	static constexpr int max = 2077;

public:
	class Invalid{};
	Year(int x): y(x) {if(x < min || x > max) throw Invalid{}; }
	int year() {return y;}
	void increment() {y++; if( y > max) throw Invalid{};}

private:
	int y;

};

Year operator++(Year& year)
{
	 year.increment();
}

ostream& operator<<(ostream& os , Year year)
{
	return os << year.year();
}

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
		Year year ;
		Month month;
		int day;
	public:
		class Invalid{};
		Date(): year(Year{2001}),month(Month::jan),day(1) {}  // alapértelmezett konstruktor
		Date(Year y, Month m, int d) :year(y),month(m),day(d) {if (!is_valid()) throw Invalid{};}  //konstruktor azt határozza meg hogy hogyan nézzen ki egy adott példány
		
		bool is_valid();
		void add_day(int n);    // ez pedig ,hogy hogyan viselkedjen egy adott példány
		
		Year get_year() const {return year;}
		Month get_month() const {return month;}
		int get_day() const {return day;}
};

bool Date:: is_valid()
{
	if(day < 1 || day>31) return false;

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
			++year;
		}
	}
}
} //UDChrono end!

ostream& operator<< (ostream& os , UDChrono::Date& date)
{
	return os << date.get_year()
			<< '.' << date.get_month()
			<< '.' << date.get_day() << '.';
}

istream& operator>>(istream& is , UDChrono::Date& date)
{
	int y,m,d ;
	char d1,d2;
	is >> y >> d1 >>m >> d2 >> d;
	if(!is) return is;
	if(d1 != '.' || d2 != '.')
	{
		cout << "Invalid format\n";
		is.clear(ios_base::failbit);
		return is;
	}

	date = UDChrono::Date{UDChrono :: Year{y}, UDChrono::Month(m-1),d};
	return is;

}

int main()
try{
	
	UDChrono :: Date today {UDChrono:: Year{2020},UDChrono :: Month::aug,31};

	
	cout << "Date: " << today << endl;

	UDChrono:: Date tomorrow ;


	cout << "Please enter a valid date in YYYY.MM.DD format.\n";
	cin >> tomorrow;

	cout << "Date entered: " << tomorrow << endl;

	return 0;

}catch(UDChrono:: Date::Invalid){
	cout << "Invalid date\n";
	return 1;
}catch(UDChrono:: Year::Invalid){
	cout << "Invalid year\n";
	return 1;
}catch(exception& e){
	cout << e.what() << endl;
	return 1;
}