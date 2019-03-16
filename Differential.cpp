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


