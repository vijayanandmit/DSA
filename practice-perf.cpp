#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int p1, p2, p3, p4;
	cin >> p1>>p2>>p3>>p4;
	int count = 0;
	
	if(p1>9)
	    ++count;
	if(p2>9)
	    ++count;
	if(p3>9)
	    ++count;
	if(p4>9)
	    ++count;
	    
	cout << count << endl;
	
	return 0;
}
