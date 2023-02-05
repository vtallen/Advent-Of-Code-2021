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

    constexpr char ascii_zero = 48;
    constexpr char ascii_one = 49;

    std::map<int, std::vector<int>> columns {};
    std::map<int, int> most_common_bit {};
    std::map<int, int> least_common_bit {};


    while (getline (input_file, input_line)) {
        // If the columns map is empty, figure out how many digits there are and initialize it
        if (columns.empty()) {
            for (int i = 0; i < input_line.length(); ++i) {
                std::vector<int> new_vec {};
                columns[i] = new_vec;
            }
        }

        int column_num {0};
        for (char binary_digit : input_line) {
            int current_digit = (binary_digit == ascii_zero) ? 0 : 1;
            columns[column_num].push_back(current_digit);

            ++column_num;
        }
    }

    // Find the most common and least common bits
    for (int i = 0; i < columns.size(); ++i) {
        int num_zeros = std::count(columns[i].begin(), columns[i].end(), 0);
        int num_ones = std::count(columns[i].begin(), columns[i].end(), 1);

        int most_common = (num_zeros > num_ones) ? 0 : 1;
        int least_common = (num_zeros > num_ones) ? 1 : 0;

        most_common_bit[i] = most_common;
        least_common_bit[i] = least_common;
    }

    char gamma_rate_binary[12] {};
    for (int i = 0; i < most_common_bit.size(); ++i) {
        gamma_rate_binary[i] = (most_common_bit[i] == 0) ? ascii_zero : ascii_one;
    }

    char epsilon_rate_binary[12] {};
    for (int i = 0; i < least_common_bit.size(); ++i) {
        epsilon_rate_binary[i] = (least_common_bit[i] == 0) ? ascii_zero : ascii_one;
    }

    int gamma_rate_decimal = std::stoi(gamma_rate_binary, 0, 2);
    int epsilon_rate_decimal = std::stoi(epsilon_rate_binary, 0, 2);

    std::cout << "The gamma rate is: " << gamma_rate_decimal << '\n';
    std::cout << "The epsilon rate is: " << epsilon_rate_decimal << '\n';
    std::cout << "The power rate is: " << gamma_rate_decimal * epsilon_rate_decimal << '\n';



    input_file.close();
}