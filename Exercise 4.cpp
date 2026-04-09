#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <cerrno>

using namespace std;

class FileNotFoundException : public exception{
public:
    const char* what() const noexcept override {
        return "Error: File not found.";
    }
};

class PermissionErrorException : public exception{
public:
    const char* what() const noexcept override {
        return "Error: File permission denied.";
    }
};

class FileHandler {
private:
    fstream file;

public:
    FileHandler() {}

    ~FileHandler(){
        close();
    }

    void open(const string& filename, ios_base::openmode mode) {
        file.open(filename, mode);
        
        if (!file.is_open()){
            if (errno == ENOENT) {
                throw FileNotFoundException();
            } else if (errno == EACCES) {
                throw PermissionErrorException();
            } else {
                throw runtime_error("Error: Failed to open file due to an unknown error.");
            }
        }
    }

    string read() {
        if (!file.is_open()){
            throw runtime_error("Error: No file is currently open.");
        }

        string content;
        string line;
        while (getline(file, line)){
            content += line + "\n";
        }
        return content;
    }

    void write(const string& data){
        if (!file.is_open()) {
            throw runtime_error("Error: Cannot write. No file is currently open.");
        }

        file << data;
        
        if (file.fail()){
            throw PermissionErrorException();
        }
    }

    void close(){
        if (file.is_open()) {
            file.close();
        }
    }
};

int main(){
    FileHandler handler;

    try{
        handler.open("missing_file.txt", ios::in);
    } catch (const exception& e) {
        cout << "Caught Exception: " << e.what() << endl;
    }

    try {
        handler.open("my_data.txt", ios::out);
        handler.write("Writing data to the file.\n");
        handler.close();

        handler.open("my_data.txt", ios::in);
        cout << "File Content:\n" << handler.read();
        handler.close();
    } catch (const exception& e) {
        cout << "Caught Exception: " << e.what() << endl;
    }

    return 0;
}