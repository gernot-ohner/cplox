//
// Created by go on 14.09.21.
//

#include "debug.h"
#include <fmt/format.h>
#include <sstream>


std::string disassembleChunk(Chunk &c, const std::string& name) {
    std::stringstream ss;
    ss << "=== " << name << " ===\n";
    for (int offset = 0; offset < c.code.size();) {
        auto d = disassembleInstruction(c, offset);
        offset = d.offset;
        ss << d.s;
    }

    return ss.str();
}

DisassembledInstruction disassembleInstruction(Chunk &c, int offset) {
    std::stringstream ss;
    ss << fmt::format("{:0>4} ", offset);

    if (offset > 0 && c.lines[offset] == c.lines[offset - 1]) {
        ss << "   | ";
    } else {
        ss << fmt::format("{:0>4} ", c.lines[offset]);
    }

    uint8_t instruction = c.code[offset];
    switch (instruction) {
        case OP_RETURN: {
            auto instruction1 = simpleInstruction("OP_RETURN", offset);
            ss << instruction1.s;
            instruction1.s = ss.str();
            return instruction1;
        }
        case OP_CONSTANT: {
            auto instruction1 = constantInstruction("OP_CONSTANT", c, offset);
            ss << instruction1.s;
            instruction1.s = ss.str();
            return instruction1;
        }
        default: {
            auto instruction1 = unkownInstruction(instruction, offset);
            ss << instruction1.s;
            instruction1.s = ss.str();
            return instruction1;
        }
    }
}

DisassembledInstruction simpleInstruction(const std::string &name, int offset) {
    return (DisassembledInstruction) {
            .s = name + "\n",
            .offset = offset + 1
    };
}

DisassembledInstruction constantInstruction(const std::string &name, Chunk &c, int offset) {
    uint8_t constant = c.code.at(offset + 1);
    std::string value = printValue(c.constants.at(constant));
    // TODO add the value to the resulting string
    DisassembledInstruction d{
            .s = fmt::format("{:<16} {:0>4} '", name, constant) + value + "\n",
            .offset = offset + 2
    };
    return d;
}

std::string printValue(Value &d) {
    // TODO fix that when you have internet access...
    return std::to_string(d);
}

inline DisassembledInstruction unkownInstruction(uint8_t instruction, int offset) {
    return (DisassembledInstruction) {
            .s = fmt::format("Unkown opcode %hhu\n", instruction),
            .offset = offset + 1
    };
}
