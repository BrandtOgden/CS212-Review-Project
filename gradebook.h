#ifndef CS212_REVIEW_PROJECT_GRADEBOOK_H
#define CS212_REVIEW_PROJECT_GRADEBOOK_H

#include <iostream>
#include <vector>

class gradebook {
private:
    std::vector<std::string> category;
    std::vector<std::string> title_assignment;
    std::vector<int> possible_points;
    std::vector<int> earned_points;
    std::vector<bool> completed;
    std::string file_name;

public:
    // Constructor
    gradebook(std::vector<std::string> category, std::vector<std::string> title_assignment,
              std::vector<int> possible_points, std::vector<int> earned_points, std::vector<bool> completed,
              std::string file_name);
    // Lists all the assignments that are currently in title_assignment
    void listAssignments();
    // List all the different categories
    void listCategories();
    // Calculates the grade for an individual assignment called name
    float getGradeIndividual(std::string name);
    // Calculates the grade for a certain category
    float getCategoryTotal(std::string category);
    // Returns the total grade in different ways as defined by the project guidelines
    // User can choose which option to do
    float getTotalGrade(int option);
    // User has option to edit existing assignment or create a new assignment
    // Automatically write new changes to the text file
    void edit(int option);
};

#endif //CS212_REVIEW_PROJECT_GRADEBOOK_H
