#include <iostream>
#include <mariadb/mysql.h>

int main()
{
	std::cout << "MySQL client version: " << mysql_get_client_info() << "\n";
	return 0;
}

