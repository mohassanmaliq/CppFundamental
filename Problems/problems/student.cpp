#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;

const string FILE_NAME = "students.txt";

class Student {
private:
    int id;
    string name;
    string department;
    double cgpa;

public:
    Student() : id(0), cgpa(0.0) {}

    Student(int id, const string &name, const string &department, double cgpa)
        : id(id), name(name), department(department), cgpa(cgpa) {}

    int getId() const { return id; }
    string getName() const { return name; }
    string getDepartment() const { return department; }
    double getCgpa() const { return cgpa; }

    void setName(const string &n) { name = n; }
    void setDepartment(const string &d) { department = d; }
    void setCgpa(double c) { cgpa = c; }

    void display() const {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Department: " << department
             << " | CGPA: " << cgpa << endl;
    }

    string toLine() const {
        ostringstream out;
        out << id << "|" << name << "|" << department << "|" << cgpa;
        return out.str();
    }

    static bool fromLine(const string &line, Student &s) {
        vector<string> parts;
        string part;
        istringstream in(line);
        while (getline(in, part, '|')) parts.push_back(part);
        if (parts.size() != 4) return false;
        s.id = atoi(parts[0].c_str());
        s.name = parts[1];
        s.department = parts[2];
        s.cgpa = atof(parts[3].c_str());
        return true;
    }
};

class StudentManager {
private:
    vector<Student> students;

    int findIndexById(int id) const {
        for (size_t i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) return (int)i;
        }
        return -1;
    }

public:
    void load() {
        students.clear();
        ifstream file(FILE_NAME.c_str());
        if (!file) return;
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
            Student s;
            if (Student::fromLine(line, s)) students.push_back(s);
        }
        file.close();
    }

    void save() const {
        ofstream file(FILE_NAME.c_str());
        for (size_t i = 0; i < students.size(); i++) {
            file << students[i].toLine() << endl;
        }
        file.close();
    }

    bool add(const Student &s) {
        if (findIndexById(s.getId()) != -1) return false;
        students.push_back(s);
        save();
        return true;
    }

    bool remove(int id) {
        int idx = findIndexById(id);
        if (idx == -1) return false;
        students.erase(students.begin() + idx);
        save();
        return true;
    }

    bool update(int id, const string &name, const string &dept, double cgpa) {
        int idx = findIndexById(id);
        if (idx == -1) return false;
        students[idx].setName(name);
        students[idx].setDepartment(dept);
        students[idx].setCgpa(cgpa);
        save();
        return true;
    }

    const Student *find(int id) const {
        int idx = findIndexById(id);
        if (idx == -1) return NULL;
        return &students[idx];
    }

    void searchByName(const string &keyword) const {
        string key = toLower(keyword);
        bool found = false;
        for (size_t i = 0; i < students.size(); i++) {
            if (toLower(students[i].getName()).find(key) != string::npos) {
                students[i].display();
                found = true;
            }
        }
        if (!found) cout << "No matching students." << endl;
    }

    void displayAll() const {
        if (students.empty()) {
            cout << "No records." << endl;
            return;
        }
        for (size_t i = 0; i < students.size(); i++) students[i].display();
    }

    void displaySortedByCgpa() const {
        vector<Student> copy = students;
        sort(copy.begin(), copy.end(), compareCgpa);
        if (copy.empty()) {
            cout << "No records." << endl;
            return;
        }
        for (size_t i = 0; i < copy.size(); i++) copy[i].display();
    }

    void displaySortedByName() const {
        vector<Student> copy = students;
        sort(copy.begin(), copy.end(), compareName);
        if (copy.empty()) {
            cout << "No records." << endl;
            return;
        }
        for (size_t i = 0; i < copy.size(); i++) copy[i].display();
    }

    void statistics() const {
        if (students.empty()) {
            cout << "No records." << endl;
            return;
        }
        double total = 0;
        const Student *top = &students[0];
        const Student *low = &students[0];
        for (size_t i = 0; i < students.size(); i++) {
            total += students[i].getCgpa();
            if (students[i].getCgpa() > top->getCgpa()) top = &students[i];
            if (students[i].getCgpa() < low->getCgpa()) low = &students[i];
        }
        cout << "Total students: " << students.size() << endl;
        cout << "Average CGPA: " << total / students.size() << endl;
        cout << "Highest CGPA: " << top->getName() << " (" << top->getCgpa() << ")" << endl;
        cout << "Lowest CGPA: " << low->getName() << " (" << low->getCgpa() << ")" << endl;
    }

    static string toLower(string s) {
        for (size_t i = 0; i < s.size(); i++) s[i] = (char)tolower((unsigned char)s[i]);
        return s;
    }

    static bool compareCgpa(const Student &a, const Student &b) {
        return a.getCgpa() > b.getCgpa();
    }

    static bool compareName(const Student &a, const Student &b) {
        return toLower(a.getName()) < toLower(b.getName());
    }
};

