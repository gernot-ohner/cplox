//
// Created by go on 14.09.21.
//

#ifndef CPLOX_DEBUG_H
#define CPLOX_DEBUG_H

#include <string>
#include "Chunk.h"
#include <fmt/format.h>
#include <sstream>

#define OUT

// TODO find a better name for this
typedef struct {
    std::string s;
    int offset;
} DisassembledInstruction;

// TODO how do I do this?
std::string disassembleChunk(Chunk &c, const std::string &name);
int disassembleInstruction(Chunk &c, int offset, OUT std::stringstream &ss);

int simpleInstruction(const std::string &name, int offset, OUT std::stringstream& ss);
int constantInstruction(const std::string &name, Chunk &c, int offset, OUT std::stringstream& ss);

inline int unkownInstruction(uint8_t instruction, int offset, OUT std::stringstream& ss);

std::string printValue(Value &d);

#endif //CPLOX_DEBUG_H
