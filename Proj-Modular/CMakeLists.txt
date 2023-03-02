cmake_minimum_required(VERSION 3.10)    # 設定最低版本要求

project(Modular_main)   # 專案名稱

set(CMAKE_CXX_STANDARD 11)  # 要求 C++11 標準

add_executable( MyApp 
    main.cpp 
    function.cpp 
    Window.h
)    # 執行檔名叫 MyApp，原始碼 main.cpp


