#include <iostream>
#include <fstream>

class HelperFunctions {
public:
    // Takes in total points and earned points and returns a letter grade
    static std::string get_letter_grade(int pct) {
        if (pct >= 94) {
            return "A";
        } else if (pct < 94 && pct >= 90) {
            return "A-";
        } else if (pct < 90 && pct >= 87) {
            return "B+";
        } else if (pct < 97 && pct >= 83) {
            return "B";
        } else if (pct < 83 && pct >= 80) {
            return "B-";
        } else if (pct < 80 && pct >= 77) {
            return "C+";
        } else if (pct < 77 && pct >= 73) {
            return "C";
        } else if (pct < 73 && pct >= 70) {
            return "C-";
        } else if (pct < 70 && pct >= 67) {
            return "D+";
        } else if (pct < 67 && pct >= 63) {
            return "D";
        } else if (pct < 63 && pct >= 60) {
            return "D-";
        } else {
            return "F";
        }
    }

    // Checks if file_name actually opens a file
    static bool check_valid_file(std::string file_name) {
        std::ifstream infile("Grades/" + file_name);
        if (infile.is_open()) {
            infile.close();
            return true;
        }
        infile.close();
        return false;
    }
};

