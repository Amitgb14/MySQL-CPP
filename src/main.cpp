
#include <iostream>
#include <signal.h>
#include "my_mysql.h"

MySQL m;

bool connect()
{
	
	std::string server;
	std::string user;
	std::string password;
	
	std::cout << "Enter server [default = localhost]: ";
        std::getline(std::cin, server);
	if(server.empty())
		server = "localhost";
	
	std::cout << "Enter user [default = root]: ";
        std::getline(std::cin, user);
	if(user.empty())
		user = "root";
	std::cout << "Enter password [default = ****]: ";
        std::getline(std::cin, password);
	if(password.empty())
		password = "amitg14";
	
	std::cout << "Try to connect....";
	m.connect(server, user, password);
	std::cout << "Connected!\n";
	
	return true;
}
int main()
{

	if(!connect())
		return -1;


	for(;;)
	{
		
		std::string query;

		std::cout << "SQL>";
		std::getline(std::cin, query);

		if(query.empty())
			continue;

		if(query.compare("exit") == 0)
		{
			std::cout << "\nBye!\n";
			break;
		}
		m.execute(query);
		

	}



	return 0;
}
