TASK#1::
Explanation:
Course Class: 
   Holds details about each course.
Student Class: Uses a dynamic array (Course* courses) to store courses.
   addCourse function to add a course to the array.
   displayGrades to print all course details.
   calculateGPA computes the GPA.
   calculateCGPA computes the CGPA (assuming only one semester for simplicity).
Main Function: 
   Prompts user for course details, populates the student object, and displays the GPA and CGPA.


TASK#2::
Explanation:
User Class: 
   Holds user credentials (username and password).
UserSystem Class:
   registerUser(): Prompts the user for a username and password, checks if the username is already taken, and saves the user details to a file if registration is successful.
   loginUser(): Prompts the user for login credentials and validates them against stored data.
   isUsernameTaken(): Checks if a file for the given username already exists.
   saveUser(): Creates a file with the username and saves the user’s credentials.
   isValidUser(): Validates the entered credentials by reading from the user’s file.
Main Function:
   Provides a menu for the user to register, login, or exit the program.
   Uses a loop to keep the program running until the user chooses to exit.
