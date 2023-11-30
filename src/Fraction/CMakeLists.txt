add_library(Fraction STATIC)
target_sources(Fraction
	PRIVATE Fraction.cpp
	PUBLIC Fraction.hpp)
target_include_directories(Fraction
	PUBLIC ${CMAKE_CURRENT_LIST_DIR})
