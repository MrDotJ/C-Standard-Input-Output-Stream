#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<algorithm>
#include<locale>
#include<cstdio>
using namespace std;

//stream based on string
int main02()
{
	return 0;
}
//streamBuffer

int main03()
{
	
	ostreambuf_iterator<char> bufwrite(cout);
	string hello("Hello,world!.\n");
	copy(hello.begin(), hello.end(), bufwrite);	//copy(source==>dest)
	istreambuf_iterator<char>inpos(cin);
	istreambuf_iterator<char>endpos;
	ostreambuf_iterator<char>outpos(cout);
	while (inpos!=endpos)
	{
		*outpos = *inpos;
		++inpos;
		++outpos;
	}
	system("pause");
	return 0;
	
	string hello = string("hello my_ostreambuf \n");
	ostreambuf_iterator<char> mycoutbuf(cout);
	istreambuf_iterator<char> mycinbuf(cin);
	istreambuf_iterator<char> myend;
	copy(hello.begin(), hello.end(), mycoutbuf);

	while (mycinbuf!=myend)		//if null call get();
	{
		*mycoutbuf = *mycinbuf;
		mycoutbuf++;
		mycinbuf++;
	}
	system("pause");
	return 0;
}*/

/*
std::endl	:	insert '\n'							std::ios::right		:
std::ends	:	insert '\0'							std::ios::scientific
std::dec	:	dec									std::ios::showbase
std::hex	:	hex
std::oct	:	oct
std::flush	:	flush the buff
std::fixed	:	cout as 1.99999 not as 1e-3
*/
int main()
{
	int a = 13;
	cout << ends << dec << a << endl << hex << a << endl << dec << fixed << setprecision(4) << a << endl;
	cout << endl;
	system("pause");
	return 0;
}


