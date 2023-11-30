add_library(Money STATIC)
target_sources(Money
	PRIVATE Money.cpp
	PUBLIC Money.hpp)
target_include_directories(Money
	PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(Money
	PUBLIC Fraction)
