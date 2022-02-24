#pragma once
#include <functional>
#include "Common.h"
#include "f.h"

double diff(double x) {
	return 4 * pow(x, 3) - 12 * x + 2;
}

double phi(double x) {
	return x + f(x) * x * x * x;
}

double ksi(double x) {
	return x - f(x) / diff(x);
}

//const std::function<double(const double&)> g
double SimpleIterations(double a, double b) {
	if (a > b) {
		std::swap(a, b);
	}
	std::function<double(const double&)> g = ksi;
	double x = (a + b) / 2;
	double x_next = g(x);
	while (abs(x_next - x) > delta) {
		x = x_next;
		x_next = g(x);
	}
	return x_next;
}

std::vector<double> SimpleIterationsForSystem() {
	const std::function<double(const double&, const double&)> f_1 = [](double x, double y) { return x - F(x, y) / dF_x(x, y); };
	const std::function<double(const double&, const double&)> f_2 = [](double x, double y) { return y - F(x, y) / dF_y(x, y); };
	double x_1, y_1, x_2, y_2;
	x_1 = y_1 = segment[0];
	x_2 = y_2 = segment[1];
	if (x_1 > x_2) std::swap(x_1, x_2);
	if (y_1 > y_2) std::swap(y_1, y_2);
	double x = (x_1 + x_2) / 2.;
	double y = (y_1 + y_2) / 2.;
	double x_next = f_1(x, y);
	double y_next = f_2(x, y);
	while (std::max(abs(x_next - x), abs(y_next - y)) > delta2) {
		x = x_next;
		y = y_next;
		x_next = f_1(x, y);
		y_next = f_2(x, y);
	}
	return { x_next, y_next };
}