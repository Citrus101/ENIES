#include <iostream>
#include <cinttypes>
#include <iomanip>

uint16_t disassemble_opcode(uint8_t *code_buffer, uint16_t pc);



uint16_t disassemble_opcode(uint8_t *code_buffer, uint16_t pc){
    uint8_t opcode = code_buffer[pc];
    uint8_t bytes = 1; 

    std::cout << std::hex << std::setw(4) << std::setfill('0') << pc << " ";
    switch (opcode)
    {
    case 0x00: 
        std::cout << "BRK ";
        /* code */
        break;
    
    default:
        break;
    }

    return bytes;
}
