//
// Created by go on 14.09.21.
//

#include "Chunk.h"

Chunk::Chunk() {
    code = std::vector<uint8_t> {};
    lines = std::vector<int> {};
    constants = std::vector<Value> {};
}

// the fields are mostly vectors.
// do I really need to free those myself?
// I don't think so
Chunk::~Chunk() = default;

[[maybe_unused]] size_t Chunk::addConstant(Value val) {
    constants.push_back(val);
    return constants.size() - 1;
}

[[maybe_unused]] void Chunk::writeChunk(uint8_t newCode, int line) {
    code.push_back(newCode);
    lines.push_back(line);
}
