#include <iostream>
#include "cpu6052.hpp"

int cpu6502::unexpected_instruction(){

    std:: cout << "Unexpected instruction found at :" <<  this -> pc << "\n";
    return 1;
}

int cpu6502::process_state(uint8_t opcode){
   switch (opcode)
   {
   case 0x00: break; //NOP
   default: unexpected_instruction();

   }
}