#ifndef CS212_REVIEW_PROJECT_GRADEBOOK_H
#define CS212_REVIEW_PROJECT_GRADEBOOK_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

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
    // Might want to add something that keeps track of the number of entries

public:
    // Constructor that gets assignments and grades from a file
    Gradebook(std::string file_name);
    // Lists all the assignments that are currently in title_assignment
    void list_assignments();
    // List all the different categories
    void list_categories();
    // Calculates the grade for an individual assignment called name
    float get_grade_individual(std::string name);
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
