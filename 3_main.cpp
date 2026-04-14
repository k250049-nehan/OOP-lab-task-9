#include <iostream>
#include "Book.h"
using namespace std;

int main() {
    Book b("The Maestro", "Nehan Malik", "9780061122415");

    cout << "Title: " << b.getTitle() << endl;
    cout << "Author: " << b.getAuthor() << endl;
    cout << "ISBN: " << b.getISBN() << endl;

    return 0;
}
