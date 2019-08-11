#include <iostream>
#include <string>

using namespace std;

template <typename T>

T add(const T &a, const T &b) {
	return a+b;
}


int main() {
	int a=1, b=1;
	string x="abc", y="def";
	
	cout << add(a, b) << endl;
	cout << add(x, y) << endl;
	
	return 0;
}
