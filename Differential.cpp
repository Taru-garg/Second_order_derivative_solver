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
	cout<<"Enter the coefficients of y'' , y' and y"<<endl;
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
        cout<<endl<<"y="<<"Ae^("<<y<<"x)+Be^("<<y1<<"x)"<<endl;
    }
    else if (m == 0)
    {
        y = y1 = -x1/(2*x);
        cout<<endl<<"y="<<"(A+Bx)e^("<<y<<"x)"<<endl;

    }
}
void differential :: forim(double o){
	double real,imag;
	real = -x1/(2*x);
	imag = sqrt(-o)/(2*x);
	cout<<"y=e^("<<real<<"x)*(Acos("<<imag<<"x)+Bsin("<<imag<<"x))"<<endl;
}

int main()
{
int n,i;
cout<<"\t\t\t\t\t\t\t\t\t\t\t CONDITION!! all equations be in Homogenous form"<<endl<<endl;
cout<<"Enter Number of Differential Equations"<<endl;						//enter no differential equation
cin>>n;
differential equ[n];			//array of number of differential equation
for(i=1;i<=n;i++)
{
	cout<<"Enter"<<" "<<i<<" differential's coffecients"<<endl;	
	equ[i].initialize();      //calling to initilization function
	equ[i].calcroot();			//calling to calcutate roots
	cout<<"___________________________________________________________________________________________________________"<<endl;
}
return 0;
}
