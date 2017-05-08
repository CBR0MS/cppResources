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

vector<pair<int, int>> getInput(string filepath);
vector<int> findInPairs(int p_num, vector<pair<int, int>> p_vec);
void addNodesToGraph(int A, vector<pair<int, int>>& p_pairs, map<char, set<int>>& p_map, const char& loc);
void sortInput(vector<pair<int, int>>& p_pairs, map<char, set<int>>& p_map);
void showLinks(map<char, set<int>> p_map);

int main() {
    
    // Communities or groups (nodes that are connected) are represented as a key in a
    // map by a character. Each key has a set that stores the numbers of the
    // individual connected nodes. It looks like this...
    
    // groups ->    'A'     'B'     'C'   ...the key in the map (characters)
    //               |       |       |
    //               V       V       V
    //              ___     ___     ____
    // nodes  ->   | 1 |   | 5 |   | 11 | ...the data in the map (sets)
    //             | 2 |   | 6 |   | 12 |
    //             | 3 |   | 7 |   | 13 |
    //             | 4 |           | 14 |
    //                             | 15 |
    
    // The use of a set as the sub-container within the map ensures that there is
    // only one occurrence of each node, and it also sorts the nodes into ascending
    // order automatically. The functions defined below allow the order of the nodes
    // to be preserved, so in order to take advantage of this, using an unordered set
    // would be more appropriate.
    
    map<char, set<int>> conGraph; // stores groups and their connections
    
    // getInput() reads in the data from the input file as two ints A, B
    // and puts them into a pair to make handling easier, and places that pair
    // into a vector. This vector of pairs is returned.
    
    vector<pair<int, int>> pairs = getInput("connectedGraphs.txt");
    
    // sortInput() utilizes the recursive function addNodesToGraph() to place the nodes
    // in groups. The recursive function adds the integer to the map's sub-container,
    // then determines any other links that it has. For example, if it is passed integer
    // 31, it finds all instances of 31 and recursively adds each of 31's own pairs,
    // such as 26 and 22 to the sub-container, repeating the process for all instances of
    // 26 and 22, their pairs, and so on, until there are no more branches.
    
    sortInput(pairs, conGraph);
    
    // Now that all the nodes are stored in their respective groups,
    // we can show the links.
    
    showLinks(conGraph);
    
    return 0;
}

void sortInput(vector<pair<int, int>>& p_pairs, map<char, set<int>>& p_map) {
    
    char group = 'A';
    
    while (p_pairs.size() > 0) {
        
        addNodesToGraph((p_pairs.at(0)).first, p_pairs, p_map, group); // puts the nodes in place
        
        if (p_pairs.size() > 0) { // get rid of any pairs that are already in the group
            
            for (auto it = p_map[group].begin(); it != p_map[group].end(); it++) {
                
                for (int j = 0; j < p_pairs.size(); j++) {
                    
                    if (p_pairs.at(j).first == *it || p_pairs.at(j).second == *it) {
                        
                        p_pairs.erase(p_pairs.begin() + j);
                    }
                }
            }
        }
        group++;
    }
}

void addNodesToGraph(int A, vector<pair<int, int>>& p_pairs, map<char, set<int>>& p_map, const char& loc) {
    
    vector<int> res = findInPairs(A, p_pairs); // get a vector of the node's links
    
    if (res.size() == 0) { // the branch is ended because it has no links
        
        p_map[loc].insert(A);
        return;
    }
    else {
        
        p_map[loc].insert(A);
        
        for (int i = 0; i < res.size(); i++) { // iterating through the instances of each of the nodes
            
            int next = p_pairs.at(res.at(i)).first; // grab the first and second values from the found pair
            int next2 = p_pairs.at(res.at(i)).second;
            
            p_pairs.erase(p_pairs.begin() + res.at(i)); // once we've used a pair, we have to delete it
            
            // we want to pass the value in the pair that isn't already in
            // the sub-container, so we'll use the find() function from STL to seek it.
            
            auto it = find(p_map[loc].begin(), p_map[loc].end(), next); // make an iterator
            
            if (it != p_map[loc].end()) { // if the first value does exist, we want the second one
                
                it = find(p_map[loc].begin(), p_map[loc].end(), next2); // get the second iterator
                
                if (it == p_map[loc].end()) { // if the second iterator is null, pass second value
                    
                    addNodesToGraph(next2, p_pairs, p_map, loc); // recursively pass second value
                }
            }
            else {
                addNodesToGraph(next, p_pairs, p_map, loc); // recursively pass first value
            }
            res = findInPairs(A, p_pairs); // update the vector after returning from call
        }
    }
}

vector<int> findInPairs(int p_num, vector<pair<int, int>> p_vec) {
    
    // finds the indexes where p_num exists in the passed vector
    
    vector<int> res;
    
    for (int i = 0; i < p_vec.size(); i++) {
        
        if ((p_vec.at(i)).first == p_num) {
            
            res.push_back(i);
        }
        else if ((p_vec.at(i)).second == p_num) {
            
            res.push_back(i);
        }
    }
    return res;
}

vector<pair<int, int>> getInput(string filepath) {
    
    vector<pair<int, int>> pairs;
    
    fstream in(filepath);
    
    if (in.is_open()) {
        
        string line = "";
        
        while (!in.eof()) {
            
            string A = "";
            string B = "";
            bool pairA = false;
            int adds = 0; // for accidental whitespace or newlines
            
            getline(in, line);
            
            for (int i = 0; i < line.length(); i++) {
                
                if (isdigit(line[i])) { // ensure the character isn't a whitespace
                    
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
