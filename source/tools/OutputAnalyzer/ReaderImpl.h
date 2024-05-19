#ifndef READERIMPL_H
#define READERIMPL_H

#include <string.h>

#include <vector>

#include "Reader_if.h"

#define DEFAULT_REPLICATION_NUMBER 1

class ReaderImpl : public Reader_if {
   public:
    ReaderImpl();
    ~ReaderImpl();
    void setFile(std::string filename);
    void setReplicationNumber(int replicationNumber);
    size_t getNumberOfReplications();
    Data operator[](int index) const;
    DataFileIterator begin();
    DataFileIterator end();
    size_t size();
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream& out, const Reader_if& o);

   private:
    FileIterator _begin;
    FileIterator _end;
    size_t _size;
    std::string _filename;
    int _replicationNumber = 1;
    int _firstLine;
};

#endif