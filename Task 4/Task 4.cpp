#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Worker {
    string name;
    char sex;
    int age;
    string address;
    string phone;
    string departmentName;
    string position;
    int experience;
    double salary;
};

void saveWorker(const Worker workers[], int count, const string& filename) {
    ofstream out(filename);
    if (!out) {
        std::cerr << "Error opening output file" << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        out << workers[i].name << endl;
        out << workers[i].sex << endl;
        out << workers[i].age << endl;
        out << workers[i].address << endl;
        out << workers[i].phone << endl;
        out << workers[i].departmentName << endl;
        out << workers[i].position << endl;
        out << workers[i].experience << endl;
        out << workers[i].salary << endl;
    }

    out.close();
}

void loadWorkers(Worker workers[], int& count, const string& filename) {
    ifstream in(filename);
    if (!in) {
        cerr << "Error opening input file" << endl;
        return;
    }

    count = 0;

    Worker worker;
    while (in >> worker.name && in >> worker.sex && in >> worker.age && in >> worker.address && in >> worker.phone && in >> worker.departmentName && in >> worker.position && in >> worker.experience && in >> worker.salary) {
        workers[count++] = worker;
    }

    in.close();
}

void addWorker(Worker workers[], int& count) {
    if (count >= 100) {
        cerr << "Too many workers" << endl;
        return;
    }

    Worker& worker = workers[count];

    cout << "Enter name: ";
    cin >> worker.name;

    cout << "Enter sex (M/F): ";
    cin >> worker.sex;
    cin.ignore();

    cout << "Enter age: ";
    cin >> worker.age;
    cin.ignore();

    cout << "Enter address: ";
    cin >> worker.address;

    cout << "Enter phone: ";
    cin >> worker.phone;

    cout << "Enter department: ";
    cin >> worker.departmentName;

    cout << "Enter position: ";
    cin >> worker.position;

    cout << "Enter experience: ";
    cin >> worker.experience;
    cin.ignore();

    cout << "Enter salary: ";
    cin >> worker.salary;
    cin.ignore();

    count++;
}

void printWorkerByAge(const Worker workers[], int count, int age) {
    for (int i = 0; i < count; i++) {
        if (workers[i].age >= age) {
            cout << workers[i].name << " (" << workers[i].age << ") " << endl;
        }
    }
}

int main() {
    const int MAX_EMPLOYEES = 100;
    Worker workers[MAX_EMPLOYEES];
    string filename = "Workers.txt";

    int count;
    loadWorkers(workers, count, filename);

    cout << "\n1. Add worker\n2. Print workers by age";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    cin.ignore();

    switch (choice) {
    case 1:
        addWorker(workers, count);
        saveWorker(workers, count, filename);
        break;
    case 2:
        cout << "Enter age: ";
        int age;
        cin >> age;
        printWorkerByAge(workers, count, age);
        break;
    default:
        cout << "Invalid choice. Please try again.\n";
        break;
    }
    return 0;
}

