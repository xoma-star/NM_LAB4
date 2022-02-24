#pragma once
#include <functional>
#include "Common.h"
#include "f.h"

double Chord(double a, double b) {
	if (a > b) {
		std::swap(a, b);
	}
	double x = a;
	double x_next = x - f(x) / (f(x) - f(b)) * (x - b);
	while (abs(x_next - x) > delta) {
		x = x_next;
		x_next = x - f(x) / (f(x) - f(b)) * (x - b);
	}
	return x_next;
}