This C++ code implements a simple file management tool that allows users to interact with the file system from the command line. Here's a breakdown of each section:
Headers:
<iostream>: Provides input/output functionality (standard streams like cin, cout)
<fstream>: Enables file operations (opening, reading, writing files)
<string>: Used for string manipulation (filenames, paths)
<vector>: Not directly used in this code, but provides functionality for dynamic arrays
<algorithm>: Not directly used in this code, but provides various algorithms
<filesystem>: Provides access to modern file system features (directory iteration, directory creation)

Namespaces:
using namespace std;: Brings commonly used elements from the standard library (like string, cin, cout) into scope for easier access. Note: This can be discouraged in larger projects to avoid naming conflicts.
using namespace filesystem;: Brings elements from the filesystem library (like directory_iterator, create_directory) into scope for easier access. Similar note: Consider using specific elements (e.g., std::filesystem::directory_iterator) for better clarity.

Functions:
listFiles(const string& path):
Takes a directory path as input.
Uses directory_iterator to iterate through all entries (files and directories) within that path.
Checks if each entry is a directory using is_directory.
Prints the filename with appropriate prefix ("[DIR]" for directories, "[FILE]" for files) using cout.
createDirectory(const string& path):
Takes a directory path as input.
Attempts to create a new directory at the specified path using create_directory.
Prints a success message if the directory is created, or a failure message otherwise.
copyFile(const string& source, const string& destination):
Takes the source and destination file paths as input.
Opens both files in binary mode (ios::binary) using ifstream and ofstream.
Copies the content from the source file to the destination file using rdbuf.
Checks if both operations were successful and prints messages accordingly.
moveFile(const string& source, const string& destination):
Takes the source and destination file paths as input.
Attempts to rename the source file to the destination path using rename.
Prints a success message if the file is moved, or a failure message otherwise.

Main Function:
Initializes a string variable currentPath to "." (representing the current directory).
Enters an infinite loop (while(true)) that continues until the user exits.
Inside the loop:
Prints the current working directory using cout.
Prompts the user for a command (ls, mkdir, cp, mv, cd, or exit) using cin.
Uses a series of if-else if statements to handle different commands:
ls: Calls listFiles with the current path to list files and directories.
mkdir: Prompts for a directory name, constructs the full path, and calls createDirectory to create the new directory.
cp: Prompts for source and destination file paths, and calls copyFile to copy the file.
mv: Prompts for source and destination file paths, and calls moveFile to rename and move the file.
cd: Prompts for a directory name, updates the currentPath by appending the directory name, effectively changing the working directory.
exit: Breaks out of the loop, terminating the program.
If the user enters an invalid command, an error message is printed using cout.

Overall Functionality:
This code provides a basic set of file management commands like listing files, creating directories, copying files, moving files, and changing the current directory. It can be a helpful tool for basic file manipulation tasks within the command line.
When Sharing Give Credits To :www.linkedin.com/in/mehtab-sahir-rajput

Additional Notes:
The code can be enhanced by adding features like:
Error handling for invalid paths or file operations.
Handling non-existent directories.
Confirmation prompts before potentially destructive actions like moving files.
Consider using specific elements from namespaces instead of using namespace for better code organization and avoiding naming conflicts.
