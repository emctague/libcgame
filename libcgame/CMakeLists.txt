include(GNUInstallDirs)
find_package(PkgConfig REQUIRED)

add_library(cgame SHARED src/libcgame.c src/cgmem.c)

pkg_check_modules(SDL2 REQUIRED sdl2 SDL2_image)

target_link_libraries(cgame SDL2_image ${SDL2_LIBRARIES})

target_include_directories(cgame PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
	PRIVATE ${SDL2_INCLUDE_DIRS}
)

target_compile_options(cgame PUBLIC ${SDL2_CFLAGS_OTHER})

set_target_properties(cgame PROPERTIES 
	VERSION ${PROJECT_VERSION}
	SOVERSION 1
	PUBLIC_HEADER include/libcgame.h)

configure_file(cgame.pc.in cgame.pc @ONLY)

install(TARGETS cgame
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(FILES ${CMAKE_BINARY_DIR}/cgame.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
