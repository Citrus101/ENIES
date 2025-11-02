#include <iostream>
#include <cinttypes>
#include <iomanip>

uint16_t disassemble_opcode(uint8_t *code_buffer, uint16_t pc);



uint16_t disassemble_opcode(uint8_t *code_buffer, uint16_t pc){
    uint8_t opcode = code_buffer[pc];
    uint8_t code_1 = code_buffer[pc + 1];
    uint8_t code_2 = code_buffer[pc + 2];
    uint8_t bytes = 1; 

    std::cout << std::hex << std::setw(4) << std::setfill('0') << pc << " ";
    switch (opcode)
    {
    case 0x00: 
        std::cout << "BRK " << "------" << std::endl; break;
    case 0x01: 
        std::cout << "ORA ($00"  << std::hex << code_1 << ",X)" << " NZ----" << std::endl; bytes = 2; break;
    case 0x05: 
        std::cout << "ORA $00" << std::hex << code_1 << " NZ----" << std::endl; bytes = 2; break;
    case 0x06: 
        std::cout << "ASL $00" << code_1 << " NZC---" << std::endl; bytes = 2; break;
    case 0x08: 
        std::cout << "PHP " << " ------"  << std::endl; bytes = 2; break;
    case 0x09: 
        std::cout << "ORA #" << std::hex << code_1 << " NZ----"  << std::endl; bytes = 2; break;
    case 0x0A: 
        std::cout << "ASL A" << " NZC---"  << std::endl; bytes = 1; break;
    case 0x0D: 
        std::cout << "ORA $" << std::hex <<  code_2 <<  std::hex << code_1 << " NZC---"  << std::endl; bytes = 2; break;
    case 0x0E: 
        std::cout << "ASL $" << std::hex <<  code_2 <<  std::hex << code_1 << " NZC---"  << std::endl; bytes = 2; break;
    case 0x10: 
        std::cout << "BPL $" << std::hex <<  code_2 <<  std::hex << code_1 << " ------"  << std::endl; bytes = 2; break;
    case 0x11: 
        std::cout << "ORA ($00" << std::hex <<  code_1 << "), Y" << " NZ----"  << std::endl; bytes = 2; break;
    case 0x15: 
        std::cout << "ORA $00" << std::hex <<  code_1 << ", X" << " NZ----"  << std::endl; bytes = 2; break;
    case 0x16: 
        std::cout << "ASL $00" << std::hex <<  code_1 << ", X" << " NZC---"  << std::endl; bytes = 2; break;
    case 0x18: 
        std::cout << "CLC " << std::endl; bytes = 1; break;
    case 0x19: 
        std::cout << "ORA $" << std::hex <<  code_2 <<  std::hex << code_1 << ", Y" << " NZ----"  << std::endl; bytes = 3; break;
    case 0x1D: 
        std::cout << "ORA $" << std::hex <<  code_2 <<  std::hex << code_1 << ", X" << " NZ----"  << std::endl; bytes = 3; break;
    case 0x1E: 
        std::cout << "ASL $" << std::hex <<  code_2 <<  std::hex << code_1 << ", X" << " NZC---"  << std::endl; bytes = 3; break;
    case 0x20: 
        std::cout << "JSR $" << std::hex <<  code_2 <<  std::hex << code_1 << std::endl; bytes = 3; break;
    case 0x21: 
        std::cout << "AND ($00"  << std::hex << code_1 << ",X)" << " NZ----" << std::endl; bytes = 2; break;
    case 0x24: 
        std::cout << "BIT $00"  << std::hex << code_1 << "NZCI-V" << std::endl; bytes = 2; break;
    case 0x25: 
        std::cout << "AND $00"  << std::hex << code_1 << "NZCI-V" << std::endl; bytes = 2; break;
    case 0x26: 
        std::cout << "ROL $00"  << std::hex << code_1 << "NZC---" << std::endl; bytes = 2; break;
    case 0x28: 
        std::cout << "PLP " << "NZCI-V"  << std::endl; bytes = 2; break;
    case 0x29: 
        std::cout << "AND #" << std::hex << code_1 << " NZ----"  << std::endl; bytes = 2; break;
    case 0x2A: 
        std::cout << "ROL A" << " NZC---"  << std::endl; bytes = 1; break;
    case 0x2C: 
        std::cout << "BITS $" << std::hex <<  code_2 <<  std::hex << code_1 << " NZ---V"  << std::endl; bytes = 3; break;
    case 0x2D: 
        std::cout << "AND $" << std::hex <<  code_2 <<  std::hex << code_1 << " NZ----"  << std::endl; bytes = 3; break;
    case 0x2E: 
        std::cout << "ROL $" << std::hex <<  code_2 <<  std::hex << code_1 << " NZC---"  << std::endl; bytes = 3; break;
    case 0x30: 
        std::cout << "BMI #" << std::hex << code_1 << " ------"  << std::endl; bytes = 2; break;
    case 0x31: 
        std::cout << "ORA ($00" << std::hex <<  code_1 << "), Y" << " NZ----"  << std::endl; bytes = 2; break;
    case 0x35: 
        std::cout << "AND $00" << std::hex <<  code_1 << ", X" << " NZ----"  << std::endl; bytes = 2; break;
    case 0x36: 
        std::cout << "ROL $00" << std::hex <<  code_1 << ", X" << " NZ----"  << std::endl; bytes = 2; break;
    case 0x38: 
        std::cout << "SEC " << "--C---"  << std::endl; bytes = 1; break;
    case 0x39: 
        std::cout << "AND $" << std::hex <<  code_2 <<  std::hex << code_1 << ", Y" << " NZ----"  << std::endl; bytes = 3; break;
    case 0x3D: 
        std::cout << "AND $" << std::hex <<  code_2 <<  std::hex << code_1 << ", X" << " NZ----"  << std::endl; bytes = 3; break;
    case 0x3E: 
        std::cout << "ROL $" << std::hex <<  code_2 <<  std::hex << code_1 << ", X" << " NZ----"  << std::endl; bytes = 3; break;
    case 0x40: 
        std::cout << "RTI " << "------" << std::endl; break;
    case 0x41: 
        std::cout << "EOR ($00"  << std::hex << code_1 << ",X)" << " NZ----" << std::endl; bytes = 2; break;
    case 0x45: 
        std::cout << "EOR $00"  << std::hex << code_1 << "NZ----" << std::endl; bytes = 2; break;
    case 0x46: 
        std::cout << "LSR $00"  << std::hex << code_1 << "0ZC---" << std::endl; bytes = 2; break;
    case 0x48: 
        std::cout << "PHA " << "------" << std::endl; break;
    case 0x49: 
        std::cout << "EOR #" << std::hex << code_1 << " NZ----"  << std::endl; bytes = 2; break;
    case 0x4A: 
        std::cout << "LSR A" << " 0ZC---"  << std::endl; bytes = 1; break;
    case 0x4C: 
        std::cout << "JMP $" << std::hex <<  code_2 <<  std::hex << code_1 << " ------"  << std::endl; bytes = 3; break;
    case 0x4D: 
        std::cout << "EOR $" << std::hex <<  code_2 <<  std::hex << code_1 << " NZ----"  << std::endl; bytes = 3; break;
    case 0x4E: 
        std::cout << "LSR $" << std::hex <<  code_2 <<  std::hex << code_1 << " 0ZC---"  << std::endl; bytes = 3; break;
    case 0x50: 
        std::cout << "BVC #" << std::hex << code_1 << " ------"  << std::endl; bytes = 2; break;
    case 0x51: 
        std::cout << "EOR ($00" << std::hex <<  code_1 << "), Y" << " NZ----"  << std::endl; bytes = 2; break;
    case 0x55: 
        std::cout << "EOR $00" << std::hex <<  code_1 << ", X" << " NZ----"  << std::endl; bytes = 2; break;
    case 0x56: 
        std::cout << "LSR $00" << std::hex <<  code_1 << ", X" << " NZ----"  << std::endl; bytes = 2; break;
    case 0x58: 
        std::cout << "CLI " << "------" << std::endl; break;
    case 0x59: 
        std::cout << "EOR $" << std::hex <<  code_2 <<  std::hex << code_1 << ", Y" << " NZ----"  << std::endl; bytes = 3; break;
    case 0x5D: 
        std::cout << "EOR $" << std::hex <<  code_2 <<  std::hex << code_1 << ", X" << " NZ----"  << std::endl; bytes = 3; break;
    case 0x5E: 
        std::cout << "EOR $" << std::hex <<  code_2 <<  std::hex << code_1 << ", X" << " NZ----"  << std::endl; bytes = 3; break;
    case 0x60: 
        std::cout << "RTS " << "------" << std::endl; break;
    case 0x61: 
        std::cout << "ADC ($00"  << std::hex << code_1 << ",X)" << " NZC--V" << std::endl; bytes = 2; break;
    case 0x65: 
        std::cout << "ADC $00"  << std::hex << code_1 << "NZC--V" << std::endl; bytes = 2; break;
    case 0x66: 
        std::cout << "ROR $00"  << std::hex << code_1 << "NZC---" << std::endl; bytes = 2; break;
    case 0x68: 
        std::cout << "PLA " << "NZ----" << std::endl; break;
    case 0x69: 
        std::cout << "ADC #" << std::hex << code_1 << " NZC--V"  << std::endl; bytes = 2; break;
    case 0x6A: 
        std::cout << "ROR A" << " NZC---"  << std::endl; bytes = 1; break;
    case 0x6C: 
        std::cout << "JMP ($" << std::hex <<  code_2 <<  std::hex << code_1 << ") ------"  << std::endl; bytes = 3; break;
    case 0x6D: 
        std::cout << "ADC $" << std::hex <<  code_2 <<  std::hex << code_1 << " NZC--V"  << std::endl; bytes = 3; break;
    case 0x6E: 
        std::cout << "ROR $" << std::hex <<  code_2 <<  std::hex << code_1 << " NZC---"  << std::endl; bytes = 3; break;
    case 0x70: 
        std::cout << "BVS #" << std::hex << code_1 << " ------"  << std::endl; bytes = 2; break;
    case 0x71: 
        std::cout << "ADC ($00" << std::hex <<  code_1 << "), Y" << " NZC--V"  << std::endl; bytes = 2; break;
    case 0x75: 
        std::cout << "ADC $00" << std::hex <<  code_1 << ", X" << " NZC--V"  << std::endl; bytes = 2; break;
    case 0x76: 
        std::cout << "ROR $00" << std::hex <<  code_1 << ", X" << " NZC---"  << std::endl; bytes = 2; break;
    case 0x78: 
        std::cout << "SEI " << "---I--" << std::endl; break;
    case 0x79: 
        std::cout << "ADC $" << std::hex <<  code_2 <<  std::hex << code_1 << ", Y" << " NZC--V"  << std::endl; bytes = 3; break;
    case 0x7D: 
        std::cout << "ADC $" << std::hex <<  code_2 <<  std::hex << code_1 << ", X" << " NZC--V"  << std::endl; bytes = 3; break;
    case 0x7E: 
        std::cout << "ROR $" << std::hex <<  code_2 <<  std::hex << code_1 << ", X" << " NZC--V"  << std::endl; bytes = 3; break;
    case 0x81: 
        std::cout << "STA ($00"  << std::hex << code_1 << ",X)" << " ------" << std::endl; bytes = 2; break;
    case 0x84: 
        std::cout << "STY $00"  << std::hex << code_1 << "------" << std::endl; bytes = 2; break;
    case 0x85: 
        std::cout << "STA $00"  << std::hex << code_1 << "------" << std::endl; bytes = 2; break;
    case 0x86: 
        std::cout << "STX $00"  << std::hex << code_1 << "------" << std::endl; bytes = 2; break;
    case 0x88: 
        std::cout << "DEY " << "NZ----" << std::endl; break;
    case 0x8A: 
        std::cout << "TXA " << "NZ----" << std::endl; break;
    case 0x8C: 
        std::cout << "STY $" << std::hex <<  code_2 <<  std::hex << code_1 << " ------"  << std::endl; bytes = 3; break;
    case 0x8D: 
        std::cout << "STA $" << std::hex <<  code_2 <<  std::hex << code_1 << " ------"  << std::endl; bytes = 3; break;
    case 0x8E: 
        std::cout << "STX $" << std::hex <<  code_2 <<  std::hex << code_1 << " ------"  << std::endl; bytes = 3; break;
    case 0x90: 
        std::cout << "BCC $" << std::hex << code_1 << " ------"  << std::endl; bytes = 2; break;
    case 0x91: 
        std::cout << "STA ($00" << std::hex <<  code_1 << "), Y" << " ------"  << std::endl; bytes = 2; break;
    case 0x94: 
        std::cout << "STY $00" << std::hex <<  code_1 << ", X" << " ------"  << std::endl; bytes = 2; break;
    case 0x95: 
        std::cout << "STA $00" << std::hex <<  code_1 << ", X" << " ------"  << std::endl; bytes = 2; break;
    case 0x96: 
        std::cout << "STX $00" << std::hex <<  code_1 << ", X" << " ------"  << std::endl; bytes = 2; break;
    case 0x98: 
        std::cout << "TYA " << "NZ----" << std::endl; break;
    case 0x99: 
        std::cout << "STA $" << std::hex <<  code_2 <<  std::hex << code_1 << ", Y" << " ------"  << std::endl; bytes = 3; break;
    case 0x9A: 
        std::cout << "TXS " << "------" << std::endl; break;
    case 0x9D: 
        std::cout << "STA $" << std::hex <<  code_2 <<  std::hex << code_1 << ", X" << " ------"  << std::endl; bytes = 3; break;
    case 0xA0: 
        std::cout << "LDY #" << std::hex << code_1 << " NZ----"  << std::endl; bytes = 2; break;
    case 0xA1: 
        std::cout << "LDA ($00"  << std::hex << code_1 << ",X)" << " NZ----" << std::endl; bytes = 2; break;
    case 0xA2: 
        std::cout << "LDX #" << std::hex << code_1 << " NZ----"  << std::endl; bytes = 2; break;
    case 0xA4: 
        std::cout << "LDY $00"  << std::hex << code_1 << "NZ----" << std::endl; bytes = 2; break;
    case 0xA5: 
        std::cout << "LDA $00"  << std::hex << code_1 << "NZ----" << std::endl; bytes = 2; break;
    case 0xA6: 
        std::cout << "LDX $00"  << std::hex << code_1 << "NZ----" << std::endl; bytes = 2; break;
    case 0xA8: 
        std::cout << "TAY " << "NZ----" << std::endl; break;
    case 0xA9: 
        std::cout << "LDA #" << std::hex << code_1 << " NZ----"  << std::endl; bytes = 2; break;
    case 0xAA: 
        std::cout << "TAX " << "NZ----" << std::endl; break;
    case 0xAC: 
        std::cout << "LDY $" << std::hex <<  code_2 <<  std::hex << code_1 << " NZ----"  << std::endl; bytes = 3; break;
    case 0xAD: 
        std::cout << "LDA $" << std::hex <<  code_2 <<  std::hex << code_1 << " NZ----"  << std::endl; bytes = 3; break;
    case 0xAE: 
        std::cout << "LDX $" << std::hex <<  code_2 <<  std::hex << code_1 << " NZ----"  << std::endl; bytes = 3; break;
    case 0xB0: 
        std::cout << "BCS #" << std::hex << code_1 << " ------"  << std::endl; bytes = 2; break;
    case 0xB1: 
        std::cout << "LDA ($00" << std::hex <<  code_1 << "), Y" << " NZ----"  << std::endl; bytes = 2; break;
    case 0xB4: 
        std::cout << "LDY $00" << std::hex <<  code_1 << ", X" << " NZ----"  << std::endl; bytes = 2; break;
    case 0xB5: 
        std::cout << "LDA $00" << std::hex <<  code_1 << ", X" << " NZ----"  << std::endl; bytes = 2; break;
    case 0xB6: 
        std::cout << "LDX $00" << std::hex <<  code_1 << ", X" << " NZ----"  << std::endl; bytes = 2; break;
    case 0xB8: 
        std::cout << "CLV " << "-----0" << std::endl; break;
    case 0xB9: 
        std::cout << "LDA $" << std::hex <<  code_2 <<  std::hex << code_1 << ", Y" << " NZ----"  << std::endl; bytes = 3; break;
    case 0xBA: 
        std::cout << "TSX " << "NZ----" << std::endl; break;
    case 0xBC: 
        std::cout << "LDY $" << std::hex <<  code_2 <<  std::hex << code_1 << ", X" << " NZ----"  << std::endl; bytes = 3; break;
    case 0xBD: 
        std::cout << "LDA $" << std::hex <<  code_2 <<  std::hex << code_1 << ", X" << " NZ----"  << std::endl; bytes = 3; break;
    case 0xBE: 
        std::cout << "LDX $" << std::hex <<  code_2 <<  std::hex << code_1 << ", Y" << " NZ----"  << std::endl; bytes = 3; break;
    case 0xC0: 
        std::cout << "CPY #" << std::hex << code_1 << " NZC---"  << std::endl; bytes = 2; break;
    case 0xC1: 
        std::cout << "CMP ($00"  << std::hex << code_1 << ",X)" << " NZC---" << std::endl; bytes = 2; break;
    case 0xC4: 
        std::cout << "CPY $00"  << std::hex << code_1 << "NZC---" << std::endl; bytes = 2; break;
    case 0xC5: 
        std::cout << "CMP $00"  << std::hex << code_1 << "NZC---" << std::endl; bytes = 2; break;
    case 0xC6: 
        std::cout << "DEC $00"  << std::hex << code_1 << "NZ----" << std::endl; bytes = 2; break;
    case 0xC8: 
        std::cout << "INY " << "NZ----" << std::endl; break;
    case 0xC9: 
        std::cout << "CMP #" << std::hex << code_1 << " NZC---"  << std::endl; bytes = 2; break;
    case 0xCA: 
        std::cout << "DEX " << "NZ----" << std::endl; break;
    case 0xCC: 
        std::cout << "CPY $" << std::hex <<  code_2 <<  std::hex << code_1 << " NZC---"  << std::endl; bytes = 3; break;
    case 0xCD: 
        std::cout << "CMP $" << std::hex <<  code_2 <<  std::hex << code_1 << " NZC---"  << std::endl; bytes = 3; break;
    case 0xCE: 
        std::cout << "DEC $" << std::hex <<  code_2 <<  std::hex << code_1 << " NZC---"  << std::endl; bytes = 3; break;
    case 0xD0: 
        std::cout << "BNE #" << std::hex << code_1 << " ------"  << std::endl; bytes = 2; break;
    case 0xD1: 
        std::cout << "CMP ($00" << std::hex <<  code_1 << "), Y" << " NZC---"  << std::endl; bytes = 2; break;
    case 0xD5: 
        std::cout << "CMP $00" << std::hex <<  code_1 << ", X" << " NZC---"  << std::endl; bytes = 2; break;
    case 0xD6: 
        std::cout << "DEC $00" << std::hex <<  code_1 << ", X" << " NZ----"  << std::endl; bytes = 2; break;
    case 0xD8: 
        std::cout << "CLD " << "----0-" << std::endl; break;
    case 0xD9: 
        std::cout << "CMP $" << std::hex <<  code_2 <<  std::hex << code_1 << ", Y" << " NZC---"  << std::endl; bytes = 3; break;
    case 0xDD: 
        std::cout << "CMP $" << std::hex <<  code_2 <<  std::hex << code_1 << ", X" << " NZC---"  << std::endl; bytes = 3; break;
    case 0xDE: 
        std::cout << "DEC $" << std::hex <<  code_2 <<  std::hex << code_1 << ", X" << " NZ----"  << std::endl; bytes = 3; break;
    case 0xE0: 
        std::cout << "CPX #" << std::hex << code_1 << " NZC---"  << std::endl; bytes = 2; break;
    case 0xE1: 
        std::cout << "SBC ($00"  << std::hex << code_1 << ",X)" << " NZC--V" << std::endl; bytes = 2; break;
    case 0xE4: 
        std::cout << "CPX $00"  << std::hex << code_1 << "NZC---" << std::endl; bytes = 2; break;
    case 0xE5: 
        std::cout << "SBC $00"  << std::hex << code_1 << "NZC--V" << std::endl; bytes = 2; break;
    case 0xE6: 
        std::cout << "SBC $00"  << std::hex << code_1 << "NZ----" << std::endl; bytes = 2; break;
    case 0xE8: 
        std::cout << "INX " << "NZ----" << std::endl; break;
    case 0xE9: 
        std::cout << "SBC #" << std::hex << code_1 << " NZC--V"  << std::endl; bytes = 2; break;
    case 0xEA: 
        std::cout << "NOP #" << std::hex << code_1 << " ------"  << std::endl; bytes = 2; break;
    case 0xEC: 
        std::cout << "CPX $" << std::hex <<  code_2 <<  std::hex << code_1 << " NZC---"  << std::endl; bytes = 3; break;
    case 0xED: 
        std::cout << "SBC $" << std::hex <<  code_2 <<  std::hex << code_1 << " NZC---"  << std::endl; bytes = 3; break;
    case 0xEE: 
        std::cout << "INC $" << std::hex <<  code_2 <<  std::hex << code_1 << " NZC---"  << std::endl; bytes = 3; break;
    case 0xF0: 
        std::cout << "BEQ #" << std::hex << code_1 << " ------"  << std::endl; bytes = 2; break;
    case 0xF1: 
        std::cout << "SBC ($00" << std::hex <<  code_1 << "), Y" << " NZC--V"  << std::endl; bytes = 2; break;
    case 0xF5: 
        std::cout << "SBC $00" << std::hex <<  code_1 << ", X" << " NZC--V"  << std::endl; bytes = 2; break;
    case 0xF6: 
        std::cout << "INC $00" << std::hex <<  code_1 << ", X" << " NZ----"  << std::endl; bytes = 2; break;
    case 0xF8: 
        std::cout << "SED " << "----1-" << std::endl; break;
    case 0xF9: 
        std::cout << "SBC $" << std::hex <<  code_2 <<  std::hex << code_1 << ", Y" << " NZC--V"  << std::endl; bytes = 3; break;
    case 0xFD: 
        std::cout << "SBC $" << std::hex <<  code_2 <<  std::hex << code_1 << ", X" << " NZC--V"  << std::endl; bytes = 3; break;
    case 0xFE: 
        std::cout << "INC $" << std::hex <<  code_2 <<  std::hex << code_1 << ", X" << " NZ----"  << std::endl; bytes = 3; break;
    default:
        std::cout << "UNDEFINED INSTR: " << opcode << std::endl; 
        break;
    }

    return bytes;
}
