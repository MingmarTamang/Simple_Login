#include <iostream>
#include <string>
#include <vector>
using namespace std;
class User
{
private:
    string username, password;

public:
    User(string name, string pass)
    {
        username = name;
        password = pass;
    }
    string getUsername()
    {
        return username;
    }
    string getPassword()
    {
        return password;
    }
};

class UserManagement
{
private:
    vector<User> users; // create object of vector
public:
    void registerUser();
    bool loginUser(string name, string pass);
    void showUser();
    void searchUser(string username);
    void deleteUser(string username);
};

int main()
{
    string username, password;
    UserManagement usermanage;

    int op;
    char choice;
    do
    {
        cout << "\t\t1. Register User " << endl;
        cout << "\t\t2. Login " << endl;
        cout << "\t\t3. Show User list " << endl;
        cout << "\t\t4. Search User " << endl;
        cout << "\t\t5. Delete User " << endl;
        cout << "\t\t6. Exit " << endl;
        cout << "\t\tEnter user Choice ";
        cin >> op;
        switch (op)
        {
        case 1:
        {
            usermanage.registerUser();
            break;
        }
        case 2:
        {
            string username, password;
            cout << "\t\tEnter User: ";
            cin >> username;
            cout << "\t\tEnter Password: ";
            cin >> password;
            usermanage.loginUser(username, password);
            break;
        }
        case 3:
        {
            usermanage.showUser();
            break;
        }
        case 4:
        {
            string username;
            cout << "\t\tEnter User name: ";
            cin >> username;
            usermanage.searchUser(username);
            break;
        }
        case 5:{
            string username;
            cout<<"\t\tEnter Username : ";
            cin>>username;
            usermanage.deleteUser(username);
        }
        case 6:{
            exit(1);
        }
        }
        cout << "\t\tDo you want to continue [Yes / No]: ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void UserManagement ::registerUser()
{
    string username, password;
    cout << "\t\tEnter User Name: ";
    cin >> username;
    cout << "\t\tEnter Password: ";
    cin >> password;

    User newUser(username, password);
    users.push_back(newUser);

    cout << "\t\tUser register successfully----" << endl;
}

bool UserManagement ::loginUser(string name, string pass)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getUsername() == name && users[i].getPassword() == pass)
        {
            cout << "\t\tLogin Successfully----" << endl;
            return 1;
        }
    }
    cout << "\t\tInvalid User Name or Password----" << endl;
    return 0;
}
void UserManagement ::showUser()
{
    cout << "\t\t----User List----" << endl;
    for (int i = 0; i < users.size(); i++)
    {
        cout << "\t\t" << users[i].getUsername() << endl;
    }
}
void UserManagement ::searchUser(string username)
{
    cout << "\t\t----User list----" << endl;
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getUsername() == username)
        {
            cout << "\t\tUser found " << endl;
        }
    }
}
void UserManagement :: deleteUser(string username){
    for(int i = 0; i<users.size(); i++){
        if(users[i].getUsername()==username){
            users.erase(users.begin()+1);
            cout<<"\t\tUser Remove Successfully";
        }
    }
}