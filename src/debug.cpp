//
// Created by go on 14.09.21.
//

#include "debug.h"

std::string disassembleChunk(Chunk &c, const std::string &name) {
    std::stringstream ss;
    ss << "=== " << name << " ===\n";
    for (int offset = 0; offset < c.code.size();) {
        offset = disassembleInstruction(c, offset, ss);
    }

    return ss.str();
}

int disassembleInstruction(Chunk &c, int offset, OUT std::stringstream &ss) {
    ss << fmt::format("{:0>4} ", offset);
    ss << ((offset > 0 && c.lines[offset] == c.lines[offset - 1])
           ? "   | "
           : fmt::format("{:0>4} ", c.lines[offset]));

    uint8_t instruction = c.code[offset];
    switch (instruction) {
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset, ss);
        case OP_CONSTANT:
            return constantInstruction("OP_CONSTANT", c, offset, ss);
        default:
            return unkownInstruction(instruction, offset, ss);
    }
}

int simpleInstruction(const std::string &name, int offset, OUT std::stringstream &ss) {
    ss << name + "\n";
    return offset + 1;
}

int constantInstruction(const std::string &name, Chunk &c, int offset, OUT std::stringstream &ss) {
    uint8_t constant = c.code.at(offset + 1);
    // TODO add the value to the resulting string
    ss << fmt::format("{:<16} {:0>4} '", name, constant);

    auto value = printValue(c.constants.at(constant));
    ss << value << "\n";
    return offset + 2;
}

inline std::string printValue(Value &d) {
    return std::to_string(d);
}

inline int unkownInstruction(uint8_t instruction, int offset, OUT std::stringstream& ss) {
    ss << fmt::format("Unkown opcode %hhu\n", instruction);
    return offset + 1;
}
