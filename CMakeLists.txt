cmake_minimum_required(VERSION 3.5)

# Nome do projeto
project(ruro VERSION 0.1 LANGUAGES CXX)

# Define o padrão do C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define os arquivos-fonte
add_executable(ruro src/main.cpp)

target_compile_options(ruro PRIVATE -Wall -Wextra -pedantic -Werror)
