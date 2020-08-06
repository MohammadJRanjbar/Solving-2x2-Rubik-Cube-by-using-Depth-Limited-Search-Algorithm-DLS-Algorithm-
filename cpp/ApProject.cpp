#include "ApProject.h"
std::vector<size_t> Color_Initializr()
{
	//get inputs and put it in a vector
	std::vector<size_t> colors;
	for (size_t i = 1; i < 7; i++)
	{
		std::cout << "Surface" << i << " : ";
			size_t x[4];
			char c[3];
			std::cin >>x[0]>>c[0] >> x[1] >> c[1] >> x[2] >> c[2] >> x[3] ;
			colors.push_back(x[0]);
			colors.push_back(x[1]);
			colors.push_back(x[2]);
			colors.push_back(x[3]);

	}
	//if user gave wrong inputs 
	if (!check(colors))
	{
		std::vector<size_t>C;
		//we give a message and reutrn a solved rubik inputs
		for (size_t j = 1; j < 7; j++)
		{
			for (size_t i = 0; i < 4; i++)
			{
				C.push_back(j);
			}
		}
		std::cout << "a deafult rubik colors was intilized" << std::endl;
		return C;
	}
	else
	{
		std::cout << "Your rubik seems valid" << std::endl;
		return colors;
	}
		
}
bool check(std::vector<size_t>colors)
{
	std::vector <size_t>temp = { 0,0,0,0,0,0 };
	for (size_t i = 0; i < colors.size(); i++)
	{
		if (colors[i] > 6 || colors[i] < 1)
		{
			std::cout << "This Rubik does not exist " << std::endl;
			return false;
		}
		for (size_t j = 1; j < 7; j++)
		{
			if (colors[i] == j)
			{
				temp[j - 1]++;
			}
		}
	}
	for (size_t i = 0; i < temp.size(); i++)
	{
		if (temp[i] != 4)
		{
			std::cout << "This Rubik does not exist " << std::endl;
			return false;
		}
	}
	return true;

}
