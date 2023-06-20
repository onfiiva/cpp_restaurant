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

	// Установка русской локали
	std::setlocale(LC_ALL, "Russian");

	//Создаем экземпляр класса для заполнения дефолтных значений
	SetDefaultValues setDefaultValues;

	//Вызываем методы для заполнения дефолтных значений
	setDefaultValues.setDefaultUsersValues();
	setDefaultValues.setDefaultIngridientsValues();
	setDefaultValues.setDefaultDishesValues();
	setDefaultValues.setDefaultAccountingParameters();

	Authorization authorization;

	authorization.Auth();

	return 0;
}