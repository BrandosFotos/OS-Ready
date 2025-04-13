#!/bin/bash

# Check if Homebrew is installed
if ! command -v brew &> /dev/null; then
    echo "Homebrew is not installed. Installing Homebrew..."
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
fi


# Install Ansible
echo "Installing Ansible..."
brew install ansible

# Verify the installation
ansible --version

# Install the roles from requrement.yaml
echo "Installing Ansible roles and collections..."
ansible-galaxy install -r requirements.yaml

echo "Ansible installation complete."