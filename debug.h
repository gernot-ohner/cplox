//
// Created by go on 14.09.21.
//

#ifndef CPLOX_DEBUG_H
#define CPLOX_DEBUG_H

#include <string>
#include "Chunk.h"

// TODO find a better name for this
typedef struct {
    std::string s;
    int offset;
} DisassembledInstruction;

// TODO how do I do this?
std::string disassembleChunk(Chunk& c, const std::string& name);
DisassembledInstruction disassembleInstruction(Chunk& c, int offset);

DisassembledInstruction simpleInstruction(const std::string& name, int offset);
DisassembledInstruction constantInstruction(const std::string& name, Chunk& c, int offset);

inline DisassembledInstruction unkownInstruction(uint8_t instruction, int offset);

std::string printValue(Value &d);

#endif //CPLOX_DEBUG_H
