#include "std_lib_facilities.h"

int main()
{
	string first_name;
	string line=" ";
	string friend_name;
	int age_of_recipient;
	char friend_sex=0;

	cout << "Please enter your friend first name!  ";
	cin >> first_name;

	cout << "Now enter another friend name!  ";
	cin >> friend_name;

	cout << "and your friend sex. (m/f) ";
	cin >> friend_sex;
  
  while(!(friend_sex=='m' or friend_sex=='f'))
  {
     cout << "error " << "(m)ale or (f)emale! ";
      cin >> friend_sex;
  }

	cout << "type the age of the recipient.     ";
	cin >> age_of_recipient;
	
  while (age_of_recipient<=0 or age_of_recipient>=110)
	{
       cout << "error" <<"(you`re kidding!)     ";
       cin >> age_of_recipient;
	}

  
    cout << "\n\n" << "Dear "<< first_name<<",\n\n";
    cout <<"HOW are you? I am fine. I miss you. HAVE you seen "
     << friend_name << " lately?\n";
    
   

    if (friend_sex=='m')
    {
        cout << "if you see "<< friend_name << " Please ask him to call me.\n";
    }
   else if (friend_sex=='f')
   {
      cout << "if you see "<< friend_name << " Please ask her to call me.\n";

   }
  
    cout << "I hear you just had a birthday and you are "<<age_of_recipient <<" years old.\n";

    if (age_of_recipient<12)
    {
    	cout << "Next year you will be "<<age_of_recipient+1 << ".\n";
    }
     if (age_of_recipient==17)
    {
    	cout << "Next year you will be able to vote. \n";
    }
    if (age_of_recipient>70)
    {
    	cout << "I hope you are enjoying retirement.\n";
    }
   
    string your_name;
    cout << "Yours sincerely\n\n\n" ;   cin >> your_name;

	return 0;
}