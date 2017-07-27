
#include <iostream>
#include <string.h>
#include <iomanip>
#include <mysql.h>

struct MySQL
{
	std::string server = "";
	std::string user = "";
	std::string password = "";

	char dbflag = 0;

	~MySQL();
	MYSQL *conn;

	MYSQL *connect_();
	MYSQL_RES *query_(std::string);


        void connect(std::string, std::string, std::string);
        bool execute(std::string);
        
};
