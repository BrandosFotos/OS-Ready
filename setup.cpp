#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <fstream>



// Prototype functions
void clearscreen();
void menu(std::string& username, std::string& playbook, std::string& platform);
void exportToInventory(const std::string& title, const std::string& keyPath, const std::string& username, const std::string& hostname, const std::string& password);
void setupSSHKey(const std::string& username, const std::string& hostname, std::string& platform, std::string& keyPath, std::string& SCP, std::string& SSH_KEYGEN);
void getPlatformSpecificPaths(std::string& platform, std::string& username, std::string& keyPath, std::string& SCP, std::string& SSH_KEYGEN);
void connecttoremote(std::string& username, std::string& hostname, std::string& password, std::string& title, std::string& platform, std::string& keyPath, std::string& SCP, std::string& SSH_KEYGEN);


int main() {
    std::string hostname;
    std::string username;
    std::string password;
    std::string title;
    std::string platform;
    std::string playbook;
    std::string keyPath;
    std::string SCP;
    std::string SSH_KEYGEN;
    char remoteOrLocal;

    clearscreen();
    do {
        std::cout << "-----------------------------------\n";
        std::cout << "Welcome to the Ansible Setup Tool\n";
        std::cout << "-----------------------------------\n";
        std::cout <<"Do you want to connect to a remote or local device?\n";
        std::cout << "(R)emote or (L)ocal" << username << ": ";
        std::cin >> remoteOrLocal;

    
        if (remoteOrLocal == 'L' || remoteOrLocal == 'l') {
            getPlatformSpecificPaths(platform, username, keyPath, SCP, SSH_KEYGEN);



            break;

        } else if (remoteOrLocal == 'R' || remoteOrLocal == 'r') {
            connecttoremote(username, hostname, password, title, platform, keyPath, SCP, SSH_KEYGEN);
            break;

        } else {
            clearscreen();
            std::cerr << "Invalid input. Please enter 'R' or 'L'.\n";
        }
    } while (remoteOrLocal != 'L' || remoteOrLocal != 'l' || remoteOrLocal != 'R' || remoteOrLocal != 'r');

    std::cout << "Exiting...\n";

    menu(username, playbook, platform);
    return 0;
}


void connecttoremote(std::string& username, std::string& hostname, std::string& password, std::string& title, std::string& platform, std::string& keyPath, std::string& SCP, std::string& SSH_KEYGEN) {

            std::cout << "Give a title to the SSH client: ";
            std::cin >> title;
            std::cout << "Enter the hostname or IP address of the SSH client: ";
            std::cin >> hostname;
            std::cout << "Enter the username for the SSH client: ";
            std::cin >> username;
            std::cout << "Enter the password for " << username << ": ";
            std::cin >> password;

            clearscreen();
            std::cout << "-----------------------------------\n";
            std::cout << "SSH Client Information\n" << std::endl;
            std::cout << "On first connection:\n";
            std::cout << "  1) Accept the Fingerprint\n";
            std::cout << "  2) Enter " << username << "'s Password\n";
            std::cout << "-----------------------------------\n";

            std::this_thread::sleep_for(std::chrono::seconds(7)); // Pause for 7 seconds

            for (int i = 5; i > 0; i--) {
                std::cout << "Connecting in " << i << " seconds...\n";
                std::this_thread::sleep_for(std::chrono::seconds(1)); // Pause for 1 second
            }

            clearscreen();
            std::cout << "-----------------------------------\n";
            std::cout << "Setting up SSH Key\n";
            std::cout << "-----------------------------------\n";

            getPlatformSpecificPaths(platform, username, keyPath, SCP, SSH_KEYGEN);
            setupSSHKey(username, hostname, platform, keyPath, SCP, SSH_KEYGEN);
            exportToInventory(title, keyPath, username, hostname, password);

}

void menu(std::string& username, std::string& playbook, std::string& platform) {
    int choice;

    do {
        clearscreen();
        std::cout << "-----------------------------------\n";
        std::cout << "Hello, " << username << " I see you are using a " << platform << std::endl <<std::endl;
        std::cout << "What would you like to do?\n";
        std::cout << "1) Install Ansible Locally\n";
        std::cout << "2) Setup Windows\n";
        std::cout << "3) Setup Linux\n";
        std::cout << "4) Setup MacOS\n";
        std::cout << "5) Exit\n";
        std::cout << "-----------------------------------\n";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Installing Ansible...\n";
            std::cout << "-----------------------------------\n";
            playbook = platform + "/install_ansible.sh";

            system(("chmod +x " + playbook).c_str());
            system(("bash " + playbook).c_str());

            if (system(playbook.c_str()) != 0) {
                std::cerr << "Failed to execute " << playbook << ". Make sure it is executable.\n";
            }

            break;

        case 2:
            std::cout << "Setting up Windows...\n";
            std::cout << "-----------------------------------\n";
            playbook = platform + "/setup_windows.sh";

            system(("chmod +x " + playbook).c_str());
            system(("bash " + playbook).c_str());

            if (system(playbook.c_str()) != 0) {
                std::cerr << "Failed to execute " << playbook << ". Make sure it is executable.\n";
            }

            break;
        
        case 3:
            std::cout << "Setting up Linux...\n";
            std::cout << "-----------------------------------\n";
            playbook = platform + "/setup_linux.sh";

            system(("chmod +x " + playbook).c_str());
            system(("bash " + playbook).c_str());

            if (system(playbook.c_str()) != 0) {
                std::cerr << "Failed to execute " << playbook << ". Make sure it is executable.\n";
            }

            break;

        case 4:
            std::cout << "Setting up MacOS...\n";
            std::cout << "-----------------------------------\n";
            playbook = platform + "/setup_macos.sh";

            system(("chmod +x " + playbook).c_str());
            system(("bash " + playbook).c_str());

            if (system(playbook.c_str()) != 0) {
                std::cerr << "Failed to execute " << playbook << ". Make sure it is executable.\n";
            }

            break;

        case 5:
            clearscreen();
            std::cout << "-----------------------------------\n";
            std::cout << "Thank you for using my program <3\n";
            std::cout << "Please consider leaving a star on the GitHub repository\n\n";
            std::cout << "Goodbye, " << username << "!\n";
            std::cout << "-----------------------------------\n";
            break;
        
        default:
            break;
        }
    } while (choice != 5);
    

}

void clearscreen() {
    std::cout << "\033[2J\033[H"; // Clears screen and moves cursor to top-left
}

void getPlatformSpecificPaths(std::string& platform, std::string& username, std::string& keyPath, std::string& SCP, std::string& SSH_KEYGEN) {
    #ifdef _WIN32
    std::cout << "Windows detected.\n";
    platform = "Win";
    username = std::getenv("USERNAME");
    sshKeygen = "ssh-keygen.exe";
    scp = "scp.exe";

    #elif __APPLE__
    std::cout << "macOS detected.\n";
    platform = "Mac";
    username = std::getenv("USER");
    SSH_KEYGEN = "ssh-keygen";
    SCP = "scp";

    #elif __linux__
    std::cout << "Linux detected.\n";
    platform = "Linux";
    username = std::getenv("USER");
    sshKeygen = "ssh-keygen";
    scp = "scp";

    #else
    std::cout << "Unknown platform detected.\n";
    platform = "Unknown";
    sshKeygen = "ssh-keygen";
    scp = "scp";
    #endif
}

void setupSSHKey(const std::string& username, const std::string& hostname, std::string& platform, std::string& keyPath, std::string& SCP, std::string& SSH_KEYGEN) {
    std::string copyKey;

    if ( platform == "Win" ) {
        keyPath = "%USERPROFILE%\\.ssh\\id_rsa";  // Windows path
        copyKey = SCP + std::string(" ") + keyPath + ".pub " + username + "@" + hostname + ":~/.ssh/authorized_keys";
    } else {
        keyPath = "~/.ssh/id_rsa";  // Path for SSH key (Linux/macOS)
        copyKey = "ssh-copy-id " + username + "@" + hostname;  // Linux/macOS command
    }


    // Generate SSH key if not present
    std::string generateKey = SSH_KEYGEN + std::string(" -t rsa -b 4096 -f ") + keyPath + " -N \"\" -q";
    std::cout << "Generating SSH key...\n";
    system(generateKey.c_str());

    std::cout << "Copying key to " << hostname << "...\n";
    int result = system(copyKey.c_str());

    if (result == 0) {
        std::cout << "SSH Key successfully copied to " << hostname << "!\n";
    } else {
        std::cerr << "Failed to copy SSH key. Ensure OpenSSH is installed and the SSH service is running.\n";
    }
}

void exportToInventory(const std::string& title, const std::string& keyPath, const std::string& username, const std::string& hostname, const std::string& password) {
    std::string inventoryPath = "Ansible/inventory.ini";
    std::ofstream inventoryFile(inventoryPath, std::ios::app); // Open in append mode
    

    if (std::ifstream (inventoryPath)) {
        std::cout << "inventory.ini exists . . returning\n";
        return;
    } else {
        std::ofstream inventoryFile(inventoryPath);
        inventoryFile << "[mesh_devices]\n";
    };

    
    if (inventoryFile.is_open()) {

        inventoryFile << title << " ansible_host=" << hostname
                      << " ansible_user=" << username
                      << " ansible_ssh_pass=" << password
                      << " ansible_ssh_private_key_file=" << keyPath << "\n";
        inventoryFile.close();
        std::cout << "Host successfully added to inventory.ini\n";
    } else {
        std::cerr << "Failed to open inventory.ini for writing.\n";
    }
}

