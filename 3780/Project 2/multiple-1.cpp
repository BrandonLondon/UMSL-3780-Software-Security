#include "create.h"
#include "banner.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <unistd.h>

std::string passRandomGen(int);

void multipleAccounts() {
	int numberOfAccounts = 0;
	int passwordLength = 0;
	const std::string basename = "user";
	srand(static_cast<int>(time(NULL)));

	banner();
	std::cout << "\n\n";	
	std::cout << std::setw(51) << "Number Of Accounts To Create: ";
	std::cin >> numberOfAccounts;
	std::cout << "\n\n";
	std::cout << std::setw(49) << "Desired Password Length: ";
	std::cin >> passwordLength;
	
	for(int i = 0; i < numberOfAccounts; i++) {
		//get usernames
		std::string username = "";
		std::string tempStr = std::to_string(i);
		if(i < 10) {
			username = basename + "000" + tempStr;
		} else {
			username = basename + "00" + tempStr;
		}

		//get passwords		
		std::string password = passRandomGen(passwordLength);

		//create accounts
		newAccount(username, password);
	}


	std::cout << "\n\n\n\n\n\n";
	std::cout << std::setw(51) << "Accounts Successfully Created" << std::endl;
	std::cout << "\n\n\n";
	std::cout << std::setw(49) << "Press Any Key To Continue" << std::endl; 
	
	//hold screen
	std::cin.get();
	std::cin.get();
}

std::string passRandomGen(int length) {
	usleep(1000000);	
	char source[length];
	source[length] = '\0';
	
	while(--length > -1) {
		source[length] = 97 + rand() % 26;
	}

	std::string password(source);
	return password;
}
