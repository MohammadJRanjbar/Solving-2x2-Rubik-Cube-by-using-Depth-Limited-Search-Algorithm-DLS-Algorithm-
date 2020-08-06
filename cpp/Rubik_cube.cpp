#include"Rubik_cube.h"
#include "Matrix.h"

Rubik_cube::Rubik_cube(std::vector<size_t>colors)
{
	this->colors = colors;
	vector2Matrix(colors);
}
/*<---------------------------------------------------------------------------------------------------------------------------------->*/
Rubik_cube::Rubik_cube()
{
	//make a solved rubik cube
	for (size_t j = 1; j < 7; j++)
	{
		for (size_t i = 0; i < 4; i++)
		{
			this->colors.push_back(j);
		}
	}
	/*
	for (size_t i = 0; i < 24; i++)
	{
		this->colors.push_back(i);
	}
	*/
	
	vector2Matrix(colors);
}
/*<---------------------------------------------------------------------------------------------------------------------------------->*/
void Rubik_cube::vector2Matrix(std::vector<size_t> colors)
{
	//to make a matrices so working with them is easier
	size_t N_sides = 6;
	size_t N_cells = static_cast<size_t>(colors.size() / N_sides);
	Matrix temp{ N_sides ,N_cells ,0 };
	size_t Temp{};
	for (size_t i = 0; i < N_sides; i++)
	{
		for (size_t j = 0; j < N_cells; j++)
		{
			temp[i][j] = colors[Temp];
			Temp++;
		}
	}
	this->Sides = temp;
	Temp = 0;
	size_t N_ele = static_cast<size_t>(sqrt(N_cells));
	Matrix temp2{ N_ele,N_ele,0 };
	for (size_t i = 0; i < N_sides; i++)
	{
		for (size_t j = 0; j < N_ele; j++)
		{
			for (size_t k = 0; k < N_ele; k++)
			{
				temp2[j][k] = colors[Temp];
				Temp++;
			}
		}
		this->Rubik.push_back(temp2);
	}
}
/*<---------------------------------------------------------------------------------------------------------------------------------->*/
void Rubik_cube::Rotate(size_t i, bool rotate_direction)
{
	//clockwise is 0 and anticlockwise is 1
	if (i == 1)
	{
		Swap(colors[3], colors[2], colors[0], colors[1], rotate_direction);
		Swap(colors[12], colors[8], colors[4], colors[23], rotate_direction);
		Swap(colors[9], colors[5], colors[22], colors[13], rotate_direction);
		vector2Matrix(colors);
	}
	if (i == 2)
	{
		Swap(colors[5], colors[7], colors[6], colors[4], rotate_direction);
		Swap(colors[2], colors[10], colors[18], colors[22], rotate_direction);
		Swap(colors[8], colors[16], colors[20], colors[0], rotate_direction);
		vector2Matrix(colors);
	}
	if (i == 3)
	{
		Swap(colors[8], colors[9], colors[11], colors[10], rotate_direction);
		Swap(colors[5], colors[3], colors[14], colors[16], rotate_direction);
		Swap(colors[2], colors[12], colors[17], colors[7], rotate_direction);
		vector2Matrix(colors);
	}
	if (i == 4)
	{
		Swap(colors[14], colors[12], colors[13], colors[15], rotate_direction);
		Swap(colors[17], colors[9], colors[1], colors[21], rotate_direction);
		Swap(colors[11], colors[3], colors[23], colors[19], rotate_direction);
		vector2Matrix(colors);
	}
	if (i == 5)
	{
		Swap(colors[16], colors[17], colors[19], colors[18], rotate_direction);
		Swap(colors[7], colors[11], colors[15], colors[20], rotate_direction);
		Swap(colors[10], colors[14], colors[21], colors[6], rotate_direction);
		vector2Matrix(colors);
	}
	if (i == 6)
	{
		Swap(colors[20], colors[21], colors[23], colors[22], rotate_direction);
		Swap(colors[15], colors[1], colors[4], colors[18], rotate_direction);
		Swap(colors[19], colors[13], colors[0], colors[6], rotate_direction);
		vector2Matrix(colors);
	}

}
/*<---------------------------------------------------------------------------------------------------------------------------------->*/
void Rubik_cube::Swap(size_t &i1, size_t &i2, size_t &i4, size_t &i3, bool rotate_direction)
{
	size_t temp{};
	//clockwise is 0 and anticlockwise is 1
	if (rotate_direction == 0)
	{
		temp = i3;
		i3 = i4;
		i4 = i2;
		i2 = i1;
		i1 = temp;


	}
	else if (rotate_direction== 1)
	{
		temp = i1;
		i1 = i2;
		i2 = i4;
		i4 = i3;
		i3 = temp;

	}

}
/*<---------------------------------------------------------------------------------------------------------------------------------->*/
bool Rubik_cube::Goal_test()
{
	//check the rubik vector with another vector that is for a solved rubik and return true if our rubik is sloved
	std::vector<size_t>temp;
	for (size_t j = 0; j < 6; j++)
	{
		temp.push_back(Sides[j][0]);
		for (size_t i = 0; i < 4; i++)
		{
			if(temp[j]!=Sides[j][i])
				return false;
		}
	}
	return true;
		

}
/*<---------------------------------------------------------------------------------------------------------------------------------->*/
void Rubik_cube::show()
{
	//colors vector is for make the output colors 
	//the elements of vector are            white ,  green     , red      ,   blue     ,  yellow  ,    purple
	std::vector<const char*>Colors_vector={"\033[0m","\033[32m","\033[31m","\033[36m" ,"\033[33m","\033[35m" };
	std::cout << "#      " << "your Rubik's colors are" << std::endl;
	std::string line1{ "+-------+" };
	std::string line2{ "+------+-------+------+" };
	//top square
	std::cout << std::setfill(' ') << std::setw(24) << line1 << std::endl;
	std::cout << std::setfill(' ') << std::setw(16) << "|";
	std::cout << " "  <<Colors_vector[Sides[0][0]-1]<<Sides[0][0]<< "\033[0m"<<"  ";
	std::cout << " " << Colors_vector[Sides[0][1]-1]<<Sides[0][1]<< "\033[0m";
	std::cout << " " << "|" << std::endl;
	std::cout << std::setfill(' ') << std::setw(16) << "|";
	std::cout << " " << Colors_vector[Sides[0][2]-1]<<Sides[0][2]<< "\033[0m"<<"  ";
	std::cout << " " << Colors_vector[Sides[0][3]-1]<<Sides[0][3]<< "\033[0m";
	std::cout << " " << "|" << std::endl;
	std::cout << std::setfill(' ') << std::setw(31) << line2 << std::endl;
	//middel side squares
	std::cout << std::setfill(' ') << std::setw(9) << "|";
	std::cout << " " << Colors_vector[Sides[1][0]-1]<<Sides[1][0]<< "\033[0m";
	std::cout << "  " << Colors_vector[Sides[1][1]-1]<<Sides[1][1]<< "\033[0m";
	std::cout << " " << "|";
	std::cout << " " << std::right << Colors_vector[Sides[2][0]-1]<<Sides[2][0]<< "\033[0m"<<"  ";
	std::cout << " " << std::right << Colors_vector[Sides[2][1]-1]<<Sides[2][1]<< "\033[0m";
	std::cout << " " << std::right << "|";
	std::cout << " " << std::right << Colors_vector[Sides[3][0]-1]<<Sides[3][0]<< "\033[0m";
	std::cout << "  " << std::right << Colors_vector[Sides[3][1]-1]<<Sides[3][1]<< "\033[0m";
	std::cout << " " << std::right << "|" << std::endl;
	//the second line
	std::cout << std::setfill(' ') << std::setw(9) << "|";
	std::cout << " " << std::right << Colors_vector[Sides[1][2]-1]<<Sides[1][2]<< "\033[0m";
	std::cout << "  " << std::right << Colors_vector[Sides[1][3]-1]<<Sides[1][3]<< "\033[0m";
	std::cout << " " << std::right << "|" ;
	std::cout << " " << std::right << Colors_vector[Sides[2][2]-1]<<Sides[2][2]<< "\033[0m"<<"  ";
	std::cout << " " << std::right << Colors_vector[Sides[2][3]-1]<<Sides[2][3]<< "\033[0m";
	std::cout << " " << std::right << "|";
	std::cout << " " << std::right << Colors_vector[Sides[3][2]-1]<<Sides[3][2]<< "\033[0m";
	std::cout << "  " << std::right << Colors_vector[Sides[3][3]-1]<<Sides[3][3]<< "\033[0m";
	std::cout << " " << std::right << "|" << std::endl;
	std::cout << std::setfill(' ') << std::setw(31) << line2 << std::endl;
	//first bottom square
	std::cout << std::setfill(' ') << std::setw(16) << "|";
	std::cout << " "  <<Colors_vector[Sides[4][0]-1]<<Sides[4][0]<< "\033[0m"<<"  ";
	std::cout << " " << Colors_vector[Sides[4][1]-1]<<Sides[4][1]<< "\033[0m";
	std::cout << " " << "|" << std::endl;
	std::cout << std::setfill(' ') << std::setw(16) << "|";
	std::cout << " "  <<Colors_vector[Sides[4][2]-1]<<Sides[4][2]<< "\033[0m"<<"  ";
	std::cout << " " << Colors_vector[Sides[4][3]-1]<<Sides[4][3]<< "\033[0m";
	std::cout << " " << "|" << std::endl;
	//second bottom square
	std::cout << std::setfill(' ') << std::setw(24) << line1 << std::endl;
	std::cout << std::setfill(' ') << std::setw(16) << "|";
	std::cout << " "  <<Colors_vector[Sides[5][0]-1]<<Sides[5][0]<< "\033[0m"<<"  ";
	std::cout << " " << Colors_vector[Sides[5][1]-1]<<Sides[5][1]<< "\033[0m";
	std::cout << " " << "|" << std::endl;
	std::cout << std::setfill(' ') << std::setw(16) << "|";
	std::cout << " "  <<Colors_vector[Sides[5][2]-1]<<Sides[5][2]<< "\033[0m"<<"  ";
	std::cout << " " << Colors_vector[Sides[5][3]-1]<<Sides[5][3]<< "\033[0m";
	std::cout << " " << "|" << std::endl;
	std::cout << std::setfill(' ') << std::setw(24) << line1 << std::endl;
}