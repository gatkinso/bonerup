set(TARGET_NAME mergesort)

file(GLOB CPPFILES *.cpp)
file(GLOB HDRFILES *.h)

add_executable(${TARGET_NAME} ${CPPFILES} ${HDRFILES})
