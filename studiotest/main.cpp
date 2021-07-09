#include<iostream>
#include<windows.h>

int main()
{
	SYSTEM_INFO si;
	::GetNativeSystemInfo(&si);
	std::cout << "Hello!\n";
	return 0;
}