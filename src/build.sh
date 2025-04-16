g++ -std=c++17 -o OS-Ready OS-Ready.cpp &&

# For Windows
# If you are running on windows and want to build it, I suggest using the following command on WSL:
# sudo apt install mingw-w64
x86_64-w64-mingw32-g++ -std=c++17 -static -o OS-Ready.exe OS-Ready.cpp