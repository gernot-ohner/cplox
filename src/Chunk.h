//
// Created by go on 14.09.21.
//

#ifndef CPLOX_CHUNK_H
#define CPLOX_CHUNK_H

#include <vector>
#include <cstdint>
#include "Value.h"

typedef enum {
    OP_CONSTANT,
    OP_RETURN
} OpCode;

class Chunk {
public:
    Chunk();
    ~Chunk();
    size_t addConstant(Value val);
    void writeChunk(uint8_t code, int line);
public:
    std::vector<uint8_t> code;
    std::vector<int> lines;
    std::vector<Value> constants;
};


#endif //CPLOX_CHUNK_H
