#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <regex>
#include <sstream>
#include <list>

using namespace std;

class FileReader {
private:

public:
	list<pair<string, vector<vector<int>>>> getShapeParams();
	string getShapeType(string &fLine);
	vector<vector<int>> getShapePoints(string &fLine);
	vector<int> parsePointCoords(string stringOfCoords);
};
