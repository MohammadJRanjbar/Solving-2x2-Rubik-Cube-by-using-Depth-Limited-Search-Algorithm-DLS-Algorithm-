#include <iostream>
#include "Matrix.h"
#include "Rubik_cube.h"
#include <stdlib.h>
#include"Graph.h"
#include "ApProject.h"

int main()
{
	std::vector<size_t>c = { 1,5,1,5,6,6,2,4,2,4,3,3,3,3,2,4,1,1,5,5,6,6,4,2 };
	std::vector<size_t>e = { 5,6,3,4,2,1,5,4,2,6,3,6,1,5,1,4,1,2,3,5,4,6,3,2 };
	Rubik_cube rc{ c };
	Graph g(rc, 1,4 );
	g.DLS();
	return 0;

}