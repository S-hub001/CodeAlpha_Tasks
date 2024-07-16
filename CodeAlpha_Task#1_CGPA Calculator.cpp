#include <iostream>
#include <iomanip>  // for std::setprecision

using namespace std;

class Course 
{
public:
    string name;
    int credits;
    double grade;

    Course() : name(""), credits(0), grade(0.0) {}
};

class Student 
{
private:
    Course* courses;
    int courseCount;
    double totalGradePoints;
    int totalCredits;
    int semesterCount;
    double totalGPA;

public:
    Student() 
    {
        courseCount = 0;
        courses = nullptr;
        totalGradePoints = 0.0;
        totalCredits = 0;
        semesterCount = 0;
        totalGPA = 0.0;
    }

    ~Student() 
    {
        delete[] courses;
    }

    void addSemester(int numberOfCourses) 
    {
        delete[] courses; // Delete previous semester's courses
        courseCount = numberOfCourses;
        courses = new Course[courseCount];
        double semesterGradePoints = 0.0;
        int semesterCredits = 0;

        for (int i = 0; i < numberOfCourses; ++i) 
        {
            string name;
            int credits;
            double grade;

            cin.ignore(); // Clear the newline character left in the buffer

            cout << "\n\n\t\t\033[1;4;35mEnter details for course # " << i + 1 << "\033[0m\n";
            cout << "\n \033[1;36mCourse Name : \033[0m";
            getline(cin, name);
            cout << "\n \033[1;33mCredits : \033[0m";
            cin >> credits;
            cout << "\n \033[1;32mGrade : \033[0m";
            cin >> grade;

            courses[i].name = name;
            courses[i].credits = credits;
            courses[i].grade = grade;

            semesterGradePoints += grade * credits;
            semesterCredits += credits;
        }

        totalGradePoints += semesterGradePoints;
        totalCredits += semesterCredits;
        ++semesterCount;
        totalGPA += semesterGradePoints / semesterCredits;
    }

    void displayGrades() 
    {
        cout << "\n\n \033[1;33mCourse Grades :";
        for (int i = 0; i < courseCount; ++i) 
        {
            cout << "\n\n \033[1;36mCourse : \033[0m" << courses[i].name 
                 << ",  \033[1;36mCredits : \033[0m" << courses[i].credits 
                 << ",  \033[1;36mGrade : \033[0m" << courses[i].grade << '\n';
        }
    }

    double calculateGPA() 
    {
        if (totalCredits == 0) return 0.0;
        return totalGradePoints / totalCredits;
    }

    double calculateCGPA() 
    {
        if (semesterCount == 0) return 0.0;
        return totalGPA / semesterCount;
    }
};

int main() 
{
    Student student;
    char choice;
    
    cout << "\n\n \t\t\t\033[1;4;36m CGPA CALCULATOR !\033[0m";
    
    do 
    {
        int numberOfCourses;

        cout << "\n\n\033[1;31m Enter the number of courses for this semester: \033[0m";
        cin >> numberOfCourses;

        student.addSemester(numberOfCourses);

        student.displayGrades();
        cout << fixed << setprecision(2);
        cout << "\n\n \t\t\033[1;34m GPA for this semester: \033[0m" << student.calculateGPA() << '\n';

        cout << "\n\n\033[1;32m Do you want to add another semester's courses? (y/n): \033[0m";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << fixed << setprecision(2);
    cout << "\n\n \t\t\033[1;34m CGPA: \033[0m" << student.calculateCGPA() << '\n';

    cout << endl << endl;
    return 0;
}

