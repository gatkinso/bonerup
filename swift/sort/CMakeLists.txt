set(TARGET_NAME mergesort_swift)

file(GLOB SWIFTFILES *.swift)

add_executable(${TARGET_NAME} ${SWIFTFILES})
