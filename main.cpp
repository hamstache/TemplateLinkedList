#include "LinkedListT.h"
#include <iostream>
using namespace std;


int main(){
    
    
	LinkedListT<int> iList(0);
	iList.push_back(1);
	iList.push_back(2);
	iList.push_back(3);
	iList.push_back(4);
	cout << "iList is: " << iList << endl;
    
	iList.push_front(5);
	iList.push_front(6);
	iList.push_front(7);
	cout << "and now iList is: " << iList << endl << endl;
    
	LinkedListT<double> dblList(0);
	dblList.push_back(1.23);
	dblList.push_back(3.45);
	dblList.push_back(6.78);
	cout << "dblList is: " << dblList << endl << endl;
    
	LinkedListT<string> strList(0);
	strList.push_back("four");
	strList.push_back("score");
	strList.push_back("and");
	strList.push_back("seven");
	strList.push_back("years");
	strList.push_back("ago");
	cout << "strList is: " << strList << endl << endl;
    
	strList.push_front("our");
	strList.push_front("fathers");
	strList.push_front("brought");
	strList.push_front("forth");
	strList.push_front("on");
	strList.push_front("this");
	strList.push_front("continent");
	cout << "and now strList is: " << strList << endl << endl;
    
	//cin.get();
	return 0;
}
