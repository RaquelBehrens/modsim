
#include "ReaderImpl.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
ReaderImpl::ReaderImpl() {}

ReaderImpl::~ReaderImpl() {}

void ReaderImpl::setFile(std::string filename) {
    _filename = filename;
    setReplicationNumber(DEFAULT_REPLICATION_NUMBER);
}

void ReaderImpl::setReplicationNumber(int replicationNumber) {
    _replicationNumber = replicationNumber;
    // std::cout << replicationNumber << std::endl;
    bool start = false;
     // Verifica se o arquivo foi aberto com sucesso
    std::string linha;

    // Lê cada linha do arquivo
    FileIterator fit = FileIterator(_filename);
    while(true) {
        linha = *fit;
        if (linha.empty() || linha[0] == '#') {
            if (start == true) {
                _end = fit;
                return;
            }
            if (!linha.compare("#ReplicationNumber=" + std::to_string(_replicationNumber))) {
                start = true;
                _size = 0;
                _begin = ++fit;
            }
        }
        ++_size;
        ++fit;

    }
    if (!start) {
        throw std::runtime_error("Replicação não encontrada");
    }
}

Reader_if::Data ReaderImpl::operator[](int n) const {
    DataFileIterator dit = _begin;
    dit + n;
    return *dit;


}

Reader_if::DataFileIterator ReaderImpl::begin() {
    return _begin;
}
Reader_if::DataFileIterator ReaderImpl::end() {
    return _end;
}

size_t ReaderImpl::getNumberOfReplications() {
    int last;
  
    std::string linha;
    FileIterator fit = FileIterator(_filename);
    while (true) {
        linha = *fit;
        if (linha[0] == '#') {
            if (linha.find("#ReplicationNumber=") != std::string::npos) {
                last = stoi(linha.substr(19));
            }
        }
        if(linha.empty()) break;
        ++fit;
    }
    return last;
}

size_t ReaderImpl::size() {
    return _size;
}

std::string ReaderImpl::toString() const {
    std::stringstream oss;
    oss << std::fixed << std::setprecision(3);
    oss << "[ ";
    // for (auto entry : ) {
    //     oss << entry.value << " ";
    // }
    oss << "]";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Reader_if& obj) {
    os << obj.toString();
    return os;
}

