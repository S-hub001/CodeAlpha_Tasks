#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User 
{
public:
    string username;
    string password;

    User(const string& user, const string& pass) : username(user), password(pass) {}
};

class UserSystem 
{
public:
    void registerUser() 
    {
        string username, password;

        cout << "\n Enter username: ";
        cin >> username;
        cout << "\n Enter password: ";
        cin >> password;

        if (isUsernameTaken(username)) 
        {
            cout << "\n\n \033[1;32mUsername is already taken. \nTry again.\n\033[0m";
            return;
        }

        User newUser(username, password);
        saveUser(newUser);
        cout << "\n\n\t\t \033[1;32mRegistration successful!\n\033[0m";
    }

    void loginUser() 
    {
        string username, password;

        cout << "\n Enter username: ";
        cin >> username;
        cout << "\n Enter password: ";
        cin >> password;

        if (isValidUser(username, password)) 
        {
            cout << "\n\n\t\t \033[1;32mLogin successful!\n\033[0m";
        } 
        else 
        {
            cout << "\n \033[1;31mInvalid username or password. Try again.\n\033[0m";
        }
    }

private:
    bool isUsernameTaken(const string& username) 
    {
        ifstream userFile(username + ".txt");
        return userFile.good();
    }

    void saveUser(const User& user) 
    {
        ofstream userFile(user.username + ".txt");
        userFile << user.username << endl;
        userFile << user.password << endl;
        userFile.close();
    }

    bool isValidUser(const string& username, const string& password) 
    {
        ifstream userFile(username + ".txt");
        if (!userFile) 
        {
            return false;
        }

        string storedUsername, storedPassword;
        getline(userFile, storedUsername);
        getline(userFile, storedPassword);
        userFile.close();

        return (storedUsername == username && storedPassword == password);
    }
};

int main() 
{
    UserSystem userSystem;
    int choice;
    
    cout << "\n\n \t\t\t\033[1;4;36mLOGIN/REGISTRATION SYSTEM !\033[0m";
    
    do 
    {
        cout << "\n\n \tWhat do you want to perform ?\n \033[1;35m\t1. Register\n \t2. Login\n \t3. Exit\033[0m\n Choose an option: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                userSystem.registerUser();
                break;
            case 2:
                userSystem.loginUser();
                break;
            case 3:
                cout << "\n\n \t\t\033[1;31mExiting...\033[0m\n";
                break;
            default:
                cout << "\n\033[1;31m Invalid choice. Try again.\033[0m\n";
        }
    } 
    while (choice != 3);

    return 0;
}

