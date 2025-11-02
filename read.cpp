// #include <iostream>
// #include <stdio.h>
// #include <fstream>
// #include <vector>
// #include <iomanip>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
using namespace std;

// int main(void){

//     std::cout << "Hello, World!" << std::endl;
//     string text;

//     ifstream f("Donkey Kong 3 (World).nes", std::ios::binary);
    
//     std::vector<unsigned char> data(
//         (std::istreambuf_iterator<char>(f)),
//         std::istreambuf_iterator<char>()
//     );

//     f.close();

//     // Example: print first 16 bytes (the iNES header)
//     for(int j=0;j<data.size();j+=16){
//         printf("%04X    ", j);

//         for (int i = j; i < (j + 16) && i < data.size(); ++i) {

//             printf("%02X ", data[i]);

//         }

//         printf("\n");

//     }
//     return 0;
// }


int main(void) {
    FILE *file = fopen("Donkey Kong 3 (World).nes", "rb");

    if (!file) {
        perror("Error opening file");
        return 1;
    }

    // Find file size
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    // Allocate buffer and read data
    uint8_t *buffer = (uint8_t *)malloc(size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return 1;
    }

    size_t bytesRead = fread(buffer, 1, size, file);
    fclose(file);

    if (bytesRead != size) {
        fprintf(stderr, "Error reading file\n");
        free(buffer);
        return 1;
    }

    printf("File size: %ld bytes\n", size);
    printf("First byte: %02X\n", buffer[0]);

    // Use buffer[i] to access bytes, e.g. disassemble from buffer[0x10]
    // ...

    free(buffer);
    return 0;
}