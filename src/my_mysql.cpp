
#include "my_mysql.h"

MYSQL *MySQL :: connect()
{
	MYSQL *con = mysql_init(NULL);
	if(! mysql_real_connect(con, server.c_str(), user.c_str(), password.c_str(), 
				          NULL, 0, NULL, 0))
	{
		std::cout << mysql_error(con) << "\n";
		exit(1);
	}
	return con;
}

MYSQL_RES *MySQL :: query(MYSQL *con, std::string qr)
{
    mysql_query(con, qr.c_str());
    return mysql_store_result(con);
}
