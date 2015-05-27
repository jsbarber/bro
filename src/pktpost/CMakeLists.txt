
include(BroSubdir)

include_directories(BEFORE
                    ${CMAKE_CURRENT_SOURCE_DIR}
                    ${CMAKE_CURRENT_BINARY_DIR}
)

set(pktpost_SRCS
    Component.cc
    Manager.cc
)

bro_add_subdir_library(pktpost ${pktpost_SRCS})
add_dependencies(bro_pktpost generate_outputs)

