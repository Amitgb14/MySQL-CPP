#include <iostream>
#include <mysql.h>

struct Car
{
	std::string name = "Amit";
};

int main()
{
	Car c;
	std::cout << c.name << "\n";
	std::cout << "MySQL client version: " << mysql_get_client_info() << "\n";
	return 0;
}

