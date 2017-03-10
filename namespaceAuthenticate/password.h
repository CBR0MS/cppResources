#include <iostream>
#include <string>
#ifndef PASSWORD_H
#define PASSWORD_H

namespace {

	std::string password;
	bool isValid();
}

namespace Authenticate {

	std::string getPassword();
	void inputPassword();
}

#endif // PASSWORD_H
