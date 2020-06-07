#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>

int main()
{
	system("chcp 1251");
	system("cls");
	unsigned timer = 0;
	std::cout << "Enter timer (seconds): ";
	std::cin >> timer;
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);     
	rawtime += timer;
	timeinfo = localtime(&rawtime);
	char s1[40];
	strftime(s1, 80, "%H:%M:%S ", timeinfo);
	while (timer > 0)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		timer--;	
		std::cout << "Комп'ютер вимкнеться через " << timer << " секунд. О " << s1 << std::endl;
	}
	system("shutdown -s");
	return 0;
}