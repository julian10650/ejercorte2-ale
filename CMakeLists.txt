cmake_minimum_required(VERSION 3.10)

project(EjerciciosCorte2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test_twitter
    tests/test_twitter.cpp
)

add_executable(test_spreadsheet
    tests/test_spreadsheet.cpp
)

add_executable(test_queen_attack
    tests/test_queen_attack.cpp
    corte2_ent2/exercism/queen_attack/queen_attack.cpp
)

add_executable(test_robot_simulator
    tests/test_robot_simulator.cpp
    corte2_ent2/exercism/robot_simulator/robot_simulator.cpp
)
