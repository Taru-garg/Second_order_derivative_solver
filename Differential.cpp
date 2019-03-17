#include<iostream>
#include<cmath>
using namespace std;


class differential{
	protected:
		double x,x1,x2; //for entering values of coefficients y'' , y' and y
		double y,y1; // storing values of roots
		double D; //discriminant
	public:
		double calcD(); //calculating discriminant
		void calcroot(); //calculating roots
		void print(); //print func()
		void initialize(); //function for taking input values
		void forim(double); //for special case i.e of imaginary roots
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
	D = (pow(x1,2) - (4*x*x2)); // b^2 - 4ac
	return D;
}
void differential :: calcroot(){
	calcD();
	double m;
	m = calcD();
	if(m<0){
		 forim(m);   //calling func() forim
	}
	if (m> 0)
    {
        y = (-x1+sqrt(m))/(2*x);     //calculating roots
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
	cout<<"y=e^("<<real<<"x)*(Acos("<<imag<<"x)+Bsin("<<imag<<"x))"<<endl;  //printing answer
}
class legendre : public differential
{ 
	public:
		
};
int main()
{
int n,i,c;
cout<<"\t\t\t\t\t\t\t\t\t\t\t CONDITION!! all equations be in Homogenous form"<<endl<<endl;
cout<<"Enter Number of Differential Equations"<<endl;						//enter no differential equation
cin>>n;
cout<<"Enter type of differential Equation"<<endl<<"1. General"<<endl<<"2. Legendre"<<endl;
cin>>c;
differential equ[n];
switch(c){
	case 1: //for general differential equation
				//array of number of differential equation

		for(i=0;i<n;++i)
		{
			cout<<"Enter"<<" equation "<<i+1<<"'s"<<" differential's coffecients"<<endl;
			cout<<"Coefficient of y'' cannot be 0"<<endl;	
			equ[i].initialize();      //calling to initilization function
			equ[i].calcroot();			//calling to calcutate roots
			cout<<"___________________________________________________________________________________________________________"<<endl;
		}
		break;
	case 2:	//for legendre's differential equation
		break;
}

return 0;
}
