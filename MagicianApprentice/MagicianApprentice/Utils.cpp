#include "utils.h"

bool Same(const string& a, const string& b)
{
	return _stricmp(a.c_str(), b.c_str()) == 0;
}

bool Same(const char* a, const string& b)
{
	return _stricmp(a, b.c_str()) == 0;
}

bool Same(const string& a, const char* b)
{
	return _stricmp(a.c_str(), b) == 0;
}

int CustomRand(int min, int max)
{
	return (max > 0) ? min + (rand() % (max - min)) : 0;
}

void ParseInput(const string& line, vector<string>& arguments)
{
	for (unsigned int i = 0; i < line.size(); ++i) {
		string token = "";
		while (line[i] != ' ' && i < line.size()) {
			token += line[i];
			++i;
		}
		arguments.push_back(token);
	}
}