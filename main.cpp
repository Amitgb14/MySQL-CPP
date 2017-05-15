
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
	
	
	for(;;)
	{
		
		std::string query;

		std::cout << "SQL>";
		std::cin >> query;


		char execute = 0;		
		
		if (query.compare("ls") == 0)
		{
			query = "SHOW DATABASES;";
			execute = 1;
		}
    
		else if (query.compare("exit") == 0)
		{
			std::cout << "\nBye!\n";
			break;
		}

		if(execute)
		{
		   	result = m.query(con, query);
			std::cout << "\nOutput!\n";
			std::cout << "-----------------------------------------------!\n";

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
    	mysql_free_result(result);
    	mysql_close(con);
	return 0;
}
