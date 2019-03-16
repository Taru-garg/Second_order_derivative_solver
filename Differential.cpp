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
		void forim();
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
	D = (pow(x1,2) - (4*x*x2));
	return D;
}
double differential :: calcroot(){
	calcD();
	if(D<0){
		 forim();
	}
	if (D> 0)
    {
        y = (-x1+sqrt(D))/(2*x);
        y1 = (-x1-sqrt(D))/(2*x);
    }
    else if (D == 0)
    {
        y = y1 = -x1/(2*x);

    }
	
}
void differential :: forim(){
	double real,imag;
	real = -x1/(2*x);
	imag = sqrt(-D)/(2*x);
	cout<<"Your answer is e^("<<real<<"x)*(cos("<<imag<<"x)+sin("<<imag<<"x)"<<endl;
}
int main(){
	return 0;
}
