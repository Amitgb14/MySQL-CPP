
#include "my_mysql.h"

MYSQL *MySQL :: connect_()
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

MySQL :: ~MySQL()
{
	mysql_close(conn);
}

MYSQL_RES *MySQL :: query_(std::string qr)
{
    	mysql_query(conn, qr.c_str());
    	return mysql_store_result(conn);
}

void MySQL :: connect(std::string server_, std::string user_, std::string password_)
{

	server = server_;
	user = user_;
	password = password_;
	conn = connect_();

}

bool MySQL :: execute(std::string query)
{
	MYSQL_RES *result;
        MYSQL_FIELD *field;
	char execute = 0;

	if(query.compare("ls") == 0)
	{
		if(dbflag == 0)
			query = "SHOW DATABASES;";
		else
			query = "SHOW Tables;";
		execute = 1;
	}
   
	else if((query.find("cd ") != std::string::npos) && (dbflag == 0)) 
	{
		size_t found = query.find("cd ");
		std::string value = query.substr(found+3);
		if (value.compare("..") == 0)
			dbflag = 0;
		else
			dbflag = 1;
			
		if(dbflag == 1)
			query = "use "+ value + ";";
			execute = 1;
			
	}
   
	else if((query.find("cat ") != std::string::npos) && (dbflag == 1)) 
	{
		size_t found = query.find("cat ");
		std::string value = query.substr(found+4);
		query = "select *from "+ value + ";";
		execute = 1;
			
	}

	if(!execute)
		return false;

	result = query_(query);
	if(result == 0)
		return true;

	std::cout << ">\n";
	int num_fields = mysql_num_fields(result);
	MYSQL_ROW row;
                                
	std::cout << "+" << std::setfill('-') << std::setw(20)  << "+\n|";
	std::cout << std::setfill(' ');


	while(field = mysql_fetch_field(result))
	{
		std::cout << field->name << std::setw(15) << "|";

	}
	std::cout << std::setfill(' ');
	std::cout << "\n+" << std::setfill('-') << std::setw(20) << "+\n";
	std::cout << std::setfill(' ');

	while ((row = mysql_fetch_row(result))) 
	{ 
		//std::cout << std::setfill(' ') << std::setw(10);
		for(int i = 0; i < num_fields; i++) 
		{
			std::cout << row[i] << std::setw(20); 
		} 
		std::cout << "\n"; 
	}
	//std::cout << "-------------------------------\n";

			

}
