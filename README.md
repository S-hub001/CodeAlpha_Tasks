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


TASK#3::
Explanation:
Classes:
Transaction:
   Represents a banking transaction.
   Attributes: type (e.g., Deposit, Withdrawal), amount, and date.
Account:
   Represents a bank account.
  Attributes: account number, balance, and a list of transactions.
  Methods:
   deposit: Adds money to the account.
   withdraw: Withdraws money from the account (if sufficient funds).
   transfer: Transfers money to another account.
   displayAccountInfo: Displays account details and recent transactions.
   addTransaction: Adds a transaction to the account's transaction list.
Customer:
   Represents a bank customer.
  Attributes: name, customer ID, and a list of accounts.
  Methods:
   addAccount: Adds a new account to the customer.
   displayCustomerInfo: Displays customer details and account information.
   getAccount: Retrieves an account by its number.
BankingService:
   Manages customers and their accounts.
  Attributes: a list of customers.
  Methods:
   createCustomer: Creates a new customer.
   getCustomer: Retrieves a customer by their ID.
   createAccount: Creates a new account for an existing customer.
Main Function:
  The main function provides a menu-driven interface for interacting with the banking system. Users can:
    Create Customer: Adds a new customer by entering a name and ID.
    Create Account: Adds a new account to an existing customer by entering the customer ID, account number, and initial deposit.
    Deposit: Deposits money into an account by entering customer ID, account number, amount, and date.
    Withdraw: Withdraws money from an account by entering customer ID, account number, amount, and date.
    Transfer: Transfers money from one account to another by entering the necessary details.
    View Account Info: Displays account information and recent transactions for a specified customer.
    Exit: Exits the program.
