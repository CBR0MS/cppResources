#include <iostream>
#include "username.h"

namespace {

	bool isValid() {

		if (username.length() == 8) {

			for (int i = 0; i < username.length(); i++) {

				if (!isalpha(username[i])) {
					return false;
				}
			}
			return true;
		}
		else {
			return false;
		}
	}

}

namespace Authenticate
{
	void inputUserName()
	{
		do
		{
			std::cout << "Enter your username (8 letters only)" << std::endl;
			std::cin >> username;

		} while (!isValid());
	}
	std::string getUserName() {

		return username;
	}
}
