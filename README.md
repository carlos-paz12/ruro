# 🎲 Russian Roulette - CLI Game

**Version:** 0.1
**License:** MIT
**Author:** [Carlos Paz](https://github.com/carlos-paz12/)

A simple and suspenseful command-line Russian Roulette game written in modern C++. Pick a number from 1 to 6, spin the chamber... and see if you survive. 💥

## 📁 Project Structure
```
ruro/
├── CMakeLists.txt
├── README.md
├── src/
│   └── main.cpp
└── build/  ←- created after compilation
```

## 📦 Build Instructions

### ✅ Requirements

- CMake >= 3.12
- C++17 compatible compiler:
  - GCC
  - Clang

### 🛠 Build (Linux/macOS/Windows)

1. Clone this repository:
```bash
git clone https://github.com/carlos-paz12/ruro.git
```
2. Navigate to the project directory:
```bash
cd ruro
```
3. Compile with `cmake`:
```bash
cmake -S . -B build
cmake --build build
```

4. Run and fun:
```bash
./build/ruro
```
---
