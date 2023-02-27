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
        } else if (this->categoryList[index] == "Project1") {
            total_points = 150;
        } else if (this->categoryList[index] == "Project2") {
            total_points = 350;
        } else if (this->categoryList[index] == "Exam") {
            total_points = 100;
        }

        // Calculates the percentage
        int pct = std::round((float(this->earned_points[index]) / float(total_points)) * 100);
        return pct;
    }

}




//gets all grades from specific category selected by user and returns the overall
//point sum for that category
float Gradebook::get_category_total(std::string category){
    float sumPoints = 0;
    if(category == "Lab"){
        //going through category list and storing indices that match the category entered
        //if category matches the user input, it adds the points at current index to
        //the labGrades vector
        for(int i = 0; i < this->categoryList.size(); i++){
            if(this->categoryList[i] == category and completed[i] == true){ //only pushes back if completed
                this->labGrades.push_back(this->earned_points[i]);
            }
        }
        //going through labGrades vector and summing values for particular category
        for(int j = 0; j < this->labGrades.size(); j++){
            sumPoints += this->labGrades[j];
        }
        //error checking if sumPoints is 0 it means there is no grade for this category
        if(sumPoints == 0){
            std::cout <<  "No lab grades entered." << std::endl;
        }else{
            //calculating grade of category
            sumPoints = sumPoints/(labGrades.size()*20);
            sumPoints = std::round((float(sumPoints) * 100));
            std::cout << "Your total lab grade is: " << sumPoints << "%" <<  std::endl;
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
        //error checking if sumPoints is 0 it means there is no grade for this category
        if(sumPoints == 0){
            std::cout <<  "No assignment grades entered." << std::endl;
        }else{
            //calculating grade of category
            sumPoints = sumPoints/(assignmentGrades.size()*50);
            sumPoints = std::round((float(sumPoints) * 100));
            std::cout << "Your total assignment grade is: " << sumPoints << "%" <<  std::endl;
        }


        //clearing the assignmentGrades vector for next category input use
        this->assignmentGrades.clear();

        //returning the total points earned for the category
        return sumPoints;
    }
    else if(category == "Project1"){
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
        //error checking if sumPoints is 0 it means there is no grade for this category
        if(sumPoints == 0){
            std::cout <<  "No Project 1 grade entered." << std::endl;
        }else{
            //calculating grade of category
            sumPoints = sumPoints/(proj1Grades.size()*150);
            sumPoints = std::round((float(sumPoints) * 100));
            std::cout << "Your total Project 1 grade is: " << sumPoints << "%" <<  std::endl;
        }

        //clearing the proj1Grades vector for next category input use
        this->proj1Grades.clear();

        //returning the total points earned for the category
        return sumPoints;
    }
    else if(category == "Project2"){
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
        //error checking if sumPoints is 0 it means there is no grade for this category
        if(sumPoints == 0){
            std::cout <<  "No Project 2 grade entered." << std::endl;
        }else{
            //calculating grade of category
            sumPoints = sumPoints/(proj2Grades.size()*350);
            sumPoints = std::round((float(sumPoints) * 100));
            std::cout << "Your total Project 2 grade is: " << sumPoints << "%" <<  std::endl;
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
        //error checking if sumPoints is 0 it means there is no grade for this category
        if(sumPoints == 0){
            std::cout <<  "No Exam grade entered." << std::endl;
        }else{
            //calculating grade of category
            sumPoints = sumPoints/(examGrades.size()*100);
            sumPoints = std::round((float(sumPoints) * 100));
            std::cout << "Your total Exam grade is: " << sumPoints << "%" << std::endl;
        }

        //clearing the labGrades vector for next category input use
        this->examGrades.clear();

        //returning the total points earned for the category
        return sumPoints;
    }
    //resetting sumPoints back to 0
    return 0;
}

//function gets the total grade of all completed deliverables
float Gradebook::get_total_grade(){
    float points_earned = 0;
    float total_possible_points = 0;
    float grade = 0;

    //iterating through categoryList and if deliverable is completed it adds
    //those points to points_earned and adds the maximum points possible
    //for that deliverable to total_possible_points
    for(int i = 0; i < this->categoryList.size(); i++){
        if(completed[i] == true){
            points_earned += this->earned_points[i];
            if(this->categoryList[i] == "Lab"){
                total_possible_points += 20;
            }
            if(this->categoryList[i] == "Assignment"){
                total_possible_points += 50;
            }
            if(this->categoryList[i] == "Project1"){
                total_possible_points += 150;
            }
            if(this->categoryList[i] == "Project2"){
                total_possible_points += 350;
            }
            if(this->categoryList[i] == "Exam"){
                total_possible_points += 100;
            }
        }
    }
    //calculating percent grade rounded
    grade = std::round((float(points_earned) / float(total_possible_points)) * 100);

    return grade;
}


std::string Gradebook::new_assignment(std::string category, std::string name, int points_earned, std::string is_completed) {
    // open the gradebook file in append mode
    std::ofstream gradebook_file;

    // write a new line to the file with all the information from the user
    // return that the assignment has been created
    gradebook_file.open("Grades/" + file_name, std::fstream::app);
    gradebook_file << "\n" + category + " " + name + " " + std::to_string(points_earned) + " " + is_completed;

    // add the new assignment to the vectors
    this->categoryList.push_back(category);
    this->title_assignment.push_back(name);
    this->earned_points.push_back(points_earned);
    if (is_completed == "completed") {
        this->completed.push_back(true);
    } else {
        this->completed.push_back(false);
    }

    return "Assignment \"" + name + "\" has been assignment created";
}


void Gradebook::edit_grade(std::string name_assignment, int new_earned_points) {
    int index = -1;
    for (int i = 0; i < this->title_assignment.size(); i++) {
        if (this->title_assignment[i] == name_assignment) {
            index = i;
            break;
        }
    }

    this->earned_points[index] = new_earned_points;

    push_changes();

}


void Gradebook::edit_completion(std::string name_assignment, bool new_completion){
    int index = -1;
    for (int i = 0; i < this->title_assignment.size(); i++) {
        if (this->title_assignment[i] == name_assignment) {
            index = i;
            break;
        }
    }

    this->completed[index] = new_completion;

    push_changes();

}


void Gradebook::push_changes() {
    std::string out_file = this->name + "\n";
    for (int i = 0; i < this->title_assignment.size(); i++){
        std::string temp_category = this->categoryList[i];
        std::string temp_title = this->title_assignment[i];
        std::string temp_earned = std::to_string(this->earned_points[i]);
        std::string temp_complete;
        if (this->completed[i]) temp_complete = "completed";
        else temp_complete = "not-completed";
        out_file+=(temp_category + " " + temp_title + " " + temp_earned + " " + temp_complete + "\n");
    }
    std::ofstream myfile;
    myfile.open("Grades/" + this->file_name);
    myfile << out_file;
    myfile.close();
    return;
}


bool Gradebook::assignment_exists(std::string assignment_name) {
    for (const auto & i : title_assignment) {
        if (i == assignment_name) {
            return true;
        }
    }
    return false;
}


// returns 0 for an assignment successfully removed and -1 if the assignment doesn't exist
std::string Gradebook::remove_assignment(std::string remove_name) {
    if (assignment_exists(remove_name)) {
        // a new temporary file to hold all the lines
        std::ofstream temp_file;
        temp_file.open("Grades/temp_gradebook.txt");

        temp_file << this->name + "\n";

        // write the line from the vectors of the current assignments unless the assignment is the one we want to remove
        for (int i = 0; i < title_assignment.size(); i++) {
            if (title_assignment[i] != remove_name) {
                std::string temp_completed = "completed";
                if (!completed[i]) {
                    temp_completed = "not-completed";
                }
                temp_file << categoryList[i] + " " + title_assignment[i] + " " + std::to_string(earned_points[i]) + " " + temp_completed + "\n";
            }
            else {
                // remove the matching assignment to delete from the vectors
                this->categoryList.erase(categoryList.begin()+i);
                this->title_assignment.erase(title_assignment.begin()+i);
                this->earned_points.erase(earned_points.begin()+i);
                this->earned_points.erase(earned_points.begin()+i);
            }
        }
        temp_file.close();
        std::remove(("Grades/" + file_name).c_str());
        std::rename("Grades/temp_gradebook.txt", ("Grades/" + file_name).c_str());
        return "Assignment \"" + remove_name + "\" has been removed";
    } else {
        return "Assignment \"" + remove_name + "\" does not exist";
    }
}