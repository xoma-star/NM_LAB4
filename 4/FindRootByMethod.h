#pragma once
#include "Dichotomy.h"
#include "Chord.h"
#include "SimpleIterations.h"
#include "Secant.h"

void repeat(int n, const std::function<void(const int&)> method) {
	for (int i = 0; i < n; i++) {
		method(i);
	}
	std::cout << "\n";
}

void FindRootByMethod(int method) {
	switch (method){
	case 0:
		repeat(4, [](int a) { std::cout << Dichotomy(segments[a][0], segments[a][1]) << " "; });
		break;
	case 1:
		repeat(4, [](int a) { std::cout << Chord(segments[a][0], segments[a][1]) << " "; });
		break;
	case 2:
	case 3:
		repeat(4, [](int a) { std::cout << SimpleIterations(segments[a][0], segments[a][1]) << " "; });
		break;
	case 4:
		repeat(4, [](int a) { std::cout << Secant(segments[a][0], segments[a][1]) << " "; });
		break;
	default:
		break;
	}
}