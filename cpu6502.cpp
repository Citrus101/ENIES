#include <iostream>

#include "cpu6502.hpp"

int cpu6502::unexpected_instruction(){

    std:: cout << "Unexpected instruction found at :" <<  this -> pc << "\n";
    return 1;
}

int cpu6502::process_state(uint8_t opcode){
    int cycles = 1;
   switch (opcode)
   {
   case 0x00: break; //NOP
   default: cycles += unexpected_instruction();

   }

   return cycles = 1;
}