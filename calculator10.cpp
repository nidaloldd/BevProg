#include "std_lib_facilities.h"

constexpr char number = '8';
constexpr char quit = 'q';
constexpr char print = ';';
constexpr char result = '=';
constexpr char let = 'L';
constexpr char name = 'a';
constexpr char sqare_root = '@';

const string declkey = "let";
const string sqrtkey = "sqrt"; 

double expression(); // bevezetjük a nevet

class Variable{
public:
		string name ;
		double value;
};

vector <Variable> var_table;  //változók táblázata

bool is_declared(string var){
	for (const auto& v : var_table)
		if(v.name == var) return true;
	return false;

}

double define_name(string var , double val){
	if(is_declared(var)) error("Variable is is declared",var);
	var_table.push_back(Variable{var,val});
	return val;
}

double get_value(string s){
	for(const auto& v : var_table)
		if(v.name == s) return v.value;
	error("get: variable not defined");
}

void set_value(string s , double d){
		for(auto& v : var_table)
			if(v.name == s)
			{	
				v.value=d;
				return;
			}
		error("set: variable not defined");		
}

class Token{
public:
	char kind;
	double value ;
	string name;
	Token (): kind(0) {}
	Token (char ch) : kind(ch),value(0) {}    // konstruktor fügvények
	Token (char ch , double val ): kind (ch),value(val) {}
	Token (char ch ,string n): kind (ch),name (n) {}
};

class Token_stream {
public:
	Token_stream();
	Token get();
	void putback (Token t);
	void ignore(char c);
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
		case quit:
		case print:
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '=':
		   return Token(ch);   // a Token kind nál fog megjelenni

		case '.':     // pl 0.5 --> .5  ként írjuk be
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		{
			cin.putback(ch);
			double val = 0;
			cin >> val;
			return Token(number ,val);

		}
		//isalpha() visszatér igazzal hogy ha a paraméter betű
		// isdigit()
		default:
		{
			if(isalpha(ch)){     
				string s ;
				s += ch;
				while(cin.get(ch) && (isalpha(ch) || isdigit(ch) ) )   s+=ch;
				cin.putback(ch);
				if(s == declkey) return Token{let};
				else if (s == sqrtkey) return Token{sqare_root};
				else if (is_declared(s))
					return Token(number , get_value(s));
				return Token{name , s};

			} 
			error("Bad token");                

		}

	}
}

void Token_stream ::ignore (char c)
{
	if(full && c == buffer.kind)
	{
		full = false;
		return;
	}

	char ch = 0;
	while(cin >> ch)
		if(ch == c) return;



}


Token_stream ts;

double calc_sqrt(){

	char ch ;
	if(cin.get(ch) && ch != '(') error("'(' expected");
	cin.putback(ch);
	double d = expression();
	if(d < 0) error("sqrt : negative value");
	return sqrt(d);


}

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
    	case number :
    		return t.value;
    	case '-':
    		return -primary();
    	case '+':
    		return primary();
    	case sqare_root:
    	    return calc_sqrt();	    	
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
			case '/':
			{						     // ha case ágba változót deklarálünk az {kapcsos} ben van!!
				double d = primary();
				if (d==0) error("divide by zero");      // elkérjük az értéket és megnézzük hogy nulla e
				left /= d;
				t = ts.get();
				break;
			}
			case '%':

			{  /*
				double d = primary();
				if (d==0) error (" % zero divider");
				left = fmod(left , d);
				t = ts.get();
				break; 
				*/
				int i1 = narrow_cast<int>(left);
				int i2 = narrow_cast<int>(primary());
				if (i2==0) error("%: zero divider");
				left = i1 % i2;
				t= ts.get();
				break ;
			}
				
			/*	left %= primary();
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

void celan_up_mess(){
	ts.ignore(print);
}

double declaration(){

	Token t = ts.get();
	if(t.kind != name) error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if(t2.kind != '=') error(" '=' expected in declaration");

	double d = expression();
	define_name(var_name,d);
	return d;

}

double statement()
{
	Token t = ts.get();
	switch(t.kind){

		case let :
			return declaration();
		default :
			ts.putback(t);
			return expression();	

	}


}

void calculate (){

	//double val = 0;

	while(cin)
	try{
		Token t = ts.get();

		while(t.kind == print) t = ts.get();
		if (t.kind == quit) return;


		ts.putback(t);
		cout << result << statement() << endl;



	} catch (exception& e){
		cerr << e.what() << endl;
		celan_up_mess();
	}


}


int main()
try {

	define_name("pi" , 3.141592654);
	define_name("e" , 2.718281828);

    calculate();

    return 0;

}catch (exception& e) {	
		

		cerr << e.what() << endl ;
		return 1;
}catch (...) {

	cerr << "exception\n" ;
	return 2;	
}