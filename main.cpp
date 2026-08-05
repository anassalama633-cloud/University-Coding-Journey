#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class Student {
private:
    int id;
    string name;
    string projectName;
    double grade;

public:
    Student(int id, string name, string projectName, double grade) 
        : id(id), name(name), projectName(projectName), grade(grade) {}

    int getId() const { return id; }
    string getName() const { return name; }
    string getProjectName() const { return projectName; }
    double getGrade() const { return grade; }

    void display() const {
        cout << left << setw(10) << id 
             << setw(20) << name 
             << setw(25) << projectName 
             << setw(10) << fixed << setprecision(2) << grade << endl;
    }

    string toFileFormat() const {
        return to_string(id) + "," + name + "," + projectName + "," + to_string(grade);
    }
};

class StudentManager {
private:
    vector<Student> students;
    const string filename = "students.txt";

public:
    StudentManager() {
        loadFromFile();
    }

    void addStudent() {
        int id;
        string name, projectName;
        double grade;

        cout << "\n--- Add New Student Record ---\n";
        cout << "Enter Student ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Project Title: ";
        getline(cin, projectName);

        cout << "Enter Grade: ";
        cin >> grade;

        students.push_back(Student(id, name, projectName, grade));
        saveToFile();
        cout << "[+] Student record added successfully!\n";
    }

    void displayAll() const {
        if (students.empty()) {
            cout << "\n[!] No records found.\n";
            return;
        }

        cout << "\n-------------------------------------------------------------------\n";
        cout << left << setw(10) << "ID" 
             << setw(20) << "Name" 
             << setw(25) << "Project Title" 
             << setw(10) << "Grade" << endl;
        cout << "-------------------------------------------------------------------\n";

        for (const auto& student : students) {
            student.display();
        }
        cout << "-------------------------------------------------------------------\n";
    }

    void searchById() const {
        int id;
        cout << "\nEnter Student ID to search: ";
        cin >> id;

        for (const auto& student : students) {
            if (student.getId() == id) {
                cout << "\n[+] Student Found:\n";
                cout << left << setw(10) << "ID" 
                     << setw(20) << "Name" 
                     << setw(25) << "Project Title" 
                     << setw(10) << "Grade" << endl;
                student.display();
                return;
            }
        }
        cout << "\n[-] Student with ID " << id << " not found.\n";
    }

    void saveToFile() const {
        ofstream outFile(filename);
        if (!outFile) {
            cerr << "Error writing to file!" << endl;
            return;
        }
        for (const auto& student : students) {
            outFile << student.toFileFormat() << endl;
        }
        outFile.close();
    }

    void loadFromFile() {
        ifstream inFile(filename);
        if (!inFile) return;

        students.clear();
        string line;
        while (getline(inFile, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);

            if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos) {
                int id = stoi(line.substr(0, pos1));
                string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
                string proj = line.substr(pos2 + 1, pos3 - pos2 - 1);
                double grade = stod(line.substr(pos3 + 1));

                students.push_back(Student(id, name, proj, grade));
            }
        }
        inFile.close();
    }
};

int main() {
    StudentManager manager;
    int choice;

    do {
        cout << "\n=========================================\n";
        cout << "  Student & Project Management System\n";
        cout << "=========================================\n";
        cout << "1. Add Student Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addStudent();
                break;
            case 2:
                manager.displayAll();
                break;
            case 3:
                manager.searchById();
                break;
            case 4:
                cout << "\nExiting program. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
