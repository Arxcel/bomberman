file(GLOB_RECURSE GLOBBED_INCLUDES "*.hpp" "*.h" )
set(BOMBERMAN_SOURCES ${BOMBERMAN_SOURCES} ${GLOBBED_INCLUDES} PARENT_SCOPE)