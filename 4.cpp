// 4. Implement a class Complex which represents the Complex Number data type. Implement the following
// a) Constructor (including a default constructor which creates the
// Complex number 0+0i).
// b) Overload operator+ to add two Complex numbers.
// c) Overload operator* to multiply two Complex numbers.
// d) Overload operators << and >> to print and read Complex Numbers.

#include <iostream>
using namespace std;


class Complex{
	
public:
	int real;
	int img;
	Complex(int r = 0, int i = 0){
		real=r;
		img=i;
	}

	friend Complex operator + (Complex c1, Complex c2);
	friend Complex operator * (Complex c1 , Complex c2);
	friend istream &operator >> (istream &in, Complex &c1);
	friend ostream &operator << (ostream &out, const Complex &c1);
};

 Complex operator + (Complex c1, Complex c2){
 	return Complex(c1.real + c2.real , c1.img + c2.img);
 }

// (a+ib) (c+id) = ac +i(ad + bc) -bd
Complex operator * (Complex c1 , Complex c2){
	return Complex(c1.real*c2.real - c1.img*c2.img , c1.real*c2.img + c1.img*c2.real);
}
	istream &operator >> (istream &in, Complex &c1){
		cout<<"Enter the real part and imaginary part of Complex number"<<endl;
		in>>c1.real>>c1.img;
		return in;
	}
	ostream &operator << (ostream &out, const Complex &c1){
		if(c1.img > 0) out<<c1.real<<" + " <<c1.img;
		else out<<c1.real<<" "<<c1.img;
		return out;
	}

int main(){
	Complex c1(4,5);
	Complex c2(5,6);
 	cout<<c1+c2<<endl;
 	cout<<c1*c2<<endl;

	return 0;
}