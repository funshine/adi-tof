cmake_minimum_required(VERSION 3.0)
project(examples)

add_subdirectory(first-frame)
add_subdirectory(data_collect)
if (NOT NXP)
    add_subdirectory(tof-viewer)
endif()

if (WITH_NETWORK)
    add_subdirectory(first-frame-network)
endif()
add_subdirectory(point_cloud)

include(GNUInstallDirs)

if (NXP)
    install(PROGRAMS
        $<TARGET_FILE:first-frame>
        $<TARGET_FILE:data_collect>
        DESTINATION ${CMAKE_INSTALL_BINDIR} )
elseif(WIN32)
    install(PROGRAMS
        $<TARGET_FILE:first-frame>
        $<TARGET_FILE:data_collect>
        $<TARGET_FILE:ADIToFGUI>
        DESTINATION ${CMAKE_INSTALL_BINDIR} )
endif()
