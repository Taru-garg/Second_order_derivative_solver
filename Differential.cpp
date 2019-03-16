#include<iostream>
using namespace std;


class differential{
	private:
		double x,x1,x2; //for entering values of coefficients y'' , y' and y
		double y,y1;
		double D;
	public:
		double calcD();
		double eval();
		void print();
		differential();
};
differential :: differential(){
	double a,b,c;
	cout<<"Enter the coefficients of y'' , y' and y";
	cin>>a>>b>>c;
	x = a;
	x1 = b;
	x2 = c;
}


