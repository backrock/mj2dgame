cmake_minimum_required(VERSION 3.4.1)

set(lib_src_DIR ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI})
include_directories(
     ${CMAKE_SOURCE_DIR}/src/main/cpp/include
     ${CMAKE_SOURCE_DIR}/src/main/cpp/MJ
)
add_library(sdl2_lib SHARED IMPORTED)
set_target_properties(sdl2_lib PROPERTIES IMPORTED_LOCATION
    ${lib_src_DIR}/libSDL2.so)
add_library(sdl2_image SHARED IMPORTED)
set_target_properties(sdl2_image PROPERTIES IMPORTED_LOCATION
        ${lib_src_DIR}/libSDL2_image.so)
#add_library(jpeg STATIC IMPORTED)
#set_target_properties(jpeg PROPERTIES IMPORTED_LOCATION
#        ${lib_src_DIR}/libjpeg.a)
#add_library(png STATIC IMPORTED)
#set_target_properties(png PROPERTIES IMPORTED_LOCATION
#        ${lib_src_DIR}/libpng.a)
#add_library(webp STATIC IMPORTED)
#set_target_properties(webp PROPERTIES IMPORTED_LOCATION
#        ${lib_src_DIR}/libwebp.a)
#add_library(libc++_shared SHARED IMPORTED)
#set_target_properties(libc++_shared PROPERTIES IMPORTED_LOCATION
#        ${lib_src_DIR}/libc++_shared.so)
#add_library(libmain SHARED IMPORTED)
#set_target_properties(libmain PROPERTIES IMPORTED_LOCATION
#        ${lib_src_DIR}/libmain.so)

#add_definitions(-std=c++11)
#SET(CMAKE_C_COMPILER g++)
#add_compile_options(-std=c++11)

add_library( main  SHARED
             src/main/cpp/MJ/Btn.cpp
         src/main/cpp/MJ/BtnUnion.cpp
         src/main/cpp/MJ/ImgUnion.cpp
         src/main/cpp/MJ/Mj.cpp
         src/main/cpp/MJ/MjView.cpp
         src/main/cpp/MJ/Mjplayer.cpp
         src/main/cpp/MJ/View.cpp
        src/main/cpp/MJ/main.cpp
          src/main/cpp/SDL_android_main.c
             )

find_library(log-lib    log )
find_library(GLESv1_CM-lib    GLESv1_CM )
find_library(GLESv2-lib    GLESv2 )

target_link_libraries( main
                       ${log-lib}
                       ${GLESv1_CM-lib}
                       ${GLESv2-lib}
                       sdl2_lib sdl2_image
                       )
