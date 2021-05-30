# CMakeList.txt: проект CMake для hw4; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("hw4")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (hw4 "main.cpp"  "controller.cpp" "controller.h" "document.h" "shape.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.

install(TARGETS hw2 RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
