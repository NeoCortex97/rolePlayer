include_directories(${INCLUDE_DIR})

add_library(TermUtils SHARED TermUtils.cpp)
add_library(TestFunctions SHARED TestFunctions.cpp)
add_library(TextUtils SHARED TextUtils.cpp)
add_library(FileUtils SHARED FileUtils.cpp)
add_library(AdvLexer SHARED AdvLexer.cpp)

# Set dependencies for FileUtils
add_dependencies(FileUtils TextUtils)
target_link_libraries(FileUtils TextUtils)

# Set dependencies for TestFunctions
add_dependencies(TestFunctions FileUtils)
target_link_libraries(TestFunctions FileUtils)

#link_directories(${CMAKE_SOURCE_DIR}/bin/libs)

# RolePlayer main executable
add_executable(rolePlayer rolePlayer.cpp)
add_dependencies(rolePlayer
                  TermUtils
                  TextUtils
                  FileUtils
                  AdvLexer
                  TestFunctions
                )
target_link_libraries(rolePlayer
                        TermUtils
                        TextUtils
                        FileUtils
                        AdvLexer
                        TestFunctions
                      )

# Testing functions from librarys
add_executable(apiTest Testing.cpp)
add_dependencies(apiTest
                  TestFunctions
                )
target_link_libraries(apiTest
                      TestFunctions
                    )
