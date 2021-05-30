# CMakeList.txt: проект CMake для hw4; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("hw4")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (hw4 "main.cpp"  "controller.cpp" "controller.h" "document.h" "shape.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
