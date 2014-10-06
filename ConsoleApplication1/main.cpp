// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	using namespace std;

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	cout << "Hello world" << endl;
	cout << "Hello world!" << endl;
	int x;
	cin >> x;
	cout << "you entered" << x << endl;
	cin.clear();
	cin.ignore(255, '\n');
	cin.get();
	while (true){
		
	}

	return 0;
}

