#include "std_lib_facilities.h"

int main()
{
    double number;
    string sign = " " ;
    double max =0 ;
    double min =0 ;
    string unit ;
    vector<double> v;

    while(sign != "|")
    {
    	cout << "if you want to start please enter a karakter!\n";
        cout << "if you are done , just type a '|' charakter \n\n";
      
       cin >> sign;

      cout << endl;

      if (sign == "|")
      {
      	 break;
      }
      else
      {
         cout << "please enter a number and a unit (cm,m,in,ft) !\n";
         
         cin >> number >> unit;

         while (!(unit == "cm" or unit == "m" or unit == "in" or unit == "ft"))
          {
              cout << "wrong unit. type it again please!";
              cin >> unit;
          }


     if (unit=="m")
     {
        v.push_back(number);
     }
     if (unit=="cm")
     {
     	v.push_back(number/100);
     }
     if (unit=="in")
     {
     	v.push_back((number*2.54)/100);
     }
     if (unit=="ft")
     {
     	v.push_back((number*12*2.54)/100 );
     }

       /* 

     if (unit=="m")
     {
        cout << number <<" "<< unit << " = " << number*100 << " cm /" << (number*100)/2.54 << " in /" <<((number*100)/2.54)/12 << " ft " << endl;

     }
     if (unit=="cm")
     {
     	cout << number <<" "<< unit << " = " << number/100 << " m /" << number/2.54 << " in /" << (number/2.54)/12 << " ft " << endl;
           
     }
     if (unit=="in")
     {
     	cout << number <<" "<< unit << " = " << (number*2.54)/100 << " m /" << number*2.54 << " cm /" << number/12 << " ft " << endl;
           
     }
     if (unit=="ft")
     {
     	cout << number <<" "<< unit << " = " << (number*12*2.54)/100 << " m /" << number*12*2.54 << " cm /" << number*12 << " in " << endl;
           
     }
  
      */


      }
      

    }

     sort(v.begin(),v.end());
     double sum=0;

    cout << "the smallest number is " << v[0] << endl;
    cout << "the largest number is " << v[v.size()-1] << endl;
    cout << "the number of values = " << v.size() << endl;

    for (int i = 0; i < v.size(); ++i)
    {
    	sum+=v[i];
    }

    cout << "the sum of values = " << sum << endl ;


    for (int i = 0; i < v.size(); ++i)
    {
    	cout << v[i] << endl ;
    }


	return 0;
}