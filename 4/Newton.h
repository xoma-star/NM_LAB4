#pragma once
#include <vector>
#include "Common.h"
#include "f.h"
#include "Gauss.h"

std::vector<double> Newton() {
	double x_1, y_1, x_2, y_2;
	x_1 = y_1 = segment[0];
	x_2 = y_2 = segment[1];
	if (x_1 > x_2) {std::swap(x_1, x_2);}
	if (y_1 > y_2) {std::swap(y_1, y_2);}
	double x = (x_1 + x_2) / 2;
	double y = (y_1 + y_2) / 2;
	std::vector<double> answer;
	std::vector<std::vector<double>> matrix(2);
	matrix[0].resize(3);
	matrix[1].resize(3);
	matrix[0][0] = dF_x_x(x, y);
	matrix[0][1] = dF_x_y(x, y);
	matrix[1][0] = dF_x_y(x, y);
	matrix[1][1] = dF_y_y(x, y);
	matrix[0][2] = -dF_x(x, y);
	matrix[1][2] = -dF_y(x, y);
	answer = Gauss(matrix);
	double x_next = x + answer[0];
	double y_next = y + answer[1];
	while (std::max(abs(answer[0]), abs(answer[1])) > delta2) {
		x = x_next;
		y = y_next;
		matrix[0][0] = dF_x_x(x, y);
		matrix[0][1] = dF_x_y(x, y);
		matrix[1][0] = dF_x_y(x, y);
		matrix[1][1] = dF_y_y(x, y);
		matrix[0][2] = -dF_x(x, y);
		matrix[1][2] = -dF_y(x, y);
		answer = Gauss(matrix);
		x_next = x + answer[0];
		y_next = y + answer[1];
	}
	return { x_next, y_next };
}