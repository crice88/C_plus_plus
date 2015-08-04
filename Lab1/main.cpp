//  Colin Rice CS66
//  main.cpp
//  Lab1
//  
//  Modify the provided source code to display 
//  Hello World and then prompt for the user's 
//  name. Reply by displaying Hello and the 
//  input user name. Compile and execute the 
//  project to insure that it executes correctly.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{    
    cout << "Hello, World!\n";
    cout << "Please enter your name: ";
    string first_name;
    cin >> first_name;   
    cout<<"Hello, "<< first_name <<"!\n";
    return 0;
}
