cmake_minimum_required(VERSION 3.21)
project(VolunteerManagementSystem C)

set(CMAKE_C_STANDARD 99)

add_executable(VolunteerManagementSystem main.c src/http/Web.h src/http/Tool.c src/http/Routes.c src/http/GET.c src/http/POST.c src/http/Send.c src/volunteer/Volunteer.h src/volunteer/Crud.c src/volunteer/Map.c)

target_link_libraries(VolunteerManagementSystem ws2_32.lib)
