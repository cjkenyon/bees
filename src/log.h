#pragma once
#include <string>

namespace logger {

enum class Level {
    INFO,
    DEBUG,
    WARN,
    ERR,
    CRITICAL,
};

class Logger {
  public:
    static Logger &instance();

    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

    void set_level(Level level);
    void debug(const std::string &message);
    void info(const std::string &message);
    void warn(const std::string &message);
    void error(const std::string &message);
    void critical(const std::string &message);

  private:
    Logger() = default;

    void write(Level level, const std::string &message);

    Level level = Level::WARN;
};

void debug(const std::string &message);
void info(const std::string &message);
void warn(const std::string &message);
void error(const std::string &message);
void critical(const std::string &message);

} // namespace logger
