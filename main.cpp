#include <iostream>
#include <fstream>
#include <limits>
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

    // Variable to store the gradebook
    Gradebook* gradebook;

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
            gradebook = new Gradebook("RyanB_grades.txt");
        } else if (person_choice == "b") {
            gradebook = new Gradebook("RyanS_grades.txt");
        } else if (person_choice == "c") {
            gradebook = new Gradebook("Jake_grades.txt");
        } else {
            // Choice d
            gradebook = new Gradebook("Brandt_grades.txt");
        }
    } else {
        // Remind the user to make sure the file is in the right place
        std::cout << "Make sure your file is in the Grades folder, /cmake-build-debug/Grades\nRemember to include the file extension." << std::endl;
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
        gradebook = new Gradebook(file_name);
    }


    /* There will be a menu that will be displayed so the user can choose a number. For certain options, a sub-menu will open
    1- Get Grade
     1a- for getting the current course grade
     1b- for getting the course grade and total grade for each category
     1c- for getting the course grade and all grades on assignments for each category
     1d- for getting the grade of an individual category
     1e- for getting the grade of an individual assignment
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

    // Get input from user and check for valid form
    std::string gradebook_choice;
    std::cin >> gradebook_choice;
    while (gradebook_choice != "1" && gradebook_choice != "2" && gradebook_choice != "3" && gradebook_choice != "4" && gradebook_choice != "5") {
        std::cout << "Invalid option, try again!" << std::endl;
        std::cin >> gradebook_choice;
    }

    // Do things with that choice
    if (gradebook_choice == "1") {
        // Give the user the choice for different options to do
        std::cout << "What grade would you like?" << std::endl;
        std::cout << "    a - Your overall course grade" << std::endl;
        std::cout << "    b - Your overall course grade and the grade of each category" << std::endl;
        std::cout << "    c - Your overall course grade, grade of each category, and all the grades of the different deliverables" << std::endl;
        std::cout << "    d - Your grade for one specific category" << std::endl;
        std::cout << "    e - Your grade for a specific deliverable" << std::endl;

        // Checks for a valid option
        std::string grade_choice;
        std::cin >> grade_choice;
        while (grade_choice != "a" && grade_choice != "b" && grade_choice != "c" && grade_choice != "d" && grade_choice != "e") {
            std::cout << "Invalid option, try again!" << std::endl;
            std::cin >> grade_choice;
        }

        // Does things based on the choice
        if (grade_choice == "a") {
            //initializes a total_grade variable and sets it to function call
            float grade_return = gradebook->get_total_grade();
            std::cout << "Your total grade for the course is: " << grade_return;
            // TODO call get_total_grade()
        } else if (grade_choice == "b") {
            //overall course grade
            float grade_return = gradebook->get_total_grade();
            //grade of each category
            float lab_total = gradebook->get_category_total("Lab");
            float assign_total = gradebook->get_category_total("Assignment");
            float proj1_total = gradebook->get_category_total("Project 1");
            float proj2_total = gradebook->get_category_total("Project 2");
            float exam_total = gradebook->get_category_total("Exam");

           //outputting overall course grade and grade for each category
            std::cout << "Your total grade for the course is: " << grade_return << std::endl;
            std::cout << "Your total lab grade is: " << lab_total << std::endl;
            std::cout << "Your total assignment grade is: " << assign_total << std::endl;
            std::cout << "Your total project 1 grade is: " << proj1_total << std::endl;
            std::cout << "Your total project 2 grade is: " << proj2_total << std::endl;
            std::cout << "Your total exam grade is: " << exam_total << std::endl;


            // TODO call get_total_grade and get_category_grade for each category
        } else if (grade_choice == "c") {
            float grade_return = gradebook->get_total_grade();
            float lab_total = gradebook->get_category_total("Lab");
            float assign_total = gradebook->get_category_total("Assignment");
            float proj1_total = gradebook->get_category_total("Project 1");
            float proj2_total = gradebook->get_category_total("Project 2");
            float exam_total = gradebook->get_category_total("Exam");

            //total grade
            float total_grade = gradebook->get_total_grade();
            //outputting overall course grade and grade for each category
            std::cout << "Your total grade for the course is: " << grade_return << std::endl;
            std::cout << "Your total lab grade is: " << lab_total << std::endl;
            std::cout << "Your total assignment grade is: " << assign_total << std::endl;
            std::cout << "Your total project 1 grade is: " << proj1_total << std::endl;
            std::cout << "Your total project 2 grade is: " << proj2_total << std::endl;
            std::cout << "Your total exam grade is: " << exam_total << std::endl;
            std::cout << "Your total grade for the course is: " << total_grade << std::endl;


            // TODO call get_total_grade, get_category_grade and get_individual_grade
        } else if (grade_choice == "d") {
            float grade_return;
            //setting single_category to temporary value
            std::string single_category = "temp";
            std::cout << "Enter a category you want to see the grade for: "<< std::endl << "(enter 'Lab', 'Assignment', 'Project 1', Project 2', or 'Exam')";
            //while the category input does not equal one of the correct category options, it continues to ask for input
            while(single_category != "Lab" or single_category != "Assignment" or single_category != "Project 1"  or single_category != "Project 2" or single_category != "Exam" ){
                std::cin >> single_category;
                std::cout <<  "Invalid category, please try again:";
            }
            grade_return = gradebook->get_category_total(single_category);
            //grade_return = get_total_grade();
            //TODO Ask what category the user would like to output; do error checking
            // Call get_category_grade using that category
        } else if (grade_choice == "e"){
            // Choice e
            // Prompts the user to enter an assignment
            std::string name_deliverable;
            std::cout << "Enter the name of an assignment:" << std::endl;
            std::cin >> name_deliverable;
            while (gradebook->get_grade_individual(name_deliverable) == -1) {
                std::cout << "There is not an assignment called " << name_deliverable <<  " try again!" << std::endl;
                std::cin >> name_deliverable;
            }

            // Calculates and outputs the grade
            int pct = gradebook->get_grade_individual(name_deliverable);
            if (pct == -2) {
                std::cout << name_deliverable << " has not been completed!" << std::endl;
            } else {
                std::string letter_grade = HelperFunctions::get_letter_grade(pct);
                std::cout << "Your grade for " << name_deliverable << " is a " << pct << "% or " << letter_grade << std::endl;
            }
        }
    } else if (gradebook_choice == "2") {

    } else if (gradebook_choice == "3") {
        // Makes a new assignment by writing to the gradebook file with certain criteria from the user
        std::string category;
        std::string name;
        int points_earned = -1;
        std::string is_completed;

        std::cout << "Enter the category of the assignment:" << std::endl;
        std::cin >> category;
        std::cout << "Enter the name of the assignment:" << std::endl;
        std::cin >> name;
        bool good_name = false;
        for (int i = 0; i < gradebook->get_title_assignment().size(); i++){
            if (name == gradebook->get_title_assignment()[i]) {
                std::cout << "There is already a deliverable with the title " << name << ". Try again.\n";
                good_name = true;
            }
        }
        while (!good_name){
            std::cin >> name;
            for (int i = 0; i < gradebook->get_title_assignment().size(); i++){
                if (name == gradebook->get_title_assignment()[i]) {
                    std::cout << "There is already a deliverable with the title " << name << ". Try Again.\n";
                    good_name = true;
                }
            }
        }
        std::cout << "Enter the number of points earned for the assignment:" << std::endl;
            std::cin >> points_earned;

        while(true){
            if(std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "Invalid input, try again.\n";
                std::cin>>points_earned;
            }
            if(!std::cin.fail()) break;
        }

        /*std::cout << "Has the assignment been completed or not? Enter y/n:" << std::endl;
        std::cin >> is_completed;
        // error checking to make sure yes or no is entered. completed or not completed is then applied accordingly
        while (is_complete != "y" || is_completed != "n") {
            std::cout << is_completed << " is not a valid entry. Enter y/n:" << std::endl;
            std::cin >> is_completed;
        }
        if (is_completed == "y") {
            is_completed = "completed";
        } else {
            is_completed = "not-completed";
        }
        std::cout << gradebook->new_assignment(category, name, points_earned, is_completed) << std::endl;*/

    } else if (gradebook_choice == "4") {
        //choice 4 allows editing the grade of a single assignment and completion status of an assignment
        std::string name_deliverable;
        std::cout << "Enter the name of an assignment:" << std::endl;
        std::cin >> name_deliverable;
        while (gradebook->get_grade_individual(name_deliverable) == -1) {
            std::cout << "There is not an assignment called " << name_deliverable <<  " try again!" << std::endl;
            std::cin >> name_deliverable;
        }

        //Menu allows choice between editing modes
        std::cout << "What would you like to edit about this deliverable?" << "\n";
        std::cout << "    a - Edit the Grade" << "\n";
        std::cout << "    b - Edit the completion status" << "\n";
        std::string choice;
        std::cin >> choice;
        bool good_input = false;
        if(choice == "a" or choice == "b") good_input = true;
        while (!good_input) {
            std::cout << "Invalid input, try again.\n";
            std::cin >> choice;
            if(choice == "a" or choice == "b") good_input = true;
        }

        if(choice == "a"){
            int index = -1;
            std::vector<std::string> categoryList = gradebook->get_category();
            std::vector<std::string> assignmentList = gradebook->get_title_assignment();
            for (int i = 0; i < categoryList.size(); i++) {
                if (assignmentList[i] == name_deliverable) {
                    index = i;
                    break;
                }
            }

            int total_points;
            if (categoryList[index] == "Assignment") total_points = 50;
            if (categoryList[index] == "Lab") total_points = 20;
            if (categoryList[index] == "Project1") total_points = 150;
            if (categoryList[index] == "Project2") total_points = 350;
            if (categoryList[index] == "Exam") total_points = 100;

            int new_grade;
            bool good_input = true;
            std::cout << "Enter the new grade for " << name_deliverable << "\nMaximum points on this deliverable is " << total_points << ".\n";
            std::cin >> new_grade;
            while(true){
                if(std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout << "Invalid input, try again.\n";
                    std::cin>>new_grade;
                }
                if(!std::cin.fail()) break;
            }
            while (new_grade <= 0 or new_grade > total_points){
                std::cout << "Invalid input, try again.\n";
                std::cin >> new_grade;
                while(true){
                    if(std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout << "Invalid input, try again.\n";
                        std::cin>>new_grade;
                    }
                    if(!std::cin.fail()) break;
                }
            }

            gradebook->edit_grade(name_deliverable, new_grade);
            std::cout << "Successfully updated grade.\n";

        } else if (choice == "b"){
            std::string completion_str;
            std::cout << "Should this deliverable be completed or not-completed?\nEnter 'completed' or 'not-completed'.\n";
            std::cin >> completion_str;
            bool good_input = false;
            if(completion_str != "completed" or completion_str != "not-completed") good_input = true;
            while (!good_input) {
                std::cout << "Invalid input, try again.\n";
                std::cin >> completion_str;
                if(completion_str != "completed" or completion_str != "not-completed") good_input = true;
            }

            bool completion;
            if (completion_str == "completed") completion = true;
            else completion = false;

            gradebook->edit_completion(name_deliverable, completion);
            std::cout << "Successfully updated completion.\n";
        }
    } else {
        std::string assignment_name;
        std::cout << "Enter the name of the assignment: " << std::endl;
        std::cin >> assignment_name;
        std::cout << gradebook->remove_assignment(assignment_name);
    }
}
