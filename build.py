import os

def build():
    os.system("cmake -B build -G \"Visual Studio 17 2022\" -A x64")
    os.system("cmake --build build --config Release")

if __name__ == "__main__":
    build()