#include <stdlib.h>
#include <iostream>
#include "my_mariadb.h"

int main()
{
	MySQL *m;
	MYSQL *con;
	MYSQL_RES *result;
	std::cout << "Try to connect....";
	con = m->connect();
	std::cout << "Connected!\n";

    std::string query = "SHOW DATABASES;";
    
    result = m->query(con, query);


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
  
    
    mysql_free_result(result);
    mysql_close(con);
	return 0;
}
