add_executable(point)
target_sources(point
	PRIVATE point.cpp)
target_link_libraries(point
	PUBLIC Point)

add_executable(polynomial)
target_sources(polynomial
	PRIVATE polynomial.cpp)
target_link_libraries(polynomial
	PUBLIC Polynomial)

add_executable(fraction)
target_sources(fraction
	PRIVATE fraction.cpp)
target_link_libraries(fraction
	PUBLIC Fraction)

find_package(OpenGL)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)
add_executable(money)
target_sources(money
	PRIVATE money.cpp)
target_link_libraries(money
	PUBLIC Money imgui OpenGL::GL ${GLFW_LIBRARIES})

add_executable(rational)
target_sources(rational
	PRIVATE rational.cpp)
target_link_libraries(rational
	PUBLIC Rational)

add_executable(array)
target_sources(array
	PRIVATE array.cpp)
target_link_libraries(array
	PUBLIC AndArray OrArray)

add_executable(list)
target_sources(list
	PRIVATE list.cpp)
target_link_libraries(list
	PUBLIC List)
