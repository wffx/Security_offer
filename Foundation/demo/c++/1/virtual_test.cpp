#include <iostream>
#include <string>

using namespace std;

class animal {
public: 
	animal() = default;
	animal(const string s) {
		name = s;
	}
	virtual void pnt()=0;
	virtual void setname()=0; 
	virtual ~animal() = default;
//protect:
	string name;
};

class cat: public animal {
public:
	cat() = default;
	cat(const string s) {
		name = s;
	} 
	void pnt() override;
	void setname() override {
		name = "I am cat\n";
		return;
	}
};

void cat::pnt() {
	cout << name << endl;
	return;
}

void print(const animal &an) {
	cout << "Print:" << an.name << endl;
	return;
}

int main(){ 
    cat c = cat();

	c.setname();
	c.pnt();

	print(c);
	return 0;
}
