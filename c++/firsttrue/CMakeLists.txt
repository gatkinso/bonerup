set(TARGET_NAME firsttrue)

file(GLOB CPPFILES *.cpp)
file(GLOB HDRFILES *.h)

add_executable(${TARGET_NAME} ${CPPFILES} ${HDRFILES})
