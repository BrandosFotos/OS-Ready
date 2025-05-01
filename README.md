# 🖥️ OS-Ready

## Overview

**OS-Ready** is a lightweight command-line utility designed to automate fresh installations and system configuration across **Windows**, **macOS**, and **Linux** using **Ansible** and **Chocolatey**. It streamlines the setup process for developers, sysadmins, and power users—handling SSH setup, Ansible installastion, inventory management, and execution of tailored playbooks.

## ✨ Features

- ✅ Install **Ansible** on the host system
- ✅ Install **Chocolatey** on Windows 
- ▶️ Run playbooks to install apps, apply configurations, and more  

## 📦 Upcoming Playbooks

Planned system automation scripts will include:
- 🍎 macOS configuration using **Homebrew**
- 🐧 Linux provisioning using native package managers  
- ⚙️ Common developer tools and environments (Docker, VSCode, Git, etc.)
- 🔐 Generate and transfer **SSH keys** for secure remote access
- 🪟 Copy Feature for Games, Programs, Misc. Files
- 🌐 Connect and configure **remote hosts** over SSH
- 📋 Automatically manage your `inventory.ini` for Ansible  

## 🚀 Getting Started

### Requirements
- Windows, macOS, or Linux system with a terminal
- Git and SSH installed
- Basic familiarity with Ansible is helpful but not required

### Installation & Usage

<details>
<summary><strong>Mac & Linux</strong></summary>

# Clone the repo
```bash
# Clones the repo and enters the directory
git clone https://github.com/BrandosFotos/OS-Ready.git
cd OS-Ready
```

# Run the build script
```bash
# Builds the program from source with cmake
chmod +x build.sh
./build.sh
```
</details>


<details>
<summary><strong>Windows (via MinGW)</strong></summary>

# Clone the repo using Git Bash or WSL
```bash
# Clones the repo and enters the directory
git clone https://github.com/BrandosFotos/OS-Ready.git
cd OS-Ready
```

 Ensure MinGW and required toolchain are installed
 (e.g. x86_64-w64-mingw32-gcc and g++ in PATH)

# Run the build script

```bash
# Builds the program from source with cmake
chmod +x build.sh
./build.sh
```
</details>


### Credits
Credit for the windows install script goes to the folks at [Massgrave.dev](https://massgrave.dev/)