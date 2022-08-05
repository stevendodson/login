#include <iostream>
#include <unordered_map>

using namespace std;

int getNum();

void reg();
int login();
void adduser(string, string);

unordered_map<string, string> umap;
   
int main() {
    string input;
    do {
        cout << "1: Register" << endl << "2: Login" << endl << "3: Quit" << endl;
        cin >> input;
        if (input == "1") {
            reg();
        }
        else if (input == "2") {
            return login();
        }
    } while(input != "3");
   
}

void reg() {
    string username;
    string password;
   
    string input;
    do {
        cout << endl << "Register" << endl << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
   
        cout << endl << "Username: " << username << endl << "Password: " << password << endl << "Is this correct? y/n" << endl;
        cin >> input;
    } while (tolower(input[0]) != 'y');
    adduser(username, password);
}

void adduser(string username, string password) {
    umap[username] = password;
}

int login() {
    cout << endl << "Login" << endl << endl;
    string username;
    string password;
   
    do {
        cout << "Enter Username: ";
   
        cin >> username;
   
        if (umap.find(username) == umap.end()) {
            cout << "User not found, try again." << endl;
        }
    } while (umap.find(username)== umap.end());
   
   
    cout << endl << "Enter Password: ";
    string word;
    cin >> word;
    if(word == umap.find(username)->second) {
        cout << "Correct";
        return 0;
    }
    else {
        cout << "Incorrect";
        return 1;
    }
   
    return 0;
}

int getNum() {
    int num;
    cin >> num;
    return num;
}
