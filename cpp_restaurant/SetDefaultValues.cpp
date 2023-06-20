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

		//Вектор для значений пользователей
		std::vector<User> userList;

		//Переменная для взаимодействия с названиями файлов
		std::string fileName;

		//Добавление базовых пользователей в список
		userList.push_back(User(1, "Иванов", "Иван", "Иванович", "admin", "admin123", "admin"));							//Системный администратор
		userList.push_back(User(2, "Петров", "Петр", "Петрович", "storage", "storage123", "storage"));						//Складской
		userList.push_back(User(3, "Андреев", "Андрей", "Андреевич", "supplier", "supplier123", "supplier"));				//Поставщик
		userList.push_back(User(4, "Максимов", "Максим", "Максимович", "accountant", "accountant123", "accountant"));		//Бухгалтер
		userList.push_back(User(5, "Романов", "Роман", "Романович", "chef", "chef123", "chef"));							//Повар
		userList.push_back(User(6, "Алексеев", "Алексей", "Алексеевич", "officiant", "officiant123", "officiant"));			//Официант

		fileName = "users.txt";

		FileLogic fileLogic;

		if (!fileLogic.isFileExists(fileName)) {		//Если файл не существует, то

			//создаем файл
			std::ofstream file(fileName);

			//заносим в него значения
			for (const auto& data : userList) {
				file << data.id << "-" << data.surname << "-" << data.name << "-" << data.patronymic << "-" << data.login << "-" << data.password << "-" << data.role << "\n";
			}

			//закрываем файл
			file.close();
		}
	}

	void setDefaultIngridientsValues() {

		//Вектор для значений блюд
		std::vector<Ingredient> ingridientsList;

		//Переменная для взаимодействия с названиями файлов
		std::string fileName;

		//Добавление базовых ингридиентов в список
		ingridientsList.push_back(Ingredient(1, "Пшеничная", "Мука", 100, 10));
		ingridientsList.push_back(Ingredient(2, "Укроп", "Зелень", 100, 10));
		ingridientsList.push_back(Ingredient(3, "Куриное", "Яйцо", 100, 20));
		ingridientsList.push_back(Ingredient(4, "Курица", "Птица", 100, 20));
		ingridientsList.push_back(Ingredient(5, "Фарш", "Мясо", 100, 50));

		fileName = "ingredients.txt";

		FileLogic fileLogic;

		if (!fileLogic.isFileExists(fileName)) {		//Если файл не существует, то

			//создаем файл
			std::ofstream file(fileName);

			//заносим в него значения
			for (const auto& data : ingridientsList) {
				file << data.id << "-" << data.name << "-" << data.type << "-" << data.count << "-" << data.cost << " \n";
			}

			//закрываем файл
			file.close();
		}
	}

	void setDefaultDishesValues() {

		//Вектор для значений блюд
		std::vector<Dish> dishesList;

		//Переменная для взаимодействия с названиями файлов
		std::string fileName;

		//Добавление базовых блюд в список

		GetValues getValues;
		std::vector<Ingredient> ingredients = getValues.getIngridients();

		std::vector<Ingredient> dishIngridients;

		if (ingredients.size() >= 5) {
			//Заполняем вектор блюд базовыми значениями
			dishIngridients = { ingredients[0], ingredients[2], ingredients[3] };
			dishesList.push_back(Dish(1, "Самса", 150, dishIngridients, "Вах какая", std::chrono::minutes(20), 70));
			dishIngridients.clear();

			dishIngridients = { ingredients[0], ingredients[1], ingredients[2], ingredients[3] };
			dishesList.push_back(Dish(2, "Шаурма", 250, dishIngridients, "Ашот ей ноги целовал", std::chrono::minutes(20), 200));
			dishIngridients.clear();

			dishIngridients = { ingredients[4], ingredients[1] };
			dishesList.push_back(Dish(3, "Люля кебаб", 150, dishIngridients, "Такую только в музей", std::chrono::minutes(30), 100));
			dishIngridients.clear();

			dishIngridients = { ingredients[4], ingredients[1] };
			dishesList.push_back(Dish(4, "Шашлык", 500, dishIngridients, "Как у бати", std::chrono::minutes(30), 300));
			dishIngridients.clear();

			dishIngridients = { ingredients[0], ingredients[2], ingredients[4], ingredients[1] };
			dishesList.push_back(Dish(5, "Манты", 100, dishIngridients, "Гоги позавидует", std::chrono::minutes(30), 30));
			dishIngridients.clear();

			fileName = "dishes.txt";

			FileLogic fileLogic;

			if (!fileLogic.isFileExists(fileName)) {		//Если файл не существует, то

				//создаем файл
				std::ofstream file(fileName);

				//заносим в него значения
				for (const auto& data : dishesList) {
					file << data.id << "-" << data.name << "-" << data.weight << "-";
					for (const auto& ingridient : data.ingridients) {
						file << ingridient.id;
					}
					long long minutes = data.preptime.count();
					std::string timeString = std::to_string(minutes);
					file << "-" << data.description << "-" << minutes << "-" << data.cost << " \n";
				}

				//закрываем файл
				file.close();
			}
		}
		else {
			std::cout << "Недостаточно данных в файле ingredients.txt." << std::endl;
		}

	}

	void setDefaultAccountingParameters() {

		//вектор, хранящий заказы
		std::vector<Order> orderList;

		//переменная, хранящая базовые данные учета
		Accounting accounting = { 10000, orderList, 0, 0 };

		//Переменная для взаимодействия с названиями файлов
		std::string fileName;

		fileName = "accounting.txt";

		FileLogic fileLogic;

		if (!fileLogic.isFileExists(fileName)) {		//Если файл не существует, то

			//создаем файл
			std::ofstream file(fileName);

			file << accounting.balance << "-" << "1" << "-" << accounting.globalSum << "-" << accounting.totalPurchase;

			//закрываем файл
			file.close();
		}
	}
};