find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

set(SOURCE_FILES main.cpp
	cg_gl_error_checker.cpp
	shader.cpp
	stb_image.cpp
	texture.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)
target_link_libraries(${PROJECT_NAME}
                        ${OPENGL_LIBRARIES}
                        glfw
                        Cg
                        CgGL)
