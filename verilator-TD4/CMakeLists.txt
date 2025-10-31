# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.2.0)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.2.0-a4)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico2 CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(test C CXX ASM)

# RTTI有効化 (dynamic_cast用) verilator生成コードで使用するため
set(PICO_CXX_ENABLE_RTTI 1)

# Verilator生成C++ファイルの自動包含 (obj_dir/*.cpp)
file(GLOB VERILATOR_SOURCES "obj_dir/*.cpp")

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Verilator include directory
set(VERILATOR_INCUDE_DIR "C:/msys64/ucrt64/share/verilator/include")

# Add executable. Default name is the project name, version 0.1

if (TARGET tinyusb_device)
    add_executable(test
            main.cpp
            debug.cpp
            ${VERILATOR_SOURCES}  # 全生成ファイル自動追加 (Vcounter.cpp, Vcounter__Syms.cpp, Vcounter___024root.cpp など)

            verilib/verilated.cpp # ${VERILATOR_INCUDE_DIR}/verilated.cpp をコピーしてpico2用に修正したもの
    )
    # C++11以上を有効 (mutexダミー用)
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    # Verilator生成ヘッダ用インクルードディレクトリ追加
    target_include_directories(test PRIVATE . obj_dir ${VERILATOR_INCUDE_DIR} )
    # # GCCの -include オプションで自動インクルード（すべてのソースに適用）
    # target_compile_options(test PRIVATE -include stub_mutex.h)

    # dir_obj/*.cppに -include stub_mutex.h を適用
    set_source_files_properties(${VERILATOR_SOURCES} PROPERTIES COMPILE_FLAGS "-include stub_mutex.h")

    # pull in common dependencies
    target_link_libraries(test pico_stdlib pico_aon_timer hardware_flash)

    # enable usb output, disable uart output
    pico_enable_stdio_usb(test 1)
    pico_enable_stdio_uart(test 1)

    # create map/bin/hex/uf2 file etc.
    pico_add_extra_outputs(test)

    # add url via pico_set_program_url
elseif(PICO_ON_DEVICE)
    message("Skipping test because TinyUSB submodule is not initialized in the SDK")
endif()
