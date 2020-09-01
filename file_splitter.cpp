#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <thread>
#include <chrono>

int main()
{
	while (true)
	{
		std::string str;
		std::string name;
		std::string filename;
        int count = 0;
		std::cout << "Enter file name: ";
		std::getline(std::cin, filename);
		filename += ".csv";
        std::cout << "Enter count of lines in new file: ";
        std::cin >> count;
		std::ifstream input(filename);
		int FILE_COUNT = 1;
		char intToArr[3];
		if (input.is_open())
		{
			while (!input.eof())
			{
				std::ofstream newfile;
				name = "File";
				name += itoa(FILE_COUNT, intToArr, 10);
				name += ".csv";
				newfile.open(name);
				auto start = std::chrono::steady_clock::now();
				for (int i = 1; i <= count;i++)
				{
					std::getline(input, str);
					newfile << str << std::endl;
					if (i % 12511 == 0 || i == count || input.eof() == true)
					{
						auto end = std::chrono::steady_clock::now();
						auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
						double prc = ((double)i / count) * 100;
						std::cout << std::fixed << std::setprecision(2) << "\r[" << prc << "%] Lines: " << i << " Time: " << ((double)time.count() / 1000) << "s";
						if (input.eof())
							break;
					}

				}
				std::cout << "\tRecorded to 'File" << FILE_COUNT << ".csv" << std::endl;
				newfile.close();
				FILE_COUNT++;
			}
		}
		else
			std::cout << "FILE: '" << filename << "' not found!" << std::endl;
	}
	return 0;
}



