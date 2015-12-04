#include<iostream>
using namespace std;
class base
{
public:
	base(){
		cout <<" base"<<endl;
	}
	~base(){
		cout<<"base des"<<endl;
	}

	virtual void foo()= 0;
	
};



class der: public base
{
public:
	der(){
		cout<<" derived"<<endl;
	}
	~der()
	{
		cout<<"der des"<<endl;
	}

	void foo()
	{
		cout<<"foo"<<endl;
	}
	
};


int main(int argc, char const *argv[])
{
	base *b = new der;

	b->foo();

	delete b;
	return 0;
}