#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <vector>
#include <iostream>
#include <fstream>


void _proto() {};

using func_t = decltype(_proto);
constexpr size_t sc_size = 0x1000;


// No UAC bypass for now since its pretty niche and not particularly intellectually stimulating 
int main() {

    freopen(nullptr, "rb", stdin);

    //WOOOOOWWW real creative huh
    LPVOID shellcode = VirtualAlloc(NULL, sc_size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!shellcode)
        return -ENOMEM;
    //not actually sure if this works but whatever
    size_t bytes_read = std::fread(reinterpret_cast<char*>(shellcode), sizeof(char), sc_size, stdin);
    func_t* shellcode_fn = reinterpret_cast<func_t*>(shellcode);

    shellcode_fn();
    return 0;

}
