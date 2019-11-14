// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include <algorithm>


int compare_input(std::string a, std::string b) {
	int result = 0;
	unsigned count = 0;
	int diff = 0;
	if (a.size() > b.size()) {
		diff = a.size() - b.size();
		count = b.size();
	}
	else {
		diff = b.size() - a.size();
		count = a.size();
	}
	for (unsigned i = 0; i < count; i++) {
		if (a[i] != b[i])
			result += 1;
	}
	result += diff;
	return result;
}

int similiar_password(std::string cp) {
	std::ifstream ifs("common_passwords.txt");
	std::string output;
	int min = 1000000;
	while (!ifs.eof()) {
		ifs >> output;
		if (ifs.eof()) break;
		int result = compare_input(cp, output);
		if (result < min) {
			min = result;
		}
	}
	std::ifstream ifs2("common_passwords.txt");
	std::vector<std::string> found_strs;
	while (!ifs2.eof()) {
		ifs2 >> output;
		if (ifs2.eof()) break;
		int result = compare_input(cp, output);
		if (result == min) {
			found_strs.push_back(output);
		}
	}
	// sort found_strs
	std::sort(found_strs.begin(), found_strs.end());
	// print found_strs
	for (size_t i = 0; i < found_strs.size(); i++) {
		std::cout << found_strs[i] << ", ";
	}
	std::cout << std::endl;
	return min;
}
int main(){ 
	std::cout << "Give me a password:" << std::endl;
	std::string input;
	std::cin >> input;
	std::cout << "You provided a password of " << input << std::endl;
	std::cout << "The most similar passwords to " << input << " are:" << std::endl;
	int result = similiar_password(input);

	std::cout << "All of which are "<< result << " character(s) different."<< std::endl;
}

