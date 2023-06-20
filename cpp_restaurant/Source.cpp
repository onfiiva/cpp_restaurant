#include<iostream>
#include<stdio.h>
#include <vector>
#include<string>
#include <fstream>
#include <sstream>
#include <chrono>

#include "SetDefaultValues.cpp"
#include "Authorization.cpp"

int main() {

	// ��������� ������� ������
	std::setlocale(LC_ALL, "Russian");

	//������� ��������� ������ ��� ���������� ��������� ��������
	SetDefaultValues setDefaultValues;

	//�������� ������ ��� ���������� ��������� ��������
	setDefaultValues.setDefaultUsersValues();
	setDefaultValues.setDefaultIngridientsValues();
	setDefaultValues.setDefaultDishesValues();
	setDefaultValues.setDefaultAccountingParameters();

	Authorization authorization;

	authorization.Auth();

	return 0;
}