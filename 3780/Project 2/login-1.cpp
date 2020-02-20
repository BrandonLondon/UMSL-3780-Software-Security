#include "login.h"
#include "banner.h"
#include "sha256.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

void failed();
void success();

void login() {
	int choice;
	std::string username;
	std::string password;
	
	do {	
		banner();
		std::cout << "\n\n";
		std::cout << std::setw(56) << "Choose Password File To Validate Against" <<std::endl;
		std::cout << "\n\n";

		std::cout << std::setw(44) << "1. Plain Text File" << std::endl;
		std::cout << "\n";
		std::cout << std::setw(40) << "2. Hashed File" << std::endl;
		std::cout << "\n";
		std::cout << std::setw(47) << "3. Hashed FIle w/Salt" << std::endl;
		std::cout << "\n\n";
		std::cout << std::setw(45) << "Enter choice here: ";
		std::cin >> choice;
		
		switch(choice) {
			case 1:
				banner();
				std::cout << "\n\n";
				std::cout << std::setw(42) << "Enter Username: ";
				std::cin >> username;
				
				std::cout << "\n";
				std::cout << std::setw(42) << "Enter Password: ";
				std::cin >> password;

				authenticate(username, password, choice);
				break;
			case 2:
				banner();
				std::cout << "\n\n";
				std::cout << std::setw(42) << "Enter Username: ";
				std::cin >> username;
				
				std::cout << "\n";
				std::cout << std::setw(42) << "Enter Password: ";
				std::cin >> password;

				authenticate(username, password, choice);
				break;
			case 3:	
				banner();
				std::cout << "\n\n";
				std::cout << std::setw(42) << "Enter Username: ";
				std::cin >> username;
				
				std::cout << "\n";
				std::cout << std::setw(42) << "Enter Password: ";
				std::cin >> password;

				authenticate(username, password, choice);
				break;
			default:
				break;	
		}

	} while(!(choice == 1 || choice == 2 || choice == 3));
	
}

void authenticate(std::string username, std::string password, int file) {
	std::string str = "";
	bool authenticated = false;

	std::string User[3];

	switch(file) {
		case 1: {
			std::ifstream input1("pass1");
			if(input1.is_open()) {
				//grep username and password
				while(std::getline(input1, str)) {
					std::istringstream tokenizer(str);
					std::getline(tokenizer, User[0], ':');
					std::getline(tokenizer, User[1]);

					if(tokenizer) {
						//check username and password
						if(username == User[0] && password == User[1]) {
							authenticated = true;
							success();
						}
					} else {
						std::cout << std::setw(50) << "Error Reading File" << std::endl;
					}
				} 

				if(!authenticated) {
					failed();
				} 

				input1.close();	
	
			} else {
				std::cout << std::setw(50) << "Unable To Open File" << std::endl;
			}
	
			break;
		}

		case 2: {
			std::ifstream input2("pass2");
			if(input2.is_open()) {
				while(std::getline(input2, str)) {
					std::istringstream tokenizer(str);
					std::getline(tokenizer, User[0], ':');
					std::getline(tokenizer, User[1]);

					if(tokenizer) {
						if(username == User[0] && sha256(password) == User[1]) {	
							authenticated = true;
							success();	
						}
					} else {
						std::cout << std::setw(50) << "Error Reading File" << std::endl;
					}
				}
					if(!authenticated) {
						failed();
					}

					input2.close();
			} else {
				std::cout << std::setw(50) << "Unable To Open File" << std::endl;
			
			} 
			
			break;
		}

		case 3: {
			std::ifstream input3("pass3");
			if(input3.is_open()) {
				while(std::getline(input3, str)) {
					std::istringstream tokenizer(str);
					std::getline(tokenizer, User[0], ':');
					std::getline(tokenizer, User[1], ':');
					std::getline(tokenizer, User[2]);
							
					if(tokenizer) {
						if(username == User[0] && sha256(password + User[2]) == User[1]) {
							authenticated = true;
							success();
						}
					} else {
						std::cout << std::setw(50) << "Unable To Open File" << std::endl;
					}
				}

					if(!authenticated) {
						failed();
					}

					input3.close();
			} else {
				std::cout << std::setw(50) << "Unable To Open File" << std::endl;
			}

			break;
		}

		default:
			break;
	}
	

	std::cin.get();
	std::cin.get();
}

void success() {
	banner();
	std::cout << "\n\n";
	std::cout << std::setw(47) << "Successfully Logged In" << std::endl; 
	std::cout << "\n\n";
	std::cout << std::setw(49) << "Press Any Key To Continue" << std::endl;
}

void failed() {
	banner();
	std::cout << "\n\n";
	std::cout << std::setw(50) << "Invalid Username or Password" << std::endl; 
	std::cout << "\n\n";
	std::cout << std::setw(49) << "Press Any Key To Continue" << std::endl;
}
