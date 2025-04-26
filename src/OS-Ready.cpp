#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

// Function declarations
void clearscreen(string platform);
void getPlatformSpecificPaths(string& platform, string& username, string& SCP);
int runProgram(int selection, string platform, string filenames[]);
void writeAllEmbeddedFiles();

int main() {
    string platform;
    string username;
    string keyPath;
    string SCP;
    string SSH_KEYGEN;
    string filenames[10];

    int selection;

    char remoteOrLocal;
    getPlatformSpecificPaths(platform, username, SCP);
    clearscreen(platform);
    

    cout << "-----------------------------------\n";
    cout << "Welcome to the Ansible Setup Tool\n";
    cout << "This is a work in progress, please be patient with me <3\n";
    cout << "-----------------------------------\n\n";


    cout << "Do you want to connect to a remote or local device?\n";
    cout << "(R)emote or (L)ocal? : ";
    cin >> remoteOrLocal;

    clearscreen(platform);

    if (remoteOrLocal == 'L' || remoteOrLocal == 'l') {

        do {
        
            cout << "------------------------[ LOCAL " << platform << "]------------------------\n\n";
            cout << "Available playbooks:\n";

            string path = platform; // Change this to your actual directory


            int j = 0;
            try {
                for (const auto& entry : fs::directory_iterator(path)) {
                    if (entry.is_regular_file()) {
                        filenames[j] = entry.path().filename().string();
                        j ++;
                    }
                }
            } catch (const fs::filesystem_error& e) {
                cerr << "Filesystem error: " << e.what() << '\n';
            }

            for (int i =0; i < j; i++) {
                cout << setw(4) << i + 1 << ")  " << filenames[i] << endl;
            }   

            if (selection > 0 && selection <= j) {
            } else if (selection != 0) {
                cout << "\n \e[1m Invalid selection. Please try again. \e[0m ";
            }
            cout << "\nSelect a playbook to run (1-" << j << ") or 0 to exit: ";
            cin >> selection;

            runProgram(selection, platform, filenames);

            
        } while (selection != 0);




    } else if (remoteOrLocal == 'R' || remoteOrLocal == 'r') {
        cout << "(REMOTE)\n";
        // Remote setup logic goes here

    } else {
        cerr << "Invalid input. Please enter 'R' or 'L'.\n";
    }

    return 0;
}
void clearscreen(string platform) {
    if (platform == "Win") {
        system("cls"); // Windows
    } else {
        system("clear"); // Mac and Linux
    }
}


void getPlatformSpecificPaths(string& platform, string& username, string& SCP) {
    #ifdef _WIN32
        char* user = getenv("USERNAME");
    #else
        char* user = getenv("USER");
    #endif

    if (user) {
        username = user;
    } else {
        username = "unknown";
    }

    // Detect platform using uname
    string result;
    FILE* pipe = popen("uname", "r");
    if (!pipe) {
        platform = "Unknown";
        SCP = "scp";
        return;
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }
    pclose(pipe);

    // Normalize the result
    if (result.find("Darwin") != string::npos) {
        platform = "Mac";
        SCP = "scp";
    } else if (result.find("Linux") != string::npos) {
        platform = "Linux";
        SCP = "scp";
    } else {
        platform = "Win";
        SCP = "scp.exe";
    }
}


int runProgram(int selection, string platform, string filenames[]) {
    clearscreen(platform);
    string command;
    string filename = filenames[selection - 1]; // Get the selected filename
    string extension;
    size_t dotIndex = filename.find_last_of(".");

    
    std::cout << "------------------------[ LOCAL " << platform << " : " << filename << " ]------------------------\n\n";
    if (dotIndex != string::npos) {
        extension = filename.substr(dotIndex + 1);
    } else {
        std::cout << "Invalid filename" << endl;
    }


    if (extension == "sh"){
        // Run shell script
        command = "bash " + platform + "/" + filename;
        system(command.c_str());

    } else if (extension == "yaml" || extension =="yml"){
        // Run ansible playbook
        command = "ansible-playbook " + platform + "/" + filename;
        system(command.c_str());

    } else if (extension == "ps1"){
        // Run powershell script
        command = "powershell -ExecutionPolicy Bypass -File " + platform + "/" + filename;
        system(command.c_str());
    } 

    cout << "\n\nPress any key to continue...";
    cin.ignore();

    // Clear the screen again
    clearscreen(platform);
    return 0;

};