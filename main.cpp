#include <iostream>
#include "stackless_co.hpp"
#include <thread>
auto test() {
	int a = 0;
	int b = 0;
	CO_BEGIN(int,a, b)
	std::cout << "begin0 a = " << a << std::endl;
	std::thread t0([&promise = shared(),this]() {
		std::this_thread::sleep_for(std::chrono::seconds(5));
		promise.resume(1024);
	});
	t0.detach();
	CO_yiled()
     //int abb = 111;
	  std::cout << "resume0 " << get()<< std::endl;
	CO_END()
}
auto show() {
	CO_BEGIN(void)
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
	auto co1 = show();
	co();
	co1();
	co1();
	std::getchar();
}
