#include "log.h"

namespace logger {

Logger &Logger::instance() {
    static Logger inst;
    return inst;
}
void Logger::set_level(Level level) { this->level = level; }
void Logger::debug(const std::string &message) {
    this->write(Level::DEBUG, message);
}
void Logger::info(const std::string &message) {
    this->write(Level::INFO, message);
}
void Logger::warn(const std::string &message) {
    this->write(Level::WARN, message);
}
void Logger::error(const std::string &message) {
    this->write(Level::ERR, message);
}
void Logger::critical(const std::string &message) {
    this->write(Level::CRITICAL, message);
}

void Logger::write(Level level, const const std::string &message) {
    if (level < this->level)
        return;
}

void debug(const std::string &message) { Logger::instance().debug(message); }
void info(const std::string &message) { Logger::instance().info(message); }
void warn(const std::string &message) { Logger::instance().warn(message); }
void error(const std::string &message) { Logger::instance().error(message); }
void critical(const std::string &message) {
    Logger::instance().critical(message);
}
} // namespace logger
