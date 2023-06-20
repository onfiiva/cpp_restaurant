#include <iostream>
#include <string>
#include <vector>

#include "FileActions.h"
#include "User.h"
#include "GuestWindow.cpp"
#include "AdminWindow.cpp"
#include "StorageWindow.cpp"
#include "SupplierWindow.cpp"
#include "AccountantWindow.cpp"
#include "ChefWindow.cpp"
#include "OfficiantWindow.cpp"

class Authorization {
public:
	void Auth() {

		int answer;

		std::cout << "����� ���������� � ��������." << "\n"
			<< "������� �������������� ��� ����� ��� �����?" << "\n"
			<< "0 - �����������;" << "\n"
			<< "1 - ����� ��� �����." << std::endl;
		std::cin >> answer;

		std::string login, password;

		GetValues getValues;
		//������ ��� �������������
		std::vector<User> users = getValues.getUsers();

		switch (answer)
		{
		case 0:

			std::cout << "������� �����: ";
			std::cin >> login;
			std::cout << "������� ������: ";
			std::cin >> password;

			for (const auto& user : users) {
				if (user.login == login && user.password == password) {
					//���� ������� ������������ � ����� ������� � �������, �������� ����������� �� ���� � ������������ �� ������ ����
					if (user.role == "admin") {
						AdminWindow admin;
						admin.Admin();
					}
					else if (user.role == "storage") {
						StorageWindow storage;
						storage.Storage();
					}
					else if (user.role == "supplier") {
						SupplierWindow supplier;
						supplier.Supplier();
					}
					else if (user.role == "accountant") {
						AccountantWindow accountant;
						accountant.Accountant();
					}
					else if (user.role == "chef") {
						ChefWindow chef;
						chef.Chef();
					}
					else if (user.role == "officiant") {
						OfficiantWindow officiant;
						officiant.Officiant();
					}
				}
			}
			break;
		case 1:
			//������� � ���� �����
			GuestWindow guest;
			guest.Guest();
			break;
		default:
			break;
		}
	}
};