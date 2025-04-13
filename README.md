# Easy Deployment Tool for Ansible

## Overview
Ansible Setup Tool is a user-friendly command-line utility designed to automate the installation of Ansible and the execution of playbooks on remote hosts. This tool simplifies the process of setting up SSH connections, generating and transferring SSH keys, and managing an inventory of remote machines.

## Features
- **Install Ansible** on the local machine
- **Connect to Remote Hosts** via SSH
- **Generate and Transfer SSH Keys** for secure authentication
- **Manage Inventory** of remote hosts in `inventory.ini`
- **Run Playbooks** to configure Windows, macOS, and Linux according to user preferences

## Planned Playbooks
The tool will soon include playbooks for:
- **Configuring Windows, macOS, and Linux** with custom settings
- **Installing Essential Programs** tailored to the developer's workflow

## Getting Started
### Prerequisites
- A Unix-based system (Linux/macOS) or Windows with a compatible terminal
- SSH installed and enabled
- Basic knowledge of Ansible and remote server management

### Usage
1. Clone this repository:
   ```sh
   git clone https://github.com/yourrepo/ansible-setup-tool.git
   cd ansible-setup-tool
   ```
2. Compile and run the program:
   ```sh
   g++ -o ansible_tool ansible_tool.cpp -std=c++11
   ./ansible_tool
   ```
3. Follow the on-screen instructions to install Ansible, configure SSH, and run playbooks.

## Contributions
Contributions are welcome! If you have ideas for additional playbooks or improvements, feel free to submit a pull request.

## License
This project is licensed under the MIT License.

## Acknowledgments
Thanks for checking out Ansible Setup Tool! If you find this tool useful, consider leaving a star on the GitHub repository.

