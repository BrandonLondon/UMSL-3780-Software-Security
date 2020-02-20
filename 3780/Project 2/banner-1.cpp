#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "banner.h"

void banner() {
	system("clear");

	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);


	for(int i = 0; i < size.ws_row + 26; i++) {
		std::cout << "=";
	}


	std::cout << "\n";

	std::cout << std::setw(46) <<  "CS3780 Login Program" << std::endl;


	for(int i = 0; i < size.ws_row + 26; i++) {
		std::cout << "=";
	}

	std::cout << "\n";
}
