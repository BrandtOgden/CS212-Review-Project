#include <iostream>
#include "gradebook.h"

int main() {
    // Will eventually have a big loop that allows for the user to either look at our grades
    // use their own files or potentially just input grade manually

    // Prompts the user the enter a file name that has assignments etc...
    std::string file_name;
    std::cout << "Enter the name of a file that has assignments on the next line:" << std::endl;
    std::cin >> file_name;
    //std::string file_name = "Brandt_grades.txt";
    while (HelperFunctions::check_valid_file(file_name) == 0) {
        std::cout << "This is not the name of a file in the Grades folder, try again!" << std::endl;
        std::cin >> file_name;
    }
    // Creates the gradebook
    Gradebook brandt_gradebook(file_name);

    brandt_gradebook.list_assignments();
    std::cout << std::endl;

    // Gets the grade of an assignment based on what user enters
    std::string name_assignment;
    std::cout << "Enter the name of an assignment that you would like to see the grade: " << std::endl;
    std::cin >> name_assignment;
    // Loop through until we get a valid assignment name
    while (!brandt_gradebook.get_grade_individual(name_assignment)) {
        std::cin >> name_assignment;
    }

    //Asks user to enter category they want to see their list of grades for
    //Also returns the total grade for that particular category
    std::string category; 
    std::cout << "Enter a category type that you would like to see all grades from:"
    std::cin >> category; 
    float get_category_total(std::string category);

}
