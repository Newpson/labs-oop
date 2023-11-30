add_library(Polynomial STATIC)
target_sources(Polynomial
	PRIVATE Polynomial.cpp PolynomialIO.cpp
	PUBLIC Polynomial.hpp PolynomialIO.hpp)
target_include_directories(Polynomial
	PUBLIC ${CMAKE_CURRENT_LIST_DIR})

