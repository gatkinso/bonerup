set(TARGET_NAME maxdepth)

file(GLOB CPPFILES *.cpp)
file(GLOB HDRFILES *.h)

add_executable(${TARGET_NAME} ${CPPFILES} ${HDRFILES})
