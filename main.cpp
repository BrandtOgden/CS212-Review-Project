#include <iostream>
#include "gradebook.h"

int main() {

    /* Have different options for what the user can do and then show the options menu to do different things with it
    1- Use one of our existing gradebooks
     1a- Ryan Brooks
     1b- Ryan Shilling
     1c- Jake Dansereau
     1d- Brandt Ogden
    2- Use their own file to make a gradebook
     */

    std::cout << "What would you like to do?" << std::endl;
    std::cout << "Type 1 - Open the grade book of one us" << std::endl;
    std::cout << "     2 - Use your own file to create a gradebook" << std::endl;
    std::string choice;
    std::cin >> choice;
    while (choice != "1" && choice != "2") {
        std::cout << "Invalid option, try again!" << std::endl;
        std::cin >> choice;
    }

    // Handles the different choices that the user has
    if (choice == "1") {
        std::cout << "Which person's gradebook would you like to open?" << std::endl;
        std::cout << "    a - Ryan Brooks" << std::endl;
        std::cout << "    b - Ryan Shilling" << std::endl;
        std::cout << "    c - Jake Dansereau" << std::endl;
        std::cout << "    d - Brandt Ogden" << std::endl;
        std::string person_choice;
        std::cin >> person_choice;
        // Check for valid input
        while (person_choice != "a" && person_choice != "b" && person_choice != "c" && person_choice != "d") {
            std::cout << "Invalid option, try again!" << std::endl;
            std::cin >> person_choice;
        }
        // Does things based on the person_choice
        if (person_choice == "a") {
            Gradebook gradebook("RyanB_grades.txt");
        } else if (person_choice == "b") {
            Gradebook gradebook("RyanS_grades.txt");
        } else if (person_choice == "c") {
            Gradebook gradebook("Jake_grades.txt");
        } else {
            // Choice d
            Gradebook gradebook("Brandt_grades.txt");
        }
    } else {
        // Remind the user to make sure the file is in the right place
        std::cout << "Make sure your file is in the Grades folder, /cmake-build-debug/Grades" << std::endl;
        // Opens the file specified by the user and does error checking for a valid file
        std::string file_name;
        std::cout << "Enter the name of a file from which you want to create a gradebook: " << std::endl;
        std::cin >> file_name;
        while (!HelperFunctions::check_valid_file(file_name)) {
            std::cout << "This is not the name of a file in the Grades folder, try again!" << std::endl;
            std::cin >> file_name;
        }
        //TODO
        // Add a check for whether the file is in a valid format

        // Creates the gradebook
        Gradebook gradebook(file_name);
    }


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

    // Start of the main loop that will do different things to do the gradebook
    std::cout << "What would you like to do with the gradebook?" << std::endl;
    std::cout << "    1 - Get your grade" << std::endl;
    std::cout << "    2 - List the current assignments" << std::endl;
    std::cout << "    3 - Create a new assignment" << std::endl;
    std::cout << "    4 - Edit an existing assignment" << std::endl;
    std::cout << "    5 - Remove an assignment" << std::endl;

    //TODO
    // Continue working on main loop and have it do the different options that Ryan specified


    /*
    // Gets the grade of an assignment based on what user enters
    std::string name_assignment;
    std::cout << "Enter the name of an assignment that you would like to see the grade: " << std::endl;
    std::cin >> name_assignment;
    // Loop through until we get a valid assignment name
    while (!my_gradebook.get_grade_individual(name_assignment)) {
        std::cin >> name_assignment;
    }

    //Asks user to enter category they want to see their list of grades for
    //Also returns the total grade for that particular category
    std::string category; 
    std::cout << "Enter a category type that you would like to see all grades from:";
    std::cin >> category; 
    float get_category_total(std::string category);

     */

}
