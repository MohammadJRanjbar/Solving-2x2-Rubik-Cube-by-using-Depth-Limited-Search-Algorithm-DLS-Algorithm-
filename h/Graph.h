#ifndef Graph_H
#define Graph_H
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
#include "Rubik_cube.h"
#include <stdlib.h>
class Graph
{
public:
	Graph(Rubik_cube, size_t, size_t);
	bool DLS();
	void navigaiton();
	void IDS(size_t);

private:
	Rubik_cube rc;
	size_t limit;
	size_t temp{ 0 };
	size_t F{};
	size_t NumbeofNodes{};
    //stack
	std::vector<Rubik_cube>rv;
    //stack for deapths
	std::vector<size_t>deapth;
	std::vector < std::vector <size_t> > outP;
	std::vector<size_t>outPTemp;
};
#endif