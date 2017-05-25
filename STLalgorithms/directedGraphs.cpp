// file: directedGraphs.cpp
// created by Christian Broms on 5/23/17
// testing an implemetation of the directed graphs algorithm

/* 
This implementaion uses only STL templates such as vectors and pairs. It 
creates a vector of the directed graph and outputs it onto the console.
There is the assumption that there will only be *ONE* fully connected 
graph in one input file. If there are multiple, check() can be called as
many timed as necessary, or until every possible combo has been achieved. 
*/

#include <iostream>
#include <vector>  // std::vector
#include <utility> // std::pair
#include <string>  // std::string (for processing file input)
#include <fstream> // (for file i/o)

using namespace std;

// function defs

vector<pair<int, int>> getInput(string filepath);
bool visited(vector<int> passed, int num);
vector<int> check(vector<pair<int, int>> pairs);

 int main() {

 	vector<pair<int, int>> pairs = getInput("directedGraphs.txt"); // get the file input 
  
	vector<int> res = check(pairs); // assemble a vector of the connections 

 	for (int i = 0; i < res.size(); i++) 
		cout << res.at(i) << ' '; // display the results 

 	return 0;
}


 vector<pair<int, int>> getInput(string filepath) { // get pairs from an input file

 	vector<pair<int, int>> pairs;

 	fstream in(filepath);

 	if (in.is_open()) {

 		string line = "";

 		while (!in.eof()) {

 			string A = "";
			string B = "";
			bool pairA = false;
			int adds = 0;

 			getline(in, line);

 			for (int i = 0; i < line.length(); i++) {

 				if (isdigit(line[i])) { // ensure the character isn't a whitespace or comma

 					if (!pairA) {
						A += line[i]; // add numbers to the string 
						adds++;
					}
					else {
						B += line[i]; // add numbers to the string 
						adds++;
					}
				}
				else {
					if (!pairA) {
						pairA = true;
					}
				}
			}
			if (adds > 0) {
				pair<int, int> tpair(stoi(A), stoi(B)); // string to int
				pairs.push_back(tpair);
			}
		}
		return pairs;
	}
	else {
		cout << "Error opening file";
		return pairs;
	}
}

 bool visited(vector<int> passed, int num) { // record the numbers that have been visited 
	
	for (int i = 0; i < passed.size(); i++) {
		if (num == passed.at(i)) {
			return true;
		}
	}
	return false;
}

 vector<int> check(vector<pair<int, int>> pairs) { // check each and assemble a vector of the results

 	vector<int> res;

 	for (int i = 0; i < pairs.size(); i++) {

 		int a = pairs.at(i).first; // trying to get back to this value
		vector<int> visitedNums; // keeping track of numbers we've visited to avoid an endless loop

 		int j = pairs.at(i).second;
		res.push_back(j);

 		while (!visited(visitedNums, j)) {

 			visitedNums.push_back(j);

 			for (int k = 0; k < pairs.size(); k++) {

 				if (pairs.at(k).first == j) {
					j = pairs.at(k).second;
					res.push_back(j);
	
				}
			}

 			if (j == a) {
				return res; // found the OG number, return the graph
			}
		}
		res.clear(); // didn't find it, clear and try again
	}
}
