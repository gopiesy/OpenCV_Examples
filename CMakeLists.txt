cmake_minimum_required(VERSION 2.8)
project( OpenCV_Examples )
find_package( OpenCV REQUIRED )
add_executable( bin/webcam_capture src/webcam_capture.cpp )
target_link_libraries( bin/webcam_capture ${OpenCV_LIBS} )

add_executable( bin/display_image src/display_image.cpp )
target_link_libraries( bin/display_image ${OpenCV_LIBS} )

add_executable( bin/background_substract src/background_substract.cpp )
target_link_libraries( bin/background_substract ${OpenCV_LIBS} )
