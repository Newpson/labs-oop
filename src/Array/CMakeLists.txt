add_library(Set STATIC)
target_sources(Set
	PRIVATE Set.cpp
	PUBLIC Set.hpp)
target_include_directories(Set
	PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_library(Array STATIC)
target_sources(Array
	PRIVATE Array.cpp
	PUBLIC Array.hpp)
target_include_directories(Array
	PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(Array
	PUBLIC Set)

add_library(OrArray STATIC)
target_sources(OrArray
	PRIVATE OrArray.cpp
	PUBLIC OrArray.hpp)
target_include_directories(OrArray
	PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(OrArray
	PUBLIC Array)

add_library(AndArray STATIC)
target_sources(AndArray
	PRIVATE AndArray.cpp
	PUBLIC AndArray.hpp)
target_include_directories(AndArray
	PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(AndArray
	PUBLIC Array)
