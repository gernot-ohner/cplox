//
// Created by go on 14.09.21.
//
#include "catch.hpp"
#include "../src/Chunk.h"
#include "../src/debug.h"

TEST_CASE("can disassemble a constant + return") {
    // given
    Chunk c{};
    auto constant = c.addConstant(1.2);
    c.writeChunk(OP_CONSTANT, 123);
    c.writeChunk(constant, 123);
    c.writeChunk(OP_RETURN, 123);

    std::string expected = "=== test chunk ===\n0000 0123 OP_CONSTANT      0000 '1.200000\n0002    | OP_RETURN\n";

    // when
    auto disassembledChunk = disassembleChunk(c, "test chunk");

    // then
    REQUIRE(disassembledChunk == expected);
}
