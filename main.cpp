#include <iostream>
#include "Chunk.h"
#include "debug.h"

int main() {

    // alright, so what did we get in chapter 1?
    // a struct Chunk
    // which has an array of code + line numbers for that
    // both of those can be modeled as std::vector
    // and an array of constant values

    // theres's also a value class, though it's just a typedef
    // then there's ValueArray, which I can just model as std::vector again

    // there's also a disassembler (in a file called "debug")
    // I don't think get much C++ mileage out of that one

    // there are MACROS for memory allocation
    // I don't think I need those?

    // ================================================
    Chunk c {};
    auto constant = c.addConstant(1.2);
    c.writeChunk(OP_CONSTANT, 123);
    c.writeChunk(constant, 123);
    c.writeChunk(OP_RETURN, 123);

    auto disassembledChunk = disassembleChunk(c, "test chunk");
    std::cout << disassembledChunk << std::endl;



//    std::cout << "Hello, World!" << std::endl;
    return 0;
}
