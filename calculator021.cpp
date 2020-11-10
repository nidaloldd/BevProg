#include "std_lib_facilities.h"

double expression(); // bevezetjük a nevet

class Token{
public:
	char kind;
	double value ;
	Token (char ch) : kind(ch),value(0) {}    // konstruktor fügvények
	Token (char ch , double val ): kind (ch),value(val) {}

};

class Token_stream {
public:
	Token_stream();
	Token get();
	void putback (Token t);
private:
	bool full;
	Token buffer;

};

Token_stream ::Token_stream() : full(false), buffer(0) {}    // Token_stream osztályon belül Token_stream függvény

void Token_stream::putback (Token t)
{
	if (full) error("Token_stream buffer full");
	buffer = t;
	full = true;
}

Token Token_stream :: get()
{
	if(full)
	{ 	
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;

	switch(ch) {
		case 'q':
		case ';':
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		//case '%':
		   return Token(ch);   // a Token kind nál fog megjelenni

		case '.':     // pl 0.5 --> .5  ként írjuk be
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		{
			cin.putback(ch);
			double val = 0;
			cin >> val;
			return Token('8' ,val);

		}
		default:
			error("Bad token");
			return 0;

	}
}


Token_stream ts;

double primary()
{
  
    Token t = ts.get();
    switch(t.kind)
    {

    	case '(':
    	{
    		 double d = expression ();
    		 t = ts.get();
    		 if(t.kind != ')')  error(" ')' expected");
    		 return d;
    	}
    	case '8' :
    		return t.value;
    	default :
    		error("primary expected");
    		return 0;


    }


}

double term()
{
	double left = primary();
	Token t = ts.get();
	while(true){

		switch(t.kind){

			case '*': 
				left *=primary();
				t = ts.get();
				break;
			case '/' :
			{						     // ha case ágba változót deklarálünk az {kapcsos} ben van!!
				double d = primary();
				if (d==0) error("divide by zero");      // elkérjük az értéket és megnézzük hogy nulla e
				left /= primary();
				t = ts.get();
				break;
			}
			/*case '%':
				left %= primary();
				t = get_token();
				break;
				*/
			default	:
				ts.putback(t);
				return left;
		}

	}
}

double expression()
{
   double left = term();
   Token t = ts.get();
   while(true){

   	switch(t.kind){

   		case '+' :
   			left += term();
   			t = ts.get();
   			break;
   		case '-':
   			left -= term();
   			t= ts.get();
   			break;
   		default :
   			ts.putback(t);
   			return left ;		

   	}

   }
}


int main()
try {

    double val = 0 ;

	while(cin)
	{
		Token t = ts.get();

		if(t.kind == 'q') break;
		if (t.kind == ';')    // 1+()3*9); 6+(9/3)
		    cout << "=" << val ;
		else
			ts.putback(t);
			val = expression();
	}

	cout << "=" << val;

}catch (exception& e) {	
		
		cerr << e.what() << endl ;
		return 1;
}catch (...) {

	cerr << "exception\n" ;
	return 2;	
}