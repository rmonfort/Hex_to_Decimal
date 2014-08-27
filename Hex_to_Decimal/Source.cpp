#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cctype>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::map;
using std::getline;

int hex_to_dec(const string &hexdecimal)
{
	//Generate hex to dec conversion table
	map<char, int> conversion_table;
	conversion_table['a'] = 10;
	conversion_table['b'] = 11;
	conversion_table['c'] = 12;
	conversion_table['d'] = 13;
	conversion_table['e'] = 14;
	conversion_table['f'] = 15;

	int n = hexdecimal.size() - 1;
	int decimal = 0;
	int number = 0;
	// Convert hex to dec
	for (const auto &c : hexdecimal)
	{
		if (isalpha(c))
		{
			number = conversion_table.find(c)->second;
			decimal += number * pow(16, n);
		}
		else
		{
			// Convert char to int
			number = c - '0';
			decimal += number * pow(16, n);
		}
		n--;
	}

	return decimal;
}

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	string line;
	while (getline(ifs, line))
	{
		cout << hex_to_dec(line) << endl;
	}

	return 0;
}