
#include <iostream>
#include <string>
using namespace std;

int main()
{
	bool a = (3 > 1);
	std::cout << std::boolalpha << a << endl;
	bool b = ((4 / 2) < 0);
	std::cout << std::boolalpha << b << endl;
	bool c = ("0" == 0);
	std::cout << std::boolalpha << c << endl;
	bool d = ((10/2) > 0 && (10/2) <= 10);
	std::cout << std::boolalpha << d << endl;
	bool e = (!(3 > 2 && 3 < 1));
	std::cout << std::boolalpha << e << endl;
	bool f = (!((3 < -5)&&(!(7 > 0))));
	std::cout << std::boolalpha << f << endl;

	return 0;
}