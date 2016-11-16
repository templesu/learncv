cmake_minimum_required(VERSION 3.0)
project (learnCV)
find_package(OpenCV REQUIRED)
find_package(GDCM REQUIRED)
add_executable(learnCV learnCV)
include_directories(${OPENCV_INCLUDES} ${GDCM_USE_FILE})
IF(GDCM_FOUND)
	INCLUDE(${GDCM_USE_FILE})
	SET(GDCM_LIBRARIES
            gdcmcharls
            gdcmCommon
            gdcmDICT
            gdcmDSED
            gdcmexpat
            # gdcmgetopt
            gdcmIOD
            gdcmjpeg12
            gdcmjpeg16
            gdcmjpeg8
            gdcmMEXD
            gdcmMSFF
            gdcmopenjpeg
            gdcmzlib)
ENDIF(GDCM_FOUND)
target_link_libraries(learnCV ${OpenCV_LIBS} ${GDCM_LIBRARIES})