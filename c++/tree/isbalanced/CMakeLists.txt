set(TARGET_NAME isbalanced)

file(GLOB CPPFILES *.cpp)
file(GLOB HDRFILES *.h)

add_executable(${TARGET_NAME} ${CPPFILES} ${HDRFILES})
