#pragma once
#include <functional>
#include "Common.h"
#include "f.h"

double Secant(double a, double b) {
	if (a > b) {
		std::swap(a, b);
	}
	double x_prev = a;
	double x = (a + b) / 2;
	double x_next = x - (x - x_prev) * f(x) / (f(x) - f(x_prev));
	while (abs(x_next - x) > delta) {
		x_prev = x;
		x = x_next;
		x_next = x - (x - x_prev) * f(x) / (f(x) - f(x_prev));
	}
	return x_next;
}