#include <iostream>
#include<fstream>
#include <string>
#include <vector>
#include <time.h>       /* time */

int main ()
{
	int n;
	std::string fileName, imgName, result;
	double correct = 0, incorrect = 0, accuracy = 0;
	int pneu = 0, norm = 0;
	std::ifstream fin;
	std::ofstream fout;
	std::vector<std::string> v;

	std::cout << "Nhap ten file txt: ";
	std::cin >> fileName;
	fin.open(fileName);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> imgName >> result;
			if (imgName[0] == 'N' || imgName[0] == 'I')
			{
				if (result[0] == 'N')
					correct ++;
				else 
				{
					incorrect ++;
					v.push_back(imgName);
					v.push_back(result);
					++pneu;
				}
					
				
			}
			else if (result[0] == 'P')
				correct ++;
			else 
				{
					incorrect ++;
					v.push_back(imgName);
					v.push_back(result);
					++norm;
				}
		}	
		fin.close();
	}
	else
	{
		std::cout << "file co van de roi dai ca";
		std::cin.ignore(1000, '\n');
		std::cin.get();
		return 0;
	}

	accuracy = correct / (correct + incorrect);
	std::cout << std::endl << "accuracy: " << accuracy;
	fout.open("result.txt");
	fout << "accuracy: " << accuracy << std::endl;
	fout << "norn wrong: " << pneu << std::endl
		<< "pneu wrong: " << norm << std::endl;
	fout << std::endl;

	n = v.size();
	for (int i = 0; i < n; ++i)
	{
		fout << v[i] << std::endl;
	} 

	fout.close();
  	return 0;
}