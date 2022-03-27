#include <iostream>
#include <cmath>
using namespace std;

int main()
{
int a,b,c,r,d;
cout << "Inserisci 3 numeri" << endl;
cin >> a >> b >> c;
if(b%2==0){
	b=b/2;
	d=(a*c);
}
else{
	d=4*(a*c);
}
if((b*b-d)>=0){
	r=sqrt(b*b-d);
	cout << "La radice e' uguale a: " << r << endl;
}
else{
cout << "Numero complesso indiciato Kappastar" << endl;
}


}