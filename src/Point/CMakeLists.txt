add_library(Point STATIC)
target_sources(Point
	PRIVATE Point.cpp
	PUBLIC Point.hpp
)
target_include_directories(Point
	PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)
