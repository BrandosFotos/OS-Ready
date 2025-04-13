# install.ps1

# Install Chocolatey (if not installed)
if (-not (Get-Command choco -ErrorAction SilentlyContinue)) {
    Write-Output "Installing Chocolatey..."
    Set-ExecutionPolicy Bypass -Scope Process -Force
    [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072
    iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
}

# Install apps
choco install git -y
choco install vscode -y
choco install googlechrome -y
choco install 7zip -y
choco install firefox -y
choco install bambustudio -y
choco install geforce-game-ready-driver -y