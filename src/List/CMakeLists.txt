add_library(List INTERFACE)
target_sources(List
	PUBLIC List.hpp List.tcc)
target_include_directories(List
	INTERFACE
	${CMAKE_CURRENT_LIST_DIR})
