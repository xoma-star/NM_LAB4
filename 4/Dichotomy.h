#pragma once
#include <functional>
#include "Common.h"
#include "f.h"

double Dichotomy(double a, double b) {
	if (a > b) std::swap(a, b);

	double err = 1;
	double left = a, right = b;
	double middle = (a + b) / 2;
	while (err > 2 * delta) {
		if (f(left) * f(middle) <= 0) {
			right = middle;
		}
		else {
			left = middle;
		}
		middle = (left + right) / 2;
		err = abs(right - left);
	}
	return middle;
}