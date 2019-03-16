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
		void calcroot();
		void print();
		void initialize();
		void forim(double);
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
void differential :: calcroot(){
	calcD();
	double m;
	m = calcD();
	if(m<0){
		 forim(m);
	}
	if (m> 0)
    {
        y = (-x1+sqrt(m))/(2*x);
        y1 = (-x1-sqrt(m))/(2*x);
        cout<<endl<<"Ae^("<<y<<"x)+Be^("<<y1<<"x)"<<endl;
    }
    else if (m == 0)
    {
        y = y1 = -x1/(2*x);
        cout<<endl<<"(A+Bx)e^("<<y<<"x)"<<endl;

    }
	
}
void differential :: forim(double o){
	double real,imag;
	real = -x1/(2*x);
	imag = sqrt(-o)/(2*x);
	cout<<"Your answer is e^("<<real<<"x)*(cos("<<imag<<"x)+sin("<<imag<<"x)"<<endl;
}

