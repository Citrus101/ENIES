#include <cinttypes>

typedef struct{
    uint8_t     carry:1;
    uint8_t     zero:1;
    uint8_t     di:1; // disable interrupt
    uint8_t     rsvd:1; // decimal mode
    uint8_t     brk_cmd:1;
    uint8_t     ovrflw:1;
    uint8_t     neg:1;
}status_flags;

class cpu6502
{
private:
    /* data */
public:
    cpu6502(/* args */);
    ~cpu6502();

public:
    int cpu6502::unexpected_instruction();
    int cpu6502::process_state(uint8_t opcode);

public:  // REGISTERS
    uint8_t a;
    uint8_t x;
    uint8_t y;
    uint16_t stack = 0x100;
    uint16_t pc;
    status_flags status_reg;
    uint8_t *memory;

};

cpu6502::cpu6502(/* args */)
{
}

cpu6502::~cpu6502()
{
}


