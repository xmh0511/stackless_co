#include <iostream>
#include "stackless_co.hpp"
auto test() {
	int a = 0;
	int b = 0;
	CO_BEGIN(a, b)
		std::cout << "begin0 a = " << a << std::endl;
	CO_yiled()
		std::cout << "resume0" << b << std::endl;
	CO_END()
}
auto show() {
	CO_BEGIN()
	{
		std::cout << "begin 1" << std::endl;
	}
	CO_yiled()
	{
		std::cout << "resume 1" << std::endl;
	}
	CO_yiled()
	{
		std::cout << "resume 2" << std::endl;
	}
	CO_END()
}
int main() {
	auto co = test();
	auto c02 = show();
	co();
	c02();
	co();
	c02();
	//c02();
}
