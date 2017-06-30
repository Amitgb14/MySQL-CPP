
#include <iostream>
#include <string.h>
#include <mysql.h>

struct MySQL
{
	std::string server = "";
	std::string user = "";
	std::string password = "";

	MYSQL *connect();
	MYSQL_RES *query(MYSQL *, std::string);
};
