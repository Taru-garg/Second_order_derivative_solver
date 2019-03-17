#include<iostream>
#include<cmath>
using namespace std;


class homogeneous_differential{
	protected:
		double a1,b1; //for legendre
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
void homogeneous_differential :: initialize(){
	double a,b,c;
	cout<<"Enter the coefficients of y'' , y' and y"<<endl;
	cin>>a>>b>>c;
	x = a;
	x1 = b;
	x2 = c;
}
double homogeneous_differential :: calcD(){
	D = (pow(x1,2) - (4*x*x2)); // b^2 - 4ac
	return D;
}
void homogeneous_differential :: calcroot(){
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
void homogeneous_differential :: forim(double o){
	double real,imag;
	real = -x1/(2*x);
	imag = sqrt(-o)/(2*x);
	cout<<"y=e^("<<real<<"x)*(Acos("<<imag<<"x)+Bsin("<<imag<<"x))"<<endl;  //printing answer
	
}
class legendre : public homogeneous_differential
{ 
	protected:
		double n1,n2,n3;
	public:
		void initialize()
		{ 
			cout<<"Enter a and b ((a+bx)^2)y''"<<endl;
			cin>>a1>>b1;
			cout<<"Enter the value of coefficient of y"<<endl;
			cin>>n3;
		}
		void new_eqn()
		{
			n1 = pow(b1,2);
			n2 = b1 - pow(b1,2);
		}
		double caclcD()
		{
			D = (pow(n2,2) - (4*n1*n3)); // b^2 - 4ac
			return D;
		}
		void calcroot()
		{	double m;
			m = calcD();
			if(m<0)
			{
		 			forim(m);   //calling func() forim
			}
			
    		else if(m == 0)
   			 {		
        		y = y1 = -n2/(2*n1);
        		cout<<endl<<"(A+B(ln("<<a1<<"+"<<b1<<"x))*e^(("<<"ln("<<a1<<"+"<<b1<<"x))/"<<1/y1<<")"<<endl;
			}
			else
    			{
       				 y = (-n2+sqrt(m))/(2*n1);     //calculating roots
       				 y1 = (-n2-sqrt(m))/(2*n1);
        			cout<<endl<<"Ae^(ln("<<a1<<"+"<<b1<<"x))/"<<y<<"+"<<"Be^(ln("<<a1<<"+"<<b1<<"x))/"<<1/y1<<endl;
    			}
    }
	void forim(double o){
		double real,imag;
		real = -n2/(2*n1);
		imag = sqrt(-o)/(2*n1);
		cout<<"y=e^("<<real<<"*ln("<<a1<<"+"<<b1<<"x))("<<"Acos("<<imag<<"ln("<<a1<<"+"<<b1<<"x))"<<"+ sin("<<imag<<"ln("<<a1<<"+"<<b1<<"x))";
		
	}
		
};
int main()
{
int n,i,c;
cout<<"\t\t\t\t\t\t\t\t\t\t\t CONDITION!! all equations be in Homogenous form"<<endl<<endl;
cout<<"Enter Number of Homogeneous differential Equations"<<endl;						//enter num differential equation
cin>>n;
homogeneous_differential equ;
legendre equn;
for(int i = 1;i<=n;i++){
cout<<"Enter type of Homogeneous differential Equation"<<endl<<"1. General"<<endl<<"2. Legendre"<<endl;
cin>>c;
switch(c){
	case 1:
			cout<<"Enter"<<" equation "<<i<<"'s"<<"Differential's coffecients"<<endl;
			cout<<"Coefficient of y'' cannot be 0"<<endl;	
			equ.initialize();      //calling to initilization function
			equ.calcroot();			//calling to calcutate roots
			cout<<"___________________________________________________________________________________________________________"<<endl;
		
		break;
	case 2:	//for legendre's differential equation
			cout<<"Coefficient of y'' cannot be 0"<<endl;	
			equn.initialize();      //calling to initilization function
			equn.new_eqn();
			equn.calcroot();			//calling to calcutate roots
			cout<<"___________________________________________________________________________________________________________"<<endl;
		
		break;
}
}
return 0;
}
