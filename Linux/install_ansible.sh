#!/bin/bash

# Detect package manager
if command -v apt &> /dev/null; then
    echo "Using APT package manager (Debian/Ubuntu)."
    sudo apt update && sudo apt install -y ansible

elif command -v dnf &> /dev/null; then
    echo "Using DNF package manager (Fedora)."
    sudo dnf install -y ansible

elif command -v yum &> /dev/null; then
    echo "Using YUM package manager (CentOS/RHEL)."
    sudo yum install -y ansible

elif command -v pacman &> /dev/null; then
    echo "Using Pacman package manager (Arch Linux)."
    sudo pacman -Sy --noconfirm ansible

else
    echo "Unsupported Linux distribution. Please install Ansible manually."
    exit 1
fi