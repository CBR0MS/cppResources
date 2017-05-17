#include <iostream>
#include <regex>
#include <string>	

using namespace std;

int main() {

	string str1 = "20 watermelons, 11 oranges";
	string str2 = R"(<div id = "slider" class = "container"></div>)"; // raw string
	string address1 = "20201 K Street, Washington, DC";
	string address2 = "94920 B Street, San Rafael, CA";

	// 1: replace 11 with 0

	regex re("11");
	string replace = "0";
	cout << regex_replace(str1, re, replace) << endl;

	// 2: replace "water" with ""

	regex re2("water");
	string replace2 = "";
	cout << regex_replace(str1, re2, replace2) << endl;

	// 3: replace "slider" with "slideshow"

	regex re3("id[\\s]*\\=[\\s]*\"slider\"");
	string replace3 = R"(id = "slideshow")"; // raw string
	cout << regex_replace(str2, re3, replace3) << endl;

	// 4: search for 5 digits 

	regex re4("\\d{5}");
	smatch res;
	regex_search(address1, res, re4);
	cout << res.str() << endl;

	regex_search(address2, res, re4);
	cout << res.str() << endl;

	return 0;
}
