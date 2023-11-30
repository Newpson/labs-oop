add_library(Pair STATIC)
target_sources(Pair
	PRIVATE Pair.cpp
	PUBLIC Pair.hpp)
target_include_directories(Pair
	PUBLIC ${CMAKE_CURRENT_LIST_DIR})
