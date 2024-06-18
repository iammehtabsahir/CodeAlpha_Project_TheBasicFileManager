#include <iostream> // Include header for input/output operations
#include <filesystem> // Include header for file system operations (C++17 or later)
#include <vector> // Include header for vector containers (optional, not used here)
#include <string>  // Include header for string manipulation

using namespace std; // Use the standard namespace (avoid overuse in larger projects)
namespace fs = filesystem; // Create an alias for the filesystem namespace

// Function to copy a file with overwrite option
bool copyFile(const string& source, const string& destination) {
  try {
    // Attempt to copy the file using filesystem library
    fs::copy_file(source, destination, fs::copy_options::overwrite_existing);
    cout << "File copied successfully!" << endl;
    return true;
  } catch (const std::filesystem::filesystem_error& e) {
    // Catch specific filesystem errors
    cerr << "Error copying file: " << e.what() << endl;
  } catch (const exception& e) {
    // Catch any other unexpected exceptions
    cerr << "An unexpected error occurred: " << e.what() << endl;
  }
  return false; // Indicate failure if exceptions occur
}
