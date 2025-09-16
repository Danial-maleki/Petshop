cmake_minimum_required(VERSION 3.19)
project(PetShopV2 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(PetShopV2
    main.cpp
    animal.h animal.cpp
    dog.h dog.cpp
    cat.h cat.cpp
    petshop.h petshop.cpp
    chicken.h chicken.cpp
    user.h user.cpp
    superuser.h superuser.cpp
    usermanagement.h usermanagement.cpp
)

target_link_libraries(PetShopV2
    PRIVATE
        Qt::Core
)
target_link_libraries(PetShopV2 PRIVATE Qt6::Core)
target_link_libraries(PetShopV2 PRIVATE Qt6::Core)
target_link_libraries(PetShopV2 PRIVATE Qt6::Core)
target_link_libraries(PetShopV2 PRIVATE Qt6::Core)
target_link_libraries(PetShopV2 PRIVATE Qt6::Core)
target_link_libraries(PetShopV2 PRIVATE Qt6::Core)
target_link_libraries(PetShopV2 PRIVATE Qt6::Core)
target_link_libraries(PetShopV2 PRIVATE Qt6::Core)

include(GNUInstallDirs)

install(TARGETS PetShopV2
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
