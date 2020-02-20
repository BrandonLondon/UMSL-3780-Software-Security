#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string.h>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <time.h>
#include "create.h"
#include "banner.h"
#include "sha256.h"
#include <openssl/rand.h>

#define USERNAME_LENGTH 8


void newAccount(std::string usernameStr, std::string passStr) {
	srand(time(NULL));


	//plaintext file
	std::ofstream output1;
	output1.open("pass1", std::ofstream::out | std::ofstream::app);
	output1 << usernameStr << ":" << passStr << "\n";
	output1.close();
		
	//sha256 file
	std::ofstream output2;
	output2.open("pass2", std::ofstream::out | std::ofstream::app);
	output2 << usernameStr << ":" << sha256(passStr) << "\n";
	output2.close();

	//sha256 w/salt file
	std::ofstream output3;
	int salt = rand() % 256;
	std::string saltStr = std::to_string(salt);
	output3.open("pass3", std::ofstream::out | std::ofstream::app);
	output3 << usernameStr << ":" << sha256(passStr + saltStr) << ":" << saltStr << "\n"; 
	output3.close();
}


void create() {
		
	bool valid = false;
	char usernameChar[USERNAME_LENGTH];
	std::string usernameStr;
	std::string passStr;

	do {

		banner();
	
		std::cout << "\n";	
		std::cout << std::setw(43) << "Create Account" << std::endl;
		std::cout << "\n\n";

		
		std::cout << std::setw(57) << "*username must be 8 alphanumeric characters" << std::endl;
		std::cout << "\n\n\n";	
	
		std::cout << std::setw(41) << "Enter Username: ";
		std::cin >> usernameStr;
		std::cout << "\n";
	
		std::cout << std::setw(41) << "Enter Password: ";
		std::cin >> passStr;
		std::cout << "\n\n\n\n";





		//check input
		if(!(usernameStr.empty() && passStr.empty())) {
			valid = true;
		} 

		//check username is appropriate length
		if(usernameStr.length() != USERNAME_LENGTH) {
			valid = false;	
		} else {
			std::copy(usernameStr.begin(), usernameStr.end(), usernameChar);
			usernameChar[USERNAME_LENGTH] = '\0';
		}

		//check username is alphanumeric
		for(int i = 0; usernameChar[i] != '\0'; i++) {
			if(isalpha(usernameChar[i] == 0)) {
				valid = false;
			}	

			if(isdigit(usernameChar[i] == 0)) {
				valid = false;
			}	
		}	
	
		
	} while(!valid);

	
	//write user info files
	if(valid) {
		newAccount(usernameStr, passStr);
	} else {
		std::cout << std::setw(50) << "Unable To Create Account" << std::endl;
		return;
	}


	std::cout << std::setw(49) << "Account Succesfully Created" << std::endl;
	std::cout << "\n\n\n";
	std::cout << std::setw(49) << "Press Any Key To Continue" << std::endl;	

	//hold screen
	std::cin.get();
	std::cin.get();
	
	return;
}	
