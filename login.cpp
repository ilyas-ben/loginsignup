#include <iostream>
#include <fstream> // Ajoutez cette ligne pour utiliser fstream

using namespace std;

class temp
{
    string userName, email, password;

    string inputedUserName, inputedPassword, inputedEmail;
    fstream file;

public:
    void login();
    void signUP();
    void forgot();
}obj;

int main(int argc, char const *argv[])
{
    char choice;
    cout << "\n1- Login";
    cout << "\n2- Sign-Up";
    cout << "\n3- Forgot Password";
    cout << "\n4- Exit";
    cout << "\nEnter Your Choice :: ";
    cin >> choice;

    switch (choice)
    {
    case '1':
        obj.login();
        break;
    case '2':
        obj.signUP();
        break;
    case '3':
        obj.forgot();
        break;
    case '4':
        return 0;
        break;
    default:
        cerr << "Invalid seleciont !!";
        main(argc, argv);
        break;
    }
    return 0;
}

void temp ::signUP()
{
    cout << "Enter your username" << endl;
    getline(cin, userName);
    cin.ignore();
    cout << "Enter your email address ::" << endl;
    getline(cin, email);
    cin.ignore();
    cout << "Enter your password :: " << endl;
    getline(cin, password);
    
    
    file.open("loginData", ios ::out | ios ::app);
    file << userName << "*" << email << "*" << password << endl;
    file.close();
}

void temp ::login()
{
    string searchName, searchPass;

    cout << "---------LOGIN---" << endl;
    cout << "Enter your user name ::" << endl;
    getline(cin, searchName);
    cin.ignore();
    cout << "Enter your password ::" << endl;
    getline(cin, searchPass);

    file.open("loginData", ios ::in);
    getline(file, userName, '*');
    getline(file, email, '*');
    getline(file, password, '\n');
    while (!file.eof())
    {
        if (userName == searchName)
        {
            if (password == searchPass)
            {
                cout << "\nUser connected";
                cout << "\nUsername ::" << userName << endl;
                cout << "\nEmail ::" << email << endl;
            }
            else
            {
                cerr << "Password is Incorrect !!";
            }
        }
        getline(file, userName, '*');
        getline(file, email, '*');
        getline(file, password, '\n');
    }

    file.close();
}

void temp ::forgot()
{
    cout << "Enter your user name ::" << endl;
    getline(cin, userName);
    cout << "Enter your email address ::" << endl;
    getline(cin, email, '*');

    file.open("loginData", ios ::in);
    getline(file, userName, '*');
    getline(file, email, '*');
    getline(file, password, '\n');
    while ((!file.eof()))
    {
        if (userName == inputedUserName)
        {
            cout << "\nPassword for" << userName << endl;
        }
        else
        {
            cerr << "Not found ...\n";
        }
    }
    file.close();
}