// ---------- input helpers ----------

int readInt(const string &prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid number." << endl;
    }
}

double readCgpa(const string &prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= 0.0 && value <= 4.0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "CGPA must be between 0.0 and 4.0." << endl;
    }
}

string readLine(const string &prompt) {
    string s;
    while (true) {
        cout << prompt;
        getline(cin, s);
        if (!s.empty() && s.find('|') == string::npos) return s;
        cout << "Input cannot be empty or contain '|'." << endl;
    }
}

// ---------- menu actions ----------

void addStudent(StudentManager &m) {
    int id = readInt("Enter ID: ");
    string name = readLine("Enter name: ");
    string dept = readLine("Enter department: ");
    double cgpa = readCgpa("Enter CGPA (0-4): ");
    if (m.add(Student(id, name, dept, cgpa))) cout << "Student added." << endl;
    else cout << "A student with this ID already exists." << endl;
}

void removeStudent(StudentManager &m) {
    int id = readInt("Enter ID to delete: ");
    if (m.remove(id)) cout << "Student deleted." << endl;
    else cout << "Student not found." << endl;
}

void updateStudent(StudentManager &m) {
    int id = readInt("Enter ID to update: ");
    if (m.find(id) == NULL) {
        cout << "Student not found." << endl;
        return;
    }
    string name = readLine("New name: ");
    string dept = readLine("New department: ");
    double cgpa = readCgpa("New CGPA (0-4): ");
    m.update(id, name, dept, cgpa);
    cout << "Student updated." << endl;
}

void searchById(const StudentManager &m) {
    int id = readInt("Enter ID: ");
    const Student *s = m.find(id);
    if (s == NULL) cout << "Student not found." << endl;
    else s->display();
}

void searchByName(const StudentManager &m) {
    string keyword = readLine("Enter name or part of it: ");
    m.searchByName(keyword);
}

void showMenu() {
    cout << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Search by ID" << endl;
    cout << "4. Search by name" << endl;
    cout << "5. Update student" << endl;
    cout << "6. Delete student" << endl;
    cout << "7. Sort by CGPA (high to low)" << endl;
    cout << "8. Sort by name (A to Z)" << endl;
    cout << "9. Statistics" << endl;
    cout << "0. Exit" << endl;
}

int main() {
    StudentManager manager;
    manager.load();

    int choice;
    do {
        showMenu();
        choice = readInt("Choice: ");
        switch (choice) {
            case 1: addStudent(manager); break;
            case 2: manager.displayAll(); break;
            case 3: searchById(manager); break;
            case 4: searchByName(manager); break;
            case 5: updateStudent(manager); break;
            case 6: removeStudent(manager); break;
            case 7: manager.displaySortedByCgpa(); break;
            case 8: manager.displaySortedByName(); break;
            case 9: manager.statistics(); break;
            case 0: cout << "Bye." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}