//stream based on file
int mai01()
{
	//ifstream & ofstream : ifstream(char*);ofstream(char*)
	//ifstream.open(char*,ios_base::);
	//getline : getline(cin,buffer) & ifstream.getline(char*,size)
	//getline : get a line of char from cin or from char*
	string filename;
	/*cerr与cout的主要区分就是，cout输出的信息可以重定向，而cerr只能输出到标准输出（显示器）上。 　　
	例如下面程序编译后生成test.exe
	// test.cpp
	int main()
	{
　　		cout << "hello world---cout" << endl ;
　　		cerr << "hello world---cerr" << endl ;
　　		return 0;
	} 　　在命令行模式下键入下面的命令： 　　test >>cout.txt
	运行结果是：
	在生成的cout.txt文件中输出了"hello world---cout"
	同时在显示器上输出了"hello world---cerr"
	也就是说cout的输出可以重定向到一个文件中，而cerr必须输出在显示器上。
	cout是标准输出流,与cerr的区别在于cerr不经过缓冲区,直接向显示器输出信息,而cout中的信息存放在缓冲区,缓冲区满或者遇到endl时才输出。*/
	
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
	char ch3;
	while (fin3.get(ch3))
	{
		cout << ch3;
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

	//4.ifstream.open(char*,ios_base::in &&out &&app)
	filename = (string)string("test.txt");

	fin.open(filename.c_str(), ios_base::in);
	if (fin.is_open())
	{
		cout << "Here are the current contents of the \'" << filename << "\':" << endl;
		cout << fin.rdbuf();
		cout << endl;
	}
	fin.clear();
	fin.close();

	ofstream fout;
	fout.open(filename.c_str(), ios_base::out | ios_base::app);
	if (!fout.is_open())
	{
		cerr << "Can't open " << filename << " file for output.\n";
		exit(EXIT_FAILURE);
	}
	cout << "Enter new file contents (to be append):\n";

	//5.call getline every to get all the lines
	string buffer;
	while (getline(cin,buffer)&&buffer.size()>0)
	{
		fout << buffer << endl;
	}
	fout.clear();
	fout.close();

	fin.open(filename.c_str(), ios_base::in);
	if (fin.is_open())
	{
		cout << "Here are the current content of the \'" << filename << "\':" << endl;
		cout << fin.rdbuf();
		cout << endl;
	}
	fin.clear();
	fin.close();


	//6.the difference between cout and cerr;
	cout << "input wrong words" << endl;
	cerr << "wrong\n";


	//7.control output
	//cout<<fixed<<right is only valid when copo with setw(int);
	//cout<<fixed : mean cout 0.000001 not 1e-6;cout<<right : mean right;
	//cout<<setw(int)<<setprecision(int)
	double a = 5.00098;
	double b = 0.00098;
	double c = 0.000009;
	cout << fixed << right;
	cout << setw(10) << setprecision(5) << a << endl;
	cout << setw(10) << setprecision(5) << b << endl;
	cout << setw(10) << setprecision(5) << c << endl;

	//8.iofstream.open()   &&   read&write through binary
	//ifstream.open(char*,ios_base::in   |ios_base::binary   |ios_base::out   |ios_base::app)
	//ifstream.read(struct*,sizeof(struct));
	//ofstream.write(struct*,sizeof(struct));pay attention to ios_base::app;
	//this example open()&read()by binary&write()by binary
	filename = string("planets.dat");
	struct planet
	{
		char	name[20];
		double	population;
		double	g;
	};
	planet p1;
	cout << fixed << right;
	ifstream fin;
	fin.open(filename.c_str(), ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout << "Here are the current contents of the " << filename << "file: \n";
		while (fin.read((char*)&p1, sizeof(p1)))
		{
			cout << setw(20) << p1.name << ":" << setprecision(0) << setw(12) << p1.population << setprecision(2) << setw(10) << p1.g << endl;
		}
		fin.clear();
		fin.close();
	}
	ofstream fout(filename.c_str(), ios_base::out | ios_base::app | ios_base::binary);
	if (!fout.is_open())
	{
		cerr << "Can't open" << filename << " file for output: \n";
		exit(EXIT_FAILURE);
	}
	cout << "Enter planet name (enter a blank line to quit):\n";
	cin.get(p1.name, 20);
	while (p1.name[0]!='\0')
	{
		char ch;
		while (ch = cin.get() != '\n')		continue;
		cout << "Enter planetary population: ";
		cin >> p1.population;
		cout << "Enter planet's acceleration of gravity: ";
		cin >> p1.g;
		while (cin.get() != '\n')		continue;
		fout.write((char*)&p1, sizeof(p1));
		cout << "Enter planet name (Enter a blank line to quit): \n";
		cin.get(p1.name, 20);
	}
	fout.close();
	fin.clear();
	fin.open(filename.c_str(), ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout << "Here are the new contents of the " << filename << "\n";
		while (fin.read((char*)&p1,sizeof(p1)))
		{
			cout << setw(20) << p1.name << ":" << setprecision(0) << setw(12) << p1.population << setprecision(2) << setw(10) << p1.g << endl;
		}
		fin.close();
	}
	cout << "Done. \n";

	//9.read()in everywhere
	ifstream fin1(filename.c_str());
	cout << fin1.rdbuf();
	cout << endl;
	fin1.seekg(0);
	cout << fin1.rdbuf();

	//10.fstream has two functions;
	//seekg(pos):seekg()is used for input_pointer==>ifstrema   go to the place to input
	//seekp(pos):seekp()is used for output_pointer==>ofstream  output the pos ;
	//tellg()&tellp():tell the position
	//ios_base::beg		|ios_base::cur		|ios_base::end
	char file[20];
	cout << "Input filename: ";
	cin >> file;
	filename = string(file);
	if (filename.empty())
	{
		exit(EXIT_FAILURE);
	}
	cout << "This example is used for test seekg(p) or tellg(p). " << endl;
//	fstream finout, fout;
	finout.open(filename.c_str(), ios_base::in | ios_base::out);
	if (finout.is_open())
	{
		cout << finout.rdbuf();
		finout.seekg(0);
		cout << finout.rdbuf();
	}
	finout.seekg(0, ios_base::beg);

	fout.open("b.txt", ios_base::out);
	if (fout.is_open())
	{
		fout << finout.rdbuf();
		fout.close();
	}
	cout << endl;
	fout.open("c.txt", ios_base::out);
	if (fout.is_open())
	{
		cout << finout.tellg();
		finout.seekp(25, ios_base::beg);
		fout.close();
	}
	cout << endl;
	fout.open("d.txt", ios_base::out);
	if (fout.is_open())
	{
		finout.seekg(10, ios_base::beg);
		fout << finout.rdbuf();
		fout.close();
	}
	cout << endl;
dd:	system("pause");
	return 0;
}



