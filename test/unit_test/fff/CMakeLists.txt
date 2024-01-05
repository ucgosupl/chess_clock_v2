set(INCLUDE_DIRS
  .
)
add_library(fff INTERFACE) 
target_include_directories(fff INTERFACE ${INCLUDE_DIRS})