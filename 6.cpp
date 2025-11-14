//Write a C++ program using STL to demonstrate the use of vector,
// list, set, and map containers.
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;

int main() {

    // ---------------- VECTOR ----------------
    vector<int> v = {10, 20, 30};

    v.push_back(40);
    v.push_back(50);

    cout << "\nVector elements: ";
    for (int x : v) 
        cout << x << " ";



    // ---------------- LIST ----------------
    list<string> names;
    names.push_back("Rahul");
    names.push_back("Priya");
    names.push_front("Amit");   // add at front

    cout << "\n\nList elements: ";
    for (const string &s : names)
        cout << s << " ";



    // ---------------- SET ----------------
    set<int> s;
    s.insert(5);
    s.insert(2);
    s.insert(9);
    s.insert(2);  // duplicate ignored

    cout << "\n\nSet elements (sorted & unique): ";
    for (int x : s)
        cout << x << " ";



    // ---------------- MAP ----------------
    map<int, string> m;
    m[101] = "Physics";
    m[102] = "Maths";
    m[103] = "Chemistry";

    cout << "\n\nMap elements (key → value):\n";
    for (auto &p : m)
        cout << p.first << " : " << p.second << "\n";


    return 0;
}