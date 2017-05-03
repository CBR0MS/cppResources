// File: ConnectedGraphs.cpp
// Compilers: Xcode 8.3.1 and MS Visual Studio 2017
// Created by Christian Broms on 4/28/17

// FILE DESCRIPTION:
// Implementation of a connected graph sorter
// using only STL containers and algorithms

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <string>

using namespace std;

pair<char, int> findLocation(pair<int, int> p_pair, map<char, set<int>> p_map);
vector<pair<int, int>> getConnections(string filepath);
void removeDuplicates(map<char, set<int>>& p_map);
void showLinks(map<char, set<int>> p_map);

int main() {

	// Communites or groups (nodes that are connected) are represented as a key in a 
	// map by a character. Each key has a set that stores the numbers of the 
	// induvidual connected nodes. It looks like this... 
	/*
		groups ->    'A'     'B'     'C'   ...the key in the map (characters)
					  |		  |       |
					  V		  V       V
					 ___	 ___	 ____
		nodes  ->	| 1 |   | 5 |   | 11 | ...the data in the map (sets)
					| 2 |   | 6 |   | 12 |
					| 3 |   | 7 |   | 13 |
					| 4 |		    | 14 |
									| 15 |
	*/

	map<char, set<int>> conGraph; // stores groups and their connections

	// getConnections() reads in the data from the input file as two ints A, B
	// and puts them into a pair to make handling easier, and places that pair
	// into a vector. This vector of pairs is returned.

	vector<pair<int, int>> pairs = getConnections("connectedGraphs.txt");

	// Now we have all the nodes from the input file stored in pairs, which 
	// are contained in a vector. We can check each pair and see if one
	// of the members A or B is in a group. If it is, we add the other 
	// corresponding missing member to the group. For example, if int A is 
	// already in Group 1, we know that int B must also be part of Group 1. 

	for (int i = 0; i < pairs.size(); i++) {

		// findLocation() iterates through the map and finds the group that int
		// pair A, B belongs in. The function returns a different pair containing the character
		// key of a group and whichever int A or B needs to be inserted at that group.
		// If A and B aren't in any of the groups, findLocation() returns a null key, which
		// indicates that a new group needs to be formed. 

		pair<char, int> res = findLocation(pairs.at(i), conGraph);

		if (res.first == '\0') {

			conGraph[conGraph.size() + 'A'].insert(pairs[i].first);
			conGraph[conGraph.size() + 'A' - 1].insert(pairs[i].second);
		}
		else {
			conGraph[res.first].insert(res.second);
		}
	}

	// now we check for duplicated nodes. This event is a product of any duplicate pairs
	// that may have been included in the input file. If one group contains some of the 
	// same nodes as another, the smaller group is merged into the larger one. 

	removeDuplicates(conGraph);

	// Now that all the nodes are stored in their respective groups, 
	// we can show the links. 

	showLinks(conGraph);

	return 0;
}

pair<char, int> findLocation(pair<int, int> p_pair, map<char, set<int>> p_map) {

	for (char i = 'A'; i < p_map.size() + 'A'; i++) { // iterating through communites

		auto it = find(p_map[i].begin(), p_map[i].end(), p_pair.first); // is first value in community?

		if (it == p_map[i].end()) {

			it = find(p_map[i].begin(), p_map[i].end(), p_pair.second); // is second value in community?

			if (it != p_map[i].end()) {

				pair<char, int> temp(i, p_pair.first);
				return temp; // second value is already in the community, return community key and value to add
			}
		}
		else {
			pair<char, int> temp(i, p_pair.second);
			return temp; // first value is already in the community, return community key and value to add
		}
	}
	pair<char, int> temp('\0', INT_MIN);
	return temp; // neither is found, return null key
}

void removeDuplicates(map<char, set<int>>& p_map) {

	set<char> delGroup; // set to store the keys of groups to delete

	for (char i = p_map.size() + 'A' - 1; i >= 'A'; i--) { // iterating through communities from last to first

		for (auto j = p_map[i].begin(); j != p_map[i].end(); j++) { // iterating through nodes in current community

			for (char k = i - 1; k >= 'A'; k--) { // iterating through the remaining groups not including current community

				if (find(p_map[k].begin(), p_map[k].end(), *j) != p_map[k].end()) { // do the other groups contain this node?

					if (p_map[k].size() > p_map[i].size()) { // add whichever group is smaller to the delete set
						delGroup.insert(i);
					}
					else {
						delGroup.insert(k);
					}
				}
			}
		}
	}
	for (auto it = delGroup.begin(); it != delGroup.end(); it++) { // now remove the duplicate groups

		if (*it != p_map.size() + 'A' - 1) { // is the group to delete between two other groups?

			char last;
			for (char x = *it; x < p_map.size() + 'A' - 1; x++) { // shift the groups behind it up and erase the last

				p_map[x] = p_map[x + 1];
				last = x + 1;
			}
			p_map.erase(last);
		}
		else { // just delete the last, nothing to shift up
			p_map.erase(*it);
		}
	}
}

vector<pair<int, int>> getConnections(string filepath) {

	vector<pair<int, int>> pairs;

	fstream in(filepath);

	if (in.is_open()) {

		string line = "";

		while (!in.eof()) {

			string A = "";
			string B = "";
			bool pairA = false;
			bool pairB = false;
			int adds = 0;

			getline(in, line);

			for (int i = 0; i < line.length(); i++) {

				if (isdigit(line[i])) {

					if (!pairA) {
						A += line[i];
						adds++;
					}
					else {
						B += line[i];
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
				pair<int, int> tpair(stoi(A), stoi(B));
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

void showLinks(map<char, set<int>> p_map) {

	cout << "\n\t------- NODE NETWORKS -------\n\n";
	cout << "\tThere are " << p_map.size() << " groups of nodes...\n\n";

	for (char i = 'A'; i < p_map.size() + 'A'; i++) {

		cout << "\tGroup " << i << ":\t";

		if (p_map[i].size() < 20 && p_map.size() > 0) {

			for (auto j = p_map[i].begin(); j != p_map[i].end(); j++) {

				cout << *j << ' ';
			}
		}
		else {
			cout << p_map[i].size() << " nodes";
		}
		cout << endl;
	}
}
