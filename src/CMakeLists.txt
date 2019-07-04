# Bring in/build our library components...
ADD_SUBDIRECTORY(lib)

# Now declare runit's executables proper...
ADD_EXECUTABLE(socklog socklog.c)
TARGET_LINK_LIBRARIES(socklog socklog_runtime)

ADD_EXECUTABLE(socklog-check socklog-check.c)
TARGET_LINK_LIBRARIES(socklog-check socklog_runtime)

ADD_EXECUTABLE(socklog-conf socklog-conf.c)
TARGET_LINK_LIBRARIES(socklog-conf socklog_runtime)

ADD_EXECUTABLE(tryto tryto.c)
TARGET_LINK_LIBRARIES(tryto socklog_runtime)

ADD_EXECUTABLE(uncat uncat.c)
TARGET_LINK_LIBRARIES(uncat socklog_runtime)
   
# Set destinations for things...binaries should go in /usr/sbin or /usr/local/sbin...
INSTALL(TARGETS
    socklog
    socklog-check
    socklog-conf
    tryto
    uncat
    DESTINATION ${CMAKE_INSTALL_SBINDIR})
