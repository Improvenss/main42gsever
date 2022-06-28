# Install script for directory: /Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/imgui-sfml-src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/imgui-sfml-build/libImGui-SFML.dylib")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libImGui-SFML.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libImGui-SFML.dylib")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/sfml-build/lib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libImGui-SFML.dylib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libImGui-SFML.dylib")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/imgui-sfml-src/imgui-SFML.h"
    "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/imgui-sfml-src/imgui-SFML_export.h"
    "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/imgui-sfml-src/imconfig-SFML.h"
    "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/imgui-src/imconfig.h"
    "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/imgui-src/imgui.h"
    "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/imgui-src/imgui_internal.h"
    "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/imgui-src/imstb_rectpack.h"
    "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/imgui-src/imstb_textedit.h"
    "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/imgui-src/imstb_truetype.h"
    "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/imgui-src/misc/cpp/imgui_stdlib.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ImGui-SFML/ImGui-SFMLConfig.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ImGui-SFML/ImGui-SFMLConfig.cmake"
         "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/imgui-sfml-build/CMakeFiles/Export/lib/cmake/ImGui-SFML/ImGui-SFMLConfig.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ImGui-SFML/ImGui-SFMLConfig-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/ImGui-SFML/ImGui-SFMLConfig.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/ImGui-SFML" TYPE FILE FILES "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/imgui-sfml-build/CMakeFiles/Export/lib/cmake/ImGui-SFML/ImGui-SFMLConfig.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/ImGui-SFML" TYPE FILE FILES "/Users/yuandre/Desktop/main42gsever/projes/main/5push_swap_all_git_samples/push_swap_git_tjensen/push_swap_visualizer/build/_deps/imgui-sfml-build/CMakeFiles/Export/lib/cmake/ImGui-SFML/ImGui-SFMLConfig-noconfig.cmake")
  endif()
endif()

