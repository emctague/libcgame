add_library(libcgame SHARED libcgame.c cgmem.c)
target_link_libraries(libcgame SDL2_image SDL2)
