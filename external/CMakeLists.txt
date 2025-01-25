set(IMGUI_BUILD_GLFW_BINDING TRUE)
set(IMGUI_BUILD_OPENGL3_BINDING TRUE)

add_library(imgui)
target_sources(imgui
	PRIVATE
	imgui/imgui.cpp
	imgui/imgui_draw.cpp
	imgui/imgui_tables.cpp
	imgui/imgui_widgets.cpp
	imgui/backends/imgui_impl_glfw.cpp
	imgui/backends/imgui_impl_opengl3.cpp
	PUBLIC
	imgui/imgui.h
	imgui/backends/imgui_impl_glfw.h
	imgui/backends/imgui_impl_opengl3.h)
target_include_directories(imgui
	PUBLIC
	${CMAKE_CURRENT_LIST_DIR}/imgui
	${CMAKE_CURRENT_LIST_DIR}/imgui/backends)
# add_subdirectory(imgui)
