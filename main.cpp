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

    // Create a gradebook

    // Display the controls menu

    /* There will be a menu that will be displayed so the user can choose a number. For certain options, a sub-menu will open
    1- Get Grade
     1a- for getting the current course grade
     2a- for getting the course grade and total grade for each category
     3a- for getting the course grade and all grades on assignments for each category
    2- List assignments
     2a- for listing all assignments in the gradebook
     2b- listing all assignments in a specific category
    3- add a new assignment
    4- edit an assignment
     4a- edit assignment name
     4b- edit category name
     4c- edit points earned
     4d- mark assignment as complete
    5- remove an assignment from the gradebook
    */

    // We'll get the user's choice and check to make sure it's valid

    /* Perform functions on the gradebook
    1a- will print get_total_grade to get the overall course grade
    1b- will print get_total_grade just like option 1, and it will print get_category_total on each category to get that category's grade
    1c- will print get_total_grade just, like the first two options. For each category it will print that category's
        grade and then iterate through all the assignments in that category and print those grades with get_grade_individual
    2a- will run list_assignments to list all the assignments in the gradebook
    2b- will run iterate through the assignments vector and print out assignments if it matches the entered category
    3- will ask the user to enter all the information to write to the text file with new line in the Category Title EarnedPoints IsCompleted format
    4a-d will ask the user for the new assignment name, category name, points earned, or completion and set that assignments value's accordingly
    5- will remove that line from the file and the vectors storing the assignment's info
     */

    // after the user enters a choice it will run the function and ask the user to enter another input. They can enter 'quit' to stop

    // Creates the gradebook
    Gradebook my_gradebook(file_name); // Not sure what we're doing, but I made a temporary one for now
    //Gradebook brandt_gradebook(file_name);

    // Display the controls menu
    std::cout << "1- Get current grade";
    std::cout << "2- Get current grade and grades for each category";

    std::cout << "2- List all assignments";
    std::cout << "3- List assignments in a specific category";
    std::cout << "4- List assignments in a specific category";

    std::string user_choice;
    std::cin >> user_choice;

    if (user_choice == "1") {
        // Option 1 to return the overall course grade
        std::cout << std::to_string(my_gradebook.get_total_grade(1));
    }
    else if (user_choice == "2") {

    }

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
