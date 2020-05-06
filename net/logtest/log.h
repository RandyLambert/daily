#ifndef SSXRVER_BASE_LOG_H
#define SSXRVER_BASE_LOG_H
#include <string>
#include <memory>
namespace ssxrver
{

class LogEvent
{
public:
    LogEvent();

private:
    cosnt char *file_ = nullptr;
    int32_t threadId_ = 0;
    uint32_t fiberId_ = 0;
    uint64_t time_;
    std::string content_;
};

//日志器
class Logger
{
public:
    typedef std::shared_ptr<Logger> ptr;
    enum
    {
        DEBUG = 1,
        INFO = 2,
        WARN = 3,
        ERROR = 4,
        FATAL = 5
    };
    Logger();
    void log(Level level, const LogEvent)

        private:
};

//日志输出地
class LogAppender
{
public:
    virtual ~LogAppender() {}

private:
};

class LogFormatter
{
};
} // namespace ssxrver

#endif
