#include <iostream>
#include <string>
#ifndef USERNAME_H
#define USERNAME_H

namespace {

	std::string username;
	bool isValid();
}

namespace Authenticate {

	std::string getUserName();
	void inputUserName();
}

#endif // USERNAME_H
