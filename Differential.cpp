#include<iostream>
#include<cmath>
using namespace std;


class differential{
	private:
		double x,x1,x2; //for entering values of coefficients y'' , y' and y
		double y,y1; // storing values of roots
		double D; //discriminant
	public:
		double calcD();
		double calcroot();
		double eval();
		void print();
		void initialize();
};
void differential :: initialize(){
	double a,b,c;
	cout<<"Enter the coefficients of y'' , y' and y";
	cin>>a>>b>>c;
	x = a;
	x1 = b;
	x2 = c;
}
double differential :: calcD(){
	double m;
	m = (pow(x1,2) - (4*x*x2));
	return m;
}
double differential :: calcroot(){
	calcD();
	
}
int main(){
	return 0;
}
