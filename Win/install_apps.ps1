# install.ps1

# Install Chocolatey (if not installed)
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
if (-not (Get-Command choco -ErrorAction SilentlyContinue)) {
    Write-Host "Chocolatey installation failed. Exiting script."
    exit 1
}

# Install apps
choco install git -y
choco install vscode -y
choco install googlechrome -y
choco install 7zip -y
choco install firefox -y
choco install bambustudio -y
choco install microsoft-teams.install -y
choco install epicgameslauncher -y
choco install discord -y
choco install steam -y
choco install nvidia-app -y
choco install winscp -y