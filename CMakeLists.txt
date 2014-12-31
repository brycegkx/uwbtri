PROJECT(SSUWB)
SET(SSUWB_SRCS gkxlocate.cpp rcm.cpp rcmIf.cpp rcmSampleApp.cpp ssuwb.cpp)
#IF(WIN32)
#  SET(SSUWB_SRCS ${HELLO_SRCS} WinSupport.c)
#ELSE (WIN32)
#  SET(SSUWB_SRCS ${HELLO_SRCS} UnixSupport.cpp)
#ENDIF (WIN32)

ADD_EXECUTABLE (SSUWB ${SSUWB_SRCS})
