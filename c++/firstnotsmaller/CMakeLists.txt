set(TARGET_NAME firstnotsmaller)

file(GLOB CPPFILES *.cpp)
file(GLOB HDRFILES *.h)

add_executable(${TARGET_NAME} ${CPPFILES} ${HDRFILES})
