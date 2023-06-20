#include<iostream>
#include<stdio.h>
#include <vector>
#include<string>
#include <fstream>
#include <sstream>
#include <chrono>

#include "FileLogic.h"
#include "Order.h"
#include "Accounting.h"
#include "User.h"
#include "Dish.h"
#include "Ingredient.h"
#include "FileActions.h"

class SetDefaultValues {
public:
	void setDefaultUsersValues() {

		//������ ��� �������� �������������
		std::vector<User> userList;

		//���������� ��� �������������� � ���������� ������
		std::string fileName;

		//���������� ������� ������������� � ������
		userList.push_back(User(1, "������", "����", "��������", "admin", "admin123", "admin"));							//��������� �������������
		userList.push_back(User(2, "������", "����", "��������", "storage", "storage123", "storage"));						//���������
		userList.push_back(User(3, "�������", "������", "���������", "supplier", "supplier123", "supplier"));				//���������
		userList.push_back(User(4, "��������", "������", "����������", "accountant", "accountant123", "accountant"));		//���������
		userList.push_back(User(5, "�������", "�����", "���������", "chef", "chef123", "chef"));							//�����
		userList.push_back(User(6, "��������", "�������", "����������", "officiant", "officiant123", "officiant"));			//��������

		fileName = "users.txt";

		FileLogic fileLogic;

		if (!fileLogic.isFileExists(fileName)) {		//���� ���� �� ����������, ��

			//������� ����
			std::ofstream file(fileName);

			//������� � ���� ��������
			for (const auto& data : userList) {
				file << data.id << "-" << data.surname << "-" << data.name << "-" << data.patronymic << "-" << data.login << "-" << data.password << "-" << data.role << "\n";
			}

			//��������� ����
			file.close();
		}
	}

	void setDefaultIngridientsValues() {

		//������ ��� �������� ����
		std::vector<Ingredient> ingridientsList;

		//���������� ��� �������������� � ���������� ������
		std::string fileName;

		//���������� ������� ������������ � ������
		ingridientsList.push_back(Ingredient(1, "���������", "����", 100, 10));
		ingridientsList.push_back(Ingredient(2, "�����", "������", 100, 10));
		ingridientsList.push_back(Ingredient(3, "�������", "����", 100, 20));
		ingridientsList.push_back(Ingredient(4, "������", "�����", 100, 20));
		ingridientsList.push_back(Ingredient(5, "����", "����", 100, 50));

		fileName = "ingredients.txt";

		FileLogic fileLogic;

		if (!fileLogic.isFileExists(fileName)) {		//���� ���� �� ����������, ��

			//������� ����
			std::ofstream file(fileName);

			//������� � ���� ��������
			for (const auto& data : ingridientsList) {
				file << data.id << "-" << data.name << "-" << data.type << "-" << data.count << "-" << data.cost << " \n";
			}

			//��������� ����
			file.close();
		}
	}

	void setDefaultDishesValues() {

		//������ ��� �������� ����
		std::vector<Dish> dishesList;

		//���������� ��� �������������� � ���������� ������
		std::string fileName;

		//���������� ������� ���� � ������

		GetValues getValues;
		std::vector<Ingredient> ingredients = getValues.getIngridients();

		std::vector<Ingredient> dishIngridients;

		if (ingredients.size() >= 5) {
			//��������� ������ ���� �������� ����������
			dishIngridients = { ingredients[0], ingredients[2], ingredients[3] };
			dishesList.push_back(Dish(1, "�����", 150, dishIngridients, "��� �����", std::chrono::minutes(20), 70));
			dishIngridients.clear();

			dishIngridients = { ingredients[0], ingredients[1], ingredients[2], ingredients[3] };
			dishesList.push_back(Dish(2, "������", 250, dishIngridients, "���� �� ���� �������", std::chrono::minutes(20), 200));
			dishIngridients.clear();

			dishIngridients = { ingredients[4], ingredients[1] };
			dishesList.push_back(Dish(3, "���� �����", 150, dishIngridients, "����� ������ � �����", std::chrono::minutes(30), 100));
			dishIngridients.clear();

			dishIngridients = { ingredients[4], ingredients[1] };
			dishesList.push_back(Dish(4, "������", 500, dishIngridients, "��� � ����", std::chrono::minutes(30), 300));
			dishIngridients.clear();

			dishIngridients = { ingredients[0], ingredients[2], ingredients[4], ingredients[1] };
			dishesList.push_back(Dish(5, "�����", 100, dishIngridients, "���� ����������", std::chrono::minutes(30), 30));
			dishIngridients.clear();

			fileName = "dishes.txt";

			FileLogic fileLogic;

			if (!fileLogic.isFileExists(fileName)) {		//���� ���� �� ����������, ��

				//������� ����
				std::ofstream file(fileName);

				//������� � ���� ��������
				for (const auto& data : dishesList) {
					file << data.id << "-" << data.name << "-" << data.weight << "-";
					for (const auto& ingridient : data.ingridients) {
						file << ingridient.id;
					}
					long long minutes = data.preptime.count();
					std::string timeString = std::to_string(minutes);
					file << "-" << data.description << "-" << minutes << "-" << data.cost << " \n";
				}

				//��������� ����
				file.close();
			}
		}
		else {
			std::cout << "������������ ������ � ����� ingredients.txt." << std::endl;
		}

	}

	void setDefaultAccountingParameters() {

		//������, �������� ������
		std::vector<Order> orderList;

		//����������, �������� ������� ������ �����
		Accounting accounting = { 10000, orderList, 0, 0 };

		//���������� ��� �������������� � ���������� ������
		std::string fileName;

		fileName = "accounting.txt";

		FileLogic fileLogic;

		if (!fileLogic.isFileExists(fileName)) {		//���� ���� �� ����������, ��

			//������� ����
			std::ofstream file(fileName);

			file << accounting.balance << "-" << "1" << "-" << accounting.globalSum << "-" << accounting.totalPurchase;

			//��������� ����
			file.close();
		}
	}
};