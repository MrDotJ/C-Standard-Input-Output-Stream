#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	string filename;
	
	cout << "Enter filename for new file: ";
	cin >> filename;

	//4.call ofstream << to put string into a file;
	ofstream fout(filename.c_str());	//cOut to the File Stream
	fout << "For your eyes only!\n";
	cout << "Enter your secret number: ";

	float secret;
	cin >> secret;
	fout << "Your secret number is " << secret << endl;
	
	fout.clear();
	fout.close();
	
	ifstream fin(filename.c_str());		//cIn something from File Stream
	cout << "Here are the contents of " << filename.c_str() << ": \n";

	char ch;
	while (fin.get(ch))
	{
		cout << ch;
	}
	cout << "Done! \n";
	
	fin.clear();
	fin.close();
	cout << "Other file read test:\n";

	//1.get all by calling ifstream.rebuf();
	ifstream fin2(filename.c_str());
	cout << "Here are some contents of " << filename.c_str() << ": \n";
	cout << fin2.rdbuf();
	fin2.clear();
	fin2.close();

	//2.get a char every call get();
	ifstream fin3("test.txt");
	char ch;
	while (fin3.get(ch))
	{
		cout << ch;
	}

	
	//3.get a line every call getline();
	char* p = new char[30];
	memset(p, 0, 30);
	fin3.getline(p, 30);
	cout << p;
	fin3.getline(p, 30);
	cout << p;
	fin3.getline(p, 30);
	cout << p;
	fin3.clear();
	fin3.close();


	system("pause");
	return 0;
}