cmake_minimum_required(VERSION 3.21)
project(lab7)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab7 main.cpp Entity/Entity.cpp Entity/Entity.h Repo/Repo.cpp Repo/Repo.h Consola/console.cpp Consola/console.h menu/menu.cpp menu/menu.h Tests/tests.cpp Tests/tests.h Service/Service.cpp Service/Service.h menu/menu.cpp menu/menu.h)
