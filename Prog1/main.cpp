#include <iostream>
#include "Prog1.h"

using namespace Prog1;

int main() {
	double **arr = nullptr;
	double *res = nullptr;
	int m, n;
	
	arr = matrix_input(m, n);
	if (!arr) {
	   std::cout << "Incorrect data detected!" << std::endl;
	   return 1;
	}
	matrix_output("Sourced matrix:", arr, m, n);
	
	res = vector_result(arr, m, n);
	if (!res) {
	   std::cout << "Error in allocating memory!" << std::endl;
	   return 1;
	}
	vector_output("Final vector:", res, m);
	
	matrix_erase(arr, m);
	delete[] res;
	return 0;
}