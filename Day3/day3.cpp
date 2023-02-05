//
// Created by Vincent Allen on 2/4/23.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

void day3() {
    std::string input_line;
    std::ifstream input_file("../Day3/day_3_input.txt");

    constexpr int ascii_zero = 48;
    constexpr int ascii_one = 49;

    std::map<int, std::vector<int>> columns {};

    while (getline (input_file, input_line)) {
        // If the columns map is empty, figure out how many digits there are and initialize it
        if (columns.empty()) {
            for (int i = 0; i < input_line.length(); ++i) {
                std::cout << "Digit" << '\n';
                std::vector<int> new_vec {};
                columns[i] = new_vec;
            }

        }

        for (char binary_digit : input_line) {

        }
    }

    input_file.close();
}