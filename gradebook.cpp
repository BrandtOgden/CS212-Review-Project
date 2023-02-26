#include "gradebook.h"
#include <vector> 
// Implement functions as defined in gradebook.h
Gradebook::Gradebook(std::string file_name) {
    // ALL FILES WE WANT TO USE HAVE TO BE IN THE GRADES FOLDER
    // WILL WANT TO MENTION THIS IS THE VIDEO
    // First line should be the name whose grades are in the file
    // The next lines should be in the format,
    // Category Title EarnedPoints IsCompleted

    this->file_name = file_name;

    // Opens the file
    std::ifstream infile("Grades/" + file_name);

    // Gets the name from the first line and store it in the private variable name
    std::getline(infile, this->name);

    // Gets all the assignments from the rest of the text file
    std::string line;
    // Loop until end of file
    while (std::getline(infile, line)) {
        // Tokenize each line to get category title etc...
        std::stringstream line_stream(line);
        // Variables to temporarily hold the tokens
        std::string temp_category;
        std::string temp_title_assignment;
        int temp_earned_points;
        // Needs to be a string so we can get input from the text file
        std::string temp_completed;
        // Loop until there are no more tokens in line_stream
        while (line_stream.good()) {
            line_stream >> temp_category;
            line_stream >> temp_title_assignment;
            line_stream >> temp_earned_points;
            line_stream >> temp_completed;

            // Add them to their respective class variables
            this->categoryList.push_back(temp_category);
            this->title_assignment.push_back(temp_title_assignment);
            this->earned_points.push_back(temp_earned_points);
            if (temp_completed == "completed") {
                this->completed.push_back(true);
            } else {
                this->completed.push_back(false);
            }
        }
    }
}

// Loop through title_assignment and output all the names so the user knows what
// assignments there are
void Gradebook::list_assignments() {
    for (int i = 0; i < this->title_assignment.size(); i++) {
        std::cout << this->title_assignment[i] << std::endl;
    }
}

// Returns the percentage of the grade of the assignment specified
// Returns -1 if there is not an assignment called name_assignment
// Returns -2 if the assignment has not been completed yet
int Gradebook::get_grade_individual(std::string name_deliverable) {
    // variable to hold the value of total points
    int total_points = -1;
    // Variable to hold the index of the assignment we are dealing with
    int index = -1;
    for (int i = 0; i < this->title_assignment.size(); i++) {
        if (this->title_assignment[i] == name_deliverable) {
            index = i;
            break;
        }
    }


    // Checks whether the name of assignment has been found
    if (index == -1) {
        return -1;
    } else if (!this->completed[index]) {
        return -2;
    } else {
        // Check for what the category is because that will change the total points
        if (this->categoryList[index] == "Lab") {
            total_points = 20;
        } else if (this->categoryList[index] == "Assignment") {
            total_points = 50;
        } else if (this->categoryList[index] == "Project 1") {
            total_points = 150;
        } else if (this->categoryList[index] == "Project 2") {
            total_points = 350;
        } else if (this->categoryList[index] == "Exam") {
            total_points = 100;
        }

        // Calculates the percentage
        int pct = std::round((float(this->earned_points[index]) / float(total_points)) * 100);
        return pct;
    }

}

std::string Gradebook::new_assignment(std::string category, std::string name, int points_earned, std::string is_completed) {
    // open the gradebook file in append mode
    std::ofstream gradebook_file;

    // write a new line to the file with all the information from the user
    // return that the assignment has been created
    gradebook_file.open("Grades/" + file_name, std::fstream::app);
    gradebook_file << "\n" + category + " " + name + " " + std::to_string(points_earned) + " " + is_completed;

    return "New assignment created";
}



//gets all grades from specific category selected by user and returns the overall
//point sum for that category
//TODO Fix math for getting sum
float Gradebook::get_category_total(std::string category){
    std::vector<int>labGrades;
    float sumPoints = 0;
    if(category == "Lab"){
        //going through category list and storing indices that match the category entered
        //if category matches the user input, it adds the points at current index to
        //the labGrades vector
        for(int i = 0; i < this->categoryList.size(); i++){
            if(this->categoryList[i] == category and completed[i] == true){ //only pushes back if completed
                labGrades.push_back(this->earned_points[i]);
            }
        }
        //going through labGrades vector and summing values for particular category
        for(int j = 0; j < labGrades.size(); j++){
            sumPoints += labGrades[j]; 
        }
        //clearing the labGrades vector for next category input use
        labGrades.clear();

        //returning the total points earned for the category
        return sumPoints; 
    }
    else if(category == "Assignment"){
          //going through category list and storing indices that match the category entered
        //if category matches the user input, it adds the points at current index to
        //the assignmentGrades vector
        for(int i = 0; i < this->categoryList.size(); i++){
            if(this->categoryList[i] == category and completed[i] == true){
                this->assignmentGrades.push_back(this->earned_points[i]);
            }
        }
        //going through assignmentGrades vector and summing values for particular category
        for(int j = 0; j < this->assignmentGrades.size(); j++){
            sumPoints += this->assignmentGrades[j];
        }
        //clearing the assignmentGrades vector for next category input use
        this->assignmentGrades.clear();

        //returning the total points earned for the category
        return sumPoints;
    }
    else if(category == "Project 1"){
          //going through category list and storing indices that match the category entered
        //if category matches the user input, it adds the points at current index to
        //the proj1Grades vector
        for(int i = 0; i < this->categoryList.size(); i++){
            if(this->categoryList[i] == category and completed[i] == true){
                this->proj1Grades.push_back(this->earned_points[i]);
            }
        }
        //going through proj1Grades vector and summing values for particular category
        for(int j = 0; j < this->proj1Grades.size(); j++){
            sumPoints += this->proj1Grades[j];
        }
        //clearing the proj1Grades vector for next category input use
        this->proj1Grades.clear();

        //returning the total points earned for the category
        return sumPoints;
    }
    else if(category == "Project 2"){
        //going through category list and storing indices that match the category entered
        //if category matches the user input, it adds the points at current index to
        //the proj1Grades vector
        for(int i = 0; i < this->categoryList.size(); i++){
            if(this->categoryList[i] == category and completed[i] == true){
                this->proj2Grades.push_back(this->earned_points[i]);
            }
        }
        //going through proj2Grades vector and summing values for particular category
        for(int j = 0; j < this->proj2Grades.size(); j++){
            sumPoints += this->proj2Grades[j];
        }
        //clearing the proj2Grades vector for next category input use
        this->proj2Grades.clear();

        //returning the total points earned for the category
        return sumPoints;
    }
    else if(category == "Exam"){
          //going through category list and storing indices that match the category entered
        //if category matches the user input, it adds the points at current index to
        //the examGrades vector
        for(int i = 0; i < this->categoryList.size(); i++){
            if(this->categoryList[i] == category and completed[i] == true){
                this->examGrades.push_back(this->earned_points[i]);
            }
        }
        //going through examGrades vector and summing values for particular category
        for(int j = 0; j < this->examGrades.size(); j++){
            sumPoints += this->examGrades[j];
        }
        //clearing the labGrades vector for next category input use
        this->examGrades.clear();

        //returning the total points earned for the category
        return sumPoints;
    }else{
        std::cout << "Error"; //TEMPORARY CONDITIONAL 
    }
    //resetting sumPoints back to 0
    sumPoints = 0; 
    return 0;
}

//TODO Fix total grade math
float Gradebook::get_total_grade(){
    float total_points;
    //calls get_category_total function for each assignment type to get the sum grade of each category
    float lab_total = get_category_total("Lab");
    float assign_total = get_category_total("Assignment");
    float proj1_total = get_category_total("Project 1");
    float proj2_total = get_category_total("Project 2");
    float exam_total = get_category_total("Exam");

    //adding all categories to get total and dividing by 10 to get grade within 0-100 scale to check for letter grade
    total_points = lab_total + assign_total + proj1_total + proj2_total + exam_total;
    total_points = total_points;   //TODO how to get weight if not all assignments are completed

    return total_points;
}


