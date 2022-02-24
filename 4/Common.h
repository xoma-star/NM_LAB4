#pragma once
#include <math.h>
#include <vector>

constexpr auto delta = 10e-7;
constexpr auto delta2 = 10e-5;
const std::vector<std::vector<float>> segments = {
	{-2.6, -2.5},
	{-0.3, -0.2},
	{0.6, 0.7},
	{2.2, 2.3}
};
//const std::vector<double> segment = { -1., 1. };
const std::vector<double> segment = { 0., 2. };