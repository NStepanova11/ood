#include "stdafx.h"
#include "FileReader.h"

map<string, vector<vector<int>>> FileReader::getShapeParams() {
	string fLine="";
	vector<string> fileLines;
	vector<vector<int>> shapePoints;
	map<string, vector<vector<int>>> shapeParams;

	ifstream f("input.txt");
	while (getline(f, fLine)){
		string shapeName = getShapeType(fLine);
		//cout << shapeName << endl;
		shapePoints = getShapePoints(fLine);
		/*
		for (auto elem : shapePoints) {
			for (auto e : elem)
			{
				cout << e << " ";
			}
			cout << endl;
		}
		*/
		shapeParams.insert(pair<string, vector<vector<int>>>(shapeName,shapePoints));
	}
	return shapeParams;
}

string FileReader::getShapeType(string &fLine) {
	string type = fLine.substr(0, fLine.find(":"));
	//cout << fLine << endl;
	return (type);
}

vector<vector<int>> FileReader::getShapePoints(string &fLine) {
	vector<vector<int>> shapePoints;
	regex pointNameX("(=[0-9]*,)([0-9]*;)"); 
	regex pointNameR("(=[0-9]*;)");
	smatch x;
	while (regex_search(fLine, x, pointNameX) || regex_search(fLine, x, pointNameR)) {
		{
			shapePoints.push_back(parsePointCoords(x[0]));
		}
		fLine = x.suffix().str();
	}
	return shapePoints;
}

vector<int> FileReader::parsePointCoords(string pointCoords) {
	vector<int> coords;
	string num = "";
	int p;
	for (char c: pointCoords)
	{
		if (isdigit(c)) {
			num += c;
		}
		else if (!isdigit(c) && num.size() != 0) {
			stringstream ss;
			ss << num;
			ss >> p;
			coords.push_back(p);
			num.clear();
		}
	}

	return coords;
}