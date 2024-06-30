#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <filesystem>

using namespace std;
using namespace filesystem;

void listFiles(const string& path) {
    for (const auto& entry : directory_iterator(path)) {
        if (is_directory(entry.status())) {
            cout << "[DIR] " << entry.path().filename().string() << endl;
        } else {
            cout << "[FILE] " << entry.path().filename().string() << endl;
        }
    }
}

void createDirectory(const string& path) {
    if (create_directory(path)) {
        cout << "Directory created successfully." << endl;
    } else {
        cout << "Failed to create directory." << endl;
    }
}

void copyFile(const string& source, const string& destination) {
    ifstream src(source, ios::binary);
    ofstream dst(destination, ios::binary);

    dst << src.rdbuf();

    if (src.good() && dst.good()) {
        cout << "File copied successfully." << endl;
    } else {
        cout << "Failed to copy file." << endl;
    }
}

void moveFile(const string& source, const string& destination) {
    if (rename(source.c_str(), destination.c_str())) {
        cout << "Failed to move file." << endl;
    } else {
        cout << "File moved successfully." << endl;
    }
}

int main() {
    string currentPath = ".";

    while (true) {
        cout << "Current path: " << currentPath << endl;
        cout << "Enter command (ls, mkdir, cp, mv, cd, exit): ";
        string command;
        cin >> command;

        if (command == "ls") {
            listFiles(currentPath);
        } else if (command == "mkdir") {
            cout << "Enter directory name: ";
            string dirName;
            cin >> dirName;
            createDirectory(currentPath + "/" + dirName);
        } else if (command == "cp") {
            cout << "Enter source file: ";
            string source;
            cin >> source;
            cout << "Enter destination: ";
            string destination;
            cin >> destination;
            copyFile(source, destination);
        } else if (command == "mv") {
            cout << "Enter source file: ";
            string source;
            cin >> source;
            cout << "Enter destination: ";
            string destination;
            cin >> destination;
            moveFile(source, destination);
        } else if (command == "cd") {
            cout << "Enter directory: ";
            string dir;
            cin >> dir;
            currentPath += "/" + dir;
        } else if (command == "exit") {
            break;
        } else {
            cout << "Invalid command." << endl;
        }
    }

    return 0;
}
