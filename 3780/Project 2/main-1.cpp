#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <iomanip>
#include <stdlib.h>
#include "banner.h"
#include "create.h"
#include "multiple.h"
#include "login.h"

int main() {
	
	bool quit = false;
	bool valid = false;
	short choice;



	do {
		banner();

		std::cout << "\n";
		std::cout << std::setw(50) << "Please select an option below" << std::endl;
		std::cout << "\n";
		std::cout << std::setw(46) << "1) Log in to Account" << std::endl;
		std::cout << "\n";
		std::cout << std::setw(47) << "2) Create New Account" << std::endl;
		std::cout << "\n";
		std::cout << std::setw(53) << "3) Create Multiple Accounts" << std::endl;
		std::cout << "\n";
		std::cout << std::setw(41) << "4) Quit Program" << std::endl;
		std::cout << "\n";
		std::cout << std::setw(45) << "Enter choice here: ";
		std::cin >> choice;
		
		switch(choice) {
			case 1:					
				login();
				break;
			case 2:
				create();
				break;
			case 3:
				multipleAccounts();
				break;
			case 4: 
				quit = true;
				break;
			default:
				std::cout<< "Invalid Selection. Try Again!" << std::endl;

		}


	
	} while(!quit);

	std::cout << "exited loop!" << std::endl;

	return 0;
}



