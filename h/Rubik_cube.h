#ifndef Rubik_cube_H
#define Rubik_cube_H
#include <stdio.h>
#include <cmath>
#include <array>
#include <memory>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>      
#include <random>
#include <optional>
#include"Matrix.h"
#include <stdlib.h>
class Rubik_cube
{
public:
	Rubik_cube(std::vector<size_t>);
	Rubik_cube();
	void show();
	void Swap(size_t &i1, size_t &i2, size_t &i3, size_t &i4, bool);
	void Rotate(size_t, bool);
	void vector2Matrix(std::vector<size_t>);
	bool Goal_test();
	Rubik_cube(const Rubik_cube &rc) = default;
private:
	Matrix Sides{};
	std::vector<Matrix>Rubik;
	std::vector<size_t> colors;
};
#endif