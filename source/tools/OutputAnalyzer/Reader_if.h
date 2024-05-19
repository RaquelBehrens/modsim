// MyClass.h (Header File)

#ifndef READER_IF
#define READER_IF

#include <bits/stdc++.h>

//TODO garantir que a stream n é modificada;
class Reader_if {
   public:
    struct Data {
        double value;
        double time;
        Data() :value{} {}

        Data(std::string linha) {
            
            std::istringstream iss(linha);
            if (linha.find(' ') != std::string::npos) {
                iss >> time >> value;
            } else {
                iss >> value;
      
            }
        }
        Data& operator=(const Data& other) {
            value = other.value;
            time = other.time;
            return *this;
        }
        bool operator==(const Data& other) { return value == other.value; }
        bool operator<(const Data& other) { return value < other.value; }
    };
    
    struct FileIterator 
    {
        using iterator_category = std::forward_iterator_tag;
        using value_type = FileIterator;
        using difference_type = std::ptrdiff_t;
        using pointer = FileIterator*;
        using reference = FileIterator&;

        FileIterator(std::string filename): pos{0} {
        
            _filename = filename;
            arquivo = std::ifstream(_filename);
        }
        FileIterator() {
   
        }

        FileIterator(const FileIterator& FileIterator) {
        
            _filename = FileIterator._filename;
            arquivo = std::ifstream(_filename);
            pos = FileIterator.pos;

        }


        std::string operator*() { 
            std::string linha;
            if(arquivo.is_open()) {
                arquivo.clear();
                arquivo.seekg(pos);
                std::getline(arquivo,linha);
                arquivo.seekg(pos);
            } else {
                throw std::runtime_error("arquivo não encontrado");
            }
            return linha;
      

        }

        // // Prefix increment
        FileIterator& operator++() {
            std::string line;
            arquivo.seekg(pos);
            getline(arquivo,line);
            pos = arquivo.tellg();
            return *this;
        }  


        // // Postfix increment
        FileIterator operator++(int) {
            FileIterator tmp = *this;
            ++(*this);
            return tmp;
        }

        FileIterator operator+(int p) {
            std::string line;
            arquivo.seekg(pos);
            for (int i = 0; i < p && getline(arquivo,line); i++)
            {}
            pos = arquivo.tellg();
            return *this;
            
        }


        FileIterator& operator=(const FileIterator& other) {
            pos = other.pos;
            _filename = other._filename;
            arquivo = std::ifstream(_filename);
            return *this;
        }

        bool operator==(const FileIterator& other) const {
            return _filename == other._filename && pos == other.pos;
        }
        
        bool operator!=(const FileIterator& other) const {
            return  _filename != other._filename || pos != other.pos;
        }    
        std::string _filename;
        std::streampos pos;
    protected:
        std::ifstream arquivo;
    };

    struct DataFileIterator : public FileIterator {
        using value_type        = DataFileIterator;
        using pointer           = DataFileIterator*;
        using reference         = DataFileIterator&;

        DataFileIterator() {}

        DataFileIterator(const FileIterator& FileIterator) {
            _filename = FileIterator._filename;
            arquivo = std::ifstream(_filename);
            pos = FileIterator.pos;
        }

        Data operator*() { 
            std::string linha;
            if(arquivo.is_open()) {

                arquivo.seekg(pos);
                std::getline(arquivo,linha);
                arquivo.seekg(pos);
            } else {
                throw std::runtime_error("arquivo não encontrado");
            }
            return Data(linha);
      

        }
    };

    // virtual void setFile(std::string fileName) = 0;
    // virtual void setReplicationNumber(int replicationNumber) = 0;
    // virtual size_t getNumberOfReplications() = 0;
    virtual Data operator[](int index) const = 0;
    virtual DataFileIterator begin() = 0;
    virtual DataFileIterator end() = 0;
    virtual size_t size() = 0;

    virtual std::string toString() const = 0;
    friend std::ostream& operator<<(std::ostream& out, const Reader_if& o);
};

#endif
