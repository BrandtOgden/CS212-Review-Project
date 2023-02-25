#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include "helper_functions.cpp"

class Gradebook {
private:
    // Stores the name of the gradebook that it is ("Brandt" , "Ryan", "Jake")
    std::string name;
    std::vector<std::string> categoryList;
    std::vector<std::string> title_assignment;
    // Don't need possible_points because that is determined by the category
    // Lab = 20 points Assignment = 50 points ...
    std::vector<int> earned_points;
    std::vector<bool> completed;
    std::string file_name;

    //vectors for grades stored in each category
    std::vector<int> labGrades;
    std::vector<int> assignmentGrades;
    std::vector<int> proj1Grades;
    std::vector<int> proj2Grades;
    std::vector<int> examGrades;


public:
    // Constructor that gets assignments and grades from a file
    Gradebook(std::string file_name);
    // TODO
    // Add a function that checks the formatting of the file to make sure there are labs assignments etc...
    // Lists all the assignments that are currently in title_assignment
    void list_assignments();
    // Calculates the grade for an individual assignment called name
    // Returns true or false based on if name_assignment is a valid assignment
    int get_grade_individual(std::string name_assignment);
    // Calculates the grade for a certain category
    float get_category_total(std::string category);
    // Returns the total grade in different ways as defined by the project guidelines
    // User can choose which option to do
    float get_total_grade(int option);
    // User has option to edit existing assignment or create a new assignment
    // Automatically write new changes to the text file
    void edit(int option);
    // Getters
    std::vector<std::string> get_category() {return this->categoryList;}
    std::vector<std::string> get_title_assignment() {return this->title_assignment;}
    std::vector<int> get_earned_points() {return this->earned_points;}
    std::vector<bool> get_completed() {return this->completed;}
    std::string new_assignment(std::string category, std::string name, int points_earned, std::string is_completed);
};


