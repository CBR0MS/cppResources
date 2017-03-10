#include <iostream>
#include "password.h"

namespace {

	bool isValid() {

		int nums = 0;

		if (password.length() >= 8) {

			for (int i = 0; i < password.length(); i++) {

				if (!isalpha(password[i])) {
					nums++;
				}
			}
			if (nums >= 1) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}

}

namespace Authenticate
{
	void inputPassword()
	{
		do
		{
			std::cout << "Enter your password (at least 8 characters and one non letter)" << std::endl;
			std::cin >> password;

		} while (!isValid());
	}
	std::string getPassword() {

		return password;
	}
}
