#ifndef CS212_REVIEW_PROJECT_GRADEBOOK_H
#define CS212_REVIEW_PROJECT_GRADEBOOK_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

class Gradebook {
private:
    // Stores the name of the gradebook that it is ("Brandt" , "Ryan", "Jake")
    std::string name;
    std::vector<std::string> category;
    std::vector<std::string> title_assignment;
    // Don't need possible_points because that is determined by the category
    // Lab = 20 points Assignment = 50 points ...
    std::vector<int> earned_points;
    std::vector<bool> completed;
    std::string file_name;

public:
    // Constructor that gets assignments and grades from a file
    Gradebook(std::string file_name);
    // Lists all the assignments that are currently in title_assignment
    void list_assignments();
    // Takes in total points and earned points and returns a letter grade
    // To be used by the functions of the class
    static std::string get_letter_grade(float earned_points, float total_points) {
        float pct = std::round((earned_points / total_points) * 100);
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
    // Calculates the grade for an individual assignment called name
    float get_grade_individual(std::string name_assignment);
    // Calculates the grade for a certain category
    float get_category_total(std::string category);
    // Returns the total grade in different ways as defined by the project guidelines
    // User can choose which option to do
    float get_total_grade(int option);
    // User has option to edit existing assignment or create a new assignment
    // Automatically write new changes to the text file
    void edit(int option);
    // Getters
    std::vector<std::string> get_category() {return this->category;}
    std::vector<std::string> get_title_assignment() {return this->title_assignment;}
    std::vector<int> get_earned_points() {return this->earned_points;}
    std::vector<bool> get_completed() {return this->completed;}
};

#endif //CS212_REVIEW_PROJECT_GRADEBOOK_H
