#ifndef _LOGGER_H_
#define _LOGGER_H_

// Include this after declaring CitraPrint

enum LogLevel {
    L_TRACE,
    L_DEBUG,
    L_INFO,
    L_WARN,
    L_ERROR,
    L_FATAL,
};
#define SELECTED_LOG_LEVEL L_INFO

enum LogGroup {
    L_MAIN     = 1,
    L_ENEMIZER = 1,
    L_OBJECTS  = 1,
};

#define LOG(group, level, string, ...) \
    (group && (level >= SELECTED_LOG_LEVEL) ? CitraPrint(string __VA_OPT__(, __VA_ARGS__)) : (void)0)

#endif //_LOGGER_H_
