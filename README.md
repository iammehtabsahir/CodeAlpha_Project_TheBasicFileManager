# CodeAlpha_Project_TheBasicFileManager
Imagine this code as a machine that copies files.

It has special tools (#include statements) to access different capabilities:
One tool (<iostream>) lets it talk to you and display messages.
Another tool (<filesystem>) helps it work with files and folders (like a filing cabinet).
The code defines a special task called copyFile that takes two things:
The location of the original file (like the address of a document in your filing cabinet).
The destination where you want a copy placed (like a new folder or location in the cabinet).
Inside the copyFile task, the code carefully tries to:
Use the file system tool to grab the original file.
Make a copy of that file and put it in the new destination you specified.
If everything goes smoothly, the code happily tells you: "File copied successfully!"
But sometimes, things might not work (like if the original file doesn't exist). In those cases, the code catches the error and tells you: "Error copying file."
