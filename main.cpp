
#include <iostream>
#include <signal.h>
#include "my_mysql.h"



int main()
{
	MySQL m;
	MYSQL *con;
	MYSQL_RES *result;

	m.server = "localhost";
	m.user = "root";
	m.password = "amitg14";

	std::cout << "Try to connect....";
	con = m.connect();
	std::cout << "Connected!\n";
	
	char useDB = 0;
	
	for(;;)
	{
		
		std::string query;

		std::cout << "SQL>";
		std::getline(std::cin, query);


		char execute = 0;
		std::cout << query << "\n";		
		
		if(query.compare("ls") == 0)
		{
			if(useDB == 0)
				query = "SHOW DATABASES;";
			else
				query = "SHOW Tables;";
			execute = 1;
		}
    
		else if(query.find("cd ") != std::string::npos)
		{
			size_t found = query.find("cd ");
			std::string value = query.substr(found+3);
			if (value.compare("..") == 0)
				useDB = 0;
			else
				useDB = 1;
				
			if(useDB == 1)
				query = "use "+ value + ";";
				execute = 1;
			
		}
    
		else if(query.compare("exit") == 0)
		{
			std::cout << "\nBye!\n";
			break;
		}

		if(execute)
		{
			std::cout << "Query: " << query << "\n";
			std::cout << "\nOutput!\n";
			std::cout << "-----------------------------------------------!\n";

			if(result != 0)
			{
				int num_fields = mysql_num_fields(result);
			    	MYSQL_ROW row;
			      
			    	while ((row = mysql_fetch_row(result))) 
			    	{ 
					for(int i = 0; i < num_fields; i++) 
				  	{ 
				      		std::cout << row[i]; 
				  	} 
					std::cout << "\n"; 
			    	}
			}
		}
  
    	}
    	mysql_free_result(result);
    	mysql_close(con);
	return 0;
}
