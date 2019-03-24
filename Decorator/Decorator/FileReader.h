#pragma once
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <regex>
#include <sstream>

using namespace std;

class FileReader {
private:

public:
	map<string, vector<vector<int>>> getShapeParams();
	string getShapeType(string &fLine);
	vector<vector<int>> getShapePoints(string &fLine);
	vector<int> parsePointCoords(string stringOfCoords);
};