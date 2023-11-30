add_library(Rational STATIC)
target_sources(Rational
	PRIVATE Rational.cpp
	PUBLIC Rational.hpp)
target_include_directories(Rational
	PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(Rational
	PUBLIC Pair)
