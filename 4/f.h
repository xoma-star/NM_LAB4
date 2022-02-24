#pragma once
#include <math.h>

double f(double x) {
	return pow(x, 4) - 6 * pow(x, 2) + 2 * x + 1;
}

double F(double x, double y) {
	//return sqrt(pow(x, 4) + pow(y, 2)) + x * y + 2;
	return pow(x, 3) + pow(y, 3) - 2 * x * y - x;
}

double dF_x(double x, double y) {
	//return 2 * pow(x, 3) / sqrt(pow(x, 4) + pow(y, 2)) + y;
	return 3 * pow(x, 2) - 2 * y - 1;
}

double dF_y(double x, double y) {
	//return y / sqrt(pow(x, 4) + pow(y, 2)) + x;
	return 3 * pow(y, 2) - 2 * x;
}

double dF_x_x(double x, double y) {
	//return -4 * pow(x, 6) / pow(pow(x, 4) + pow(y, 2), 1.5) +
		//6 * pow(x, 2) / sqrt(pow(x, 4) + pow(y, 2));
	return 6 * x;
}

double dF_x_y(double x, double y) {
	//return -2 * pow(x, 3) * y / pow(pow(x, 4) + pow(y, 2), 1.5) + 1;
	return -2;
}

double dF_y_y(double x, double y) {
	//return -pow(y, 2) / pow(pow(x, 4) + pow(y, 2), 1.5) + 1 / sqrt(pow(x, 4) + pow(y, 2));
	return 6 * y;
}