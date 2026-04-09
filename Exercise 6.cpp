#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Logger {
public:
    virtual ~Logger() {}
    virtual void logMessage(const string& message) = 0;
};

class ConsoleLogger : public Logger {
public:
    void logMessage(const string& message) override {
        cout << "[Console Logger] " << message <<  endl;
    }
};

class FileLogger : public Logger {
public:
    void logMessage(const string& message) override {
        cout << "[File Logger] Writing to file: " << message << endl;
    }
};

class DatabaseLogger : public Logger {
public:
    void logMessage(const string& message) override {
        cout << "[Database Logger] Inserting record: " << message << endl;
    }
};

int main() {
    ConsoleLogger console;
    FileLogger file;
    DatabaseLogger db;

    vector<Logger*> loggers;
    loggers.push_back(&console);
    loggers.push_back(&file);
    loggers.push_back(&db);

    for (Logger* logger : loggers) {
        logger->logMessage("System initialization complete.");
    }

    return 0;
}