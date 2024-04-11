bits 64
default rel

global AssemblyDrawRounded
global AssemblyDrawPrecise

section .bss
    buffer resd 2

section .text
    AssemblyDrawRounded: ; TODO
        mov [buffer+0], ecx
        mov [buffer+4], edx
        movaps xmm0, [buffer]
        cvtps2dq xmm0, xmm0
        movd xmm1, r10d
        mulps xmm0, xmm1
        haddps xmm0, xmm0
        movd eax, xmm0
        add rax, r9
        mov [rax], r8

    AssemblyDrawPrecise: ; TODO
        ret