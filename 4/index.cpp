#pragma once
#include <iostream>
#include <iomanip>
#include "FindRootByMethod.h"
#include "Newton.h"

int main() {
	//Plot();
	//������� 1
	setlocale(LC_ALL, "Ru");
	std::cout << std::setprecision(7);
	std::cout << "���������: \n";
	FindRootByMethod(0);
	std::cout << "�����: \n";
	FindRootByMethod(1);
	std::cout << "�����. ��������: \n";
	FindRootByMethod(2);
	std::cout << "������: \n";
	FindRootByMethod(3);
	std::cout << "�������: \n";
	FindRootByMethod(4);

	//������� 2
	std::vector<double> min = SimpleIterationsForSystem();
	//std::cout << "Min x = " << min[0] << ", y = " << min[1] << ", value = " << F(min[0], min[1]) << std::endl;

	//������� 3
	min = Newton();
	std::cout << "Min x = " << min[0] << ", y = " << min[1] << ", value = " << F(min[0], min[1]) << std::endl;
	return 0;
}