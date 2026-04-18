#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

// Function to get file extension
string getExtension(const string& filename) {
    size_t pos = filename.rfind('.');
    if (pos == string::npos) return "";
    return filename.substr(pos);
}

// Function to create directory
bool createDirectory(const string& path) {
    return CreateDirectoryA(path.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS;
}

// Function to move file
bool moveFile(const string& source, const string& dest) {
    return MoveFileA(source.c_str(), dest.c_str());
}

// Function to check if directory exists
bool directoryExists(const string& path) {
    DWORD attribs = GetFileAttributesA(path.c_str());
    return (attribs != INVALID_FILE_ATTRIBUTES && (attribs & FILE_ATTRIBUTE_DIRECTORY));
}

int main(int argc, char* argv[]) {
    string path;
    
    // إذا تم تمرير المسار كـ argument، استخدمه
    if (argc > 1) {
        path = argv[1];
    } else {
        cout << "Enter the directory path to organize: ";
        getline(cin, path);
    }

    if (path[path.length() - 1] != '\\') path += '\\';

    if (directoryExists(path)) {
        try {
            // Collect all files
            vector<string> files;
            WIN32_FIND_DATAA findData;
            HANDLE findHandle = FindFirstFileA((path + "*").c_str(), &findData);

            if (findHandle != INVALID_HANDLE_VALUE) {
                do {
                    if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                        files.push_back(findData.cFileName);
                    }
                } while (FindNextFileA(findHandle, &findData));
                FindClose(findHandle);
            }

            // Process collected files
            for (const auto& filename : files) {
                string ext = getExtension(filename);
                string folderName = "Others";

                // Categorize files based on extension
                if (ext == ".pdf" || ext == ".docx") folderName = "Documents";
                else if (ext == ".jpg" || ext == ".png") folderName = "Images";
                else if (ext == ".cpp" || ext == ".py") folderName = "Programming";

                // Create folder
                string destFolder = path + folderName;
                createDirectory(destFolder);

                // Move file
                string sourcePath = path + filename;
                string destPath = destFolder + "\\" + filename;
                
                if (moveFile(sourcePath, destPath)) {
                    cout << "Moved: " << filename << " -> " << folderName << endl;
                }
            }
            cout << "Files organized successfully!" << endl;
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    } else {
        cout << "Invalid path!" << endl;
    }
    return 0;
}