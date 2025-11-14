// Create a class Book to manage book records in a library. The class should have
// the following private data members: bookID (int). title (string). price (float)
// Implement the following
// a) Default constructor to initialize default values.
// b) Parameterized constructor to initialize with user-provided values.
// c) Destructor to display a message when the object is destroyed.

#include <iostream>
using namespace std;

class Book {
private:
    int bookID;
    string title;
    float price;

public:
    // a) Default constructor
    Book() {
        bookID = 0;
        title = "Untitled";
        price = 0.0;
        cout << "Default constructor called.\n";
    }

    // b) Parameterized constructor
    Book(int b, string t, float p) {
        bookID = b;
        title = t;
        price = p;
        cout << "Parameterized constructor called.\n";
    }

    // Function to display book info
    void display() {
        cout << "\nBook ID: " << bookID
             << "\nTitle: " << title
             << "\nPrice: " << price << endl;
    }

    // c) Destructor
    ~Book() {
        cout << "Destructor called for Book: " << title << endl;
    }
};

int main() {
    cout << "--- Default Constructor Object ---\n";
    Book b1; // calls default constructor
    b1.display();

    cout << "\n--- Parameterized Constructor Object ---\n";
    Book b2(101, "AI Revolution", 499.99); // calls parameterized constructor
    b2.display();

    cout << "\nEnd of main function.\n";
    return 0;
}
