#include "../std_lib_facilities.h"

int main()
try{


	struct Point
	{
		int x;
		int y;
	};

	vector<Point> original_points;
	vector<Point> processed_points;
	string file = "My_data.txt";

	for (int i = 0; i < 6; ++i)
	{
		original_points.push_back(Point{randint(50),randint(50)});
	}
	

	for (const auto& r :original_points )
	{
		cout << r.x << ' ' << r.y << endl;
	}


			
			ofstream out {file};

			if(!out) error("cant open the output file" , file);
			else cout << "tha data is stored in 'My_data.txt'!\n";

			for(const auto& r : original_points)
			{
				out << r.x << ' ' << r.y << endl;
			}

			out.close();



		ifstream inp {file};

		if(!inp) error("cant open the input file!",file);

		for(int i=0; i<6; i++ )
		{
			int x ,y;
			inp >> x >> y;
			processed_points.push_back(Point{x,y});
		}

		cout << "original_points\n";
		for(const auto& r : original_points)
		{
			cout << r.x << ' ' << r.y << endl;
		}
		cout << "processed_points\n";
		for(const auto& r : processed_points)
		{
			cout << r.x << ' ' << r.y << endl;
		}

		bool different = false;
		if(original_points.size()!=processed_points.size()) cout << "the size not match! \n";
		else 
		{
			cout << "the size  match! \n";

			for (int i = 0; i < 6; ++i)
			{
				if(original_points[i].x != processed_points[i].x && original_points[i].y != processed_points[i].y)
				 {
				 	cout << "the [" << i << ".]" << "element is differ\n" ;
				 	different== true;

				 }
			}
		}

		if(!different) cout << "the 2 vector equal!\n";

	return 0;

}catch(runtime_error& e){
	cerr << "Error : " << e.what() << endl;
	return 1;

}catch(...){
	cerr << "some error\n";
	return 2;
}