# CS212-Review-Project
**Ryan Shilling, Ryan Brooks, Jake Dansereau, Brandt Ogden**



## Summary 
Courses that have a large quantity of assignments, projects, and/or labs can 
make it difficult for students to view their grades for each. Additionally, 
it can be difficult to calculate the weight that each of these deliverables
count towards in finding one's overall grade for the course. Hence, the
goal of this project is to provide a way for students to be able to access 
various aspects of their grades for CS 212. Such options include getting
one's overall grade for the course, listing the grades of a student's
deliverables, and being able to add, edit, and/or remove assignments. 
Getting one's grades is imperative to seeing where a student stands in the 
course. Listing the deliverables will allow students to view specific 
assignments to give them a more detailed view of their course progress.
Being able to add, edit, and remove assigments will allow students to 
manipulate their points and completion status. This serves several purposes, 
including being able to modify points should their be any changes made to 
how grades are calculated for different categories, as well as being able 
to mark deliverables as completed as the course progresses.  Overall, these 
options will allow users to not only receive their general grades for the course, 
but to be able to manipulate grade information, hence allowing this program 
to be applicable throughout a student's progress in a course. 



## Planning 
In our first planning session we outlined the different functions that we were 
going to need in our class along with the different private variables we would 
need, and started to think about how these functions would be working.
<img src="https://user-images.githubusercontent.com/123508751/221453881-786c4854-2ade-4c52-afe7-09f3017ce446.jpg"  width="400" height="400">
During this planning session we divided who would do the different functions.
Brandt worked on the constructor for the gradebook which took input from a file
and put it into the private vectors associated with the GradeBook class. He also 
worked on the get_individual_grade function along with the corresponding
options in main. Jake worked on the get_category_grade and get_total_grade 
functions along with the corresponding options in main. Ryan Shilling worked 
on the edit functions that allow the user to edit different grades and completion
status along with the corresponding options in main. Ryan Brooks wrote the 
outline for main (you can see this in the comments at the top of main.cpp) and 
did most of the miscellaneous work on it that didn't fit into anyone else's role,
including the ability to remove an assignment.

## Compilation Instructions
To be completed

## Runtime Instructions 
Upon running the program, the user will be presented with two options:

  Type 1 - Open the gradebook of one us
       2 - Quit
     
Entering option 2 will terminate the program with exit code 0. Entering option 
1 will present the user with the mock grade text files of the four 
members of our group. The menu option will look as follows:

Which person's gradebook would you like to open?
    1 - Ryan Brooks
    2 - Ryan Shilling
    3 - Jake Dansereau
    4 - Brandt Ogden

Entering an option 1-4 prompts the 'main menu' for selecting different viewing 
options for grades:

What would you like to do with the gradebook?
    1 - Get your grade
    2 - List the current deliverables
    3 - Create a new assignment
    4 - Edit an existing assignment
    5 - Remove an assignment
    
##*Option 1*
Selecting option 1 will allow the user to get their overall grade for the course.
They can select various viewing options for their grade as follows:

What grade would you like?
    a - Your overall course grade
    b - Your overall course grade and the grade of each category
    c - Your overall course grade, grade of each category, and all the grades of the different deliverables
    d - Your grade for one specific category
    e - Your grade for a specific deliverable
    
Selecting option 'a' prints the user's overall course grade numerically and the
corresponding alphabetical grade.  Selecting option 'b' prints the former along
with the grade of each specific category's grade. Selecting option 'c' prints the
former two along with the specific grade of each of the completed assignments from
the text file.  Selecting option 'd' then prompts the user to enter a specific 
category as follows:

Enter a category you want to see the grade for:
(enter 'Lab', 'Assignment', 'Project 1', Project 2', or 'Exam')

Entering one of these assignments will output the grade for that specific category.
Note that the user must enter one of the exact categories from the course, otherwise
they will again be prompted to enter a valid input. Lastly, selecting option 'e' 
allows the user to enter a specific deliverable and receive the grade for it as follows:

Enter the name of an assignment:

Note that the user must enter one of the exact categories from the course, otherwise
they will again be prompted to enter a valid input. After reaching the end of either 
of these options a-e for option 1, they will be prompted with an option to continue
in the gradebook or to quit:

What would you like to do?
Type 1 - Open the gradebook of one us
     2 - Quit

##*Option 2*
Selecting option 2 allows the user to get all of their current deliverables that are 
in the selected text file. After viewing the deliveries, the user is promped with 
the option to once again continue or quit, as seen above. 

##*Option 3*
Selecting option 3 allows the user to enter a specific category in order to create
a new assignment. 
##*Option 4*

##*Option 5*

     


During runtime different options will be shown to allow you to do different things 
with the grades in the text file. It will explain exactly what your options are and
what you need to type. All the inputs are "idiot-proofed" and will not allow you
to continue until you give a valid input. Different examples of inputs are shown in 
the next section.

## Sample Runs

