#include <iostream>
#include <fstream> //so we can write and read out files
#include <string>



bool IsLoggedIn() { // to verify if we are logged in or not
    string username, password, un, pw; //these are the comparison strings

    std::cout << "Please Enter your username: "; std::cin >> username;
    std::cout << "Please Enter your pasword "; std::cin >> password;
    // read variable from stream  // read data from inside folder 
    ifstream read("data\\" + username + ".txt");
    // read the variable inside "un" which is username
    getline(read, un);
    // read the password next
    getline(read, pw);
    // checks if the username and password match
    if (un == username && pw == password) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    int choice; //register or log in
    // asks if you would to register or not, takes user input
    std::cout << "1: Would you like to register?\n2: Login\nYour choice: " std::cin >> choice;

    if (choice == 1) {
        string username, password; 
        // user picks a username and a password
        std::cout << "Select a username: " std::cin >> username;
        std::cout << "Select a password: " std::cin >> password;
        // ofstream creates a file with username 
        ofstream file;
        file.open("data\\" + username + ".txt");
        // we write to the file the username while creating a new line  storing the password
        file << username << endl << password;
        // closes the file
        file.close();
        // returns to main which lets the user restart the registration process or log in
        main();
    }
    else if (choice == 2) {
        bool status = IsLoggedIn(); // create a bool name status and redirects to logged in bool on top

        if (!status) {
            std::cout << "False Login!" << endl;
            system("PAUSE");
            return 0;
        }
        else {
            std::cout << "Successfully logged in!" << endl;
            system("PAUSE");
            return 1;
        }
    }
}

