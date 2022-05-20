cmake_minimum_required(VERSION 3.21)
project(VolunteerManagementSystem C)

set(CMAKE_C_STANDARD 99)

add_executable(VolunteerManagementSystem main.c http/Web.h http/Init.c http/Routes.c http/GET.c http/POST.c http/Send.c volunteer/Volunteer.c volunteer/Volunteer.h volunteer/Crud.c)

target_link_libraries(VolunteerManagementSystem ws2_32.lib)
