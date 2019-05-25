add_library(beauties flowers.cpp gems.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(beauties
    flowers.cpp
    gems.cpp
)

foreach(beau ${beauties})
    get_filename_component(bname ${beau} NAME_WE)
    add_executable(${bname} ${beau})
endforeach()
