bits 64
default rel

global AssemblyRGBAFromFloatArray
global AssemblyRGBAFromFloats
global AssemblyRGBAFromInt
global AssemblyRGBAFromByte


section .bss
    buffer          resd 4

section .data
    multiplier      times 4 dd 255.0

section .text
    AssemblyRGBAFromFloatArray:
        movaps      xmm0, [rcx]
        movaps      xmm1, [multiplier]
        mulps       xmm0, xmm1
        cvtps2dq    xmm0, xmm0
        packssdw    xmm0, xmm0
        packuswb    xmm0, xmm0
        movd        eax,  xmm0 ; overflows and underflows are handled automatically by saturations above
        ret

    AssemblyRGBAFromFloats:
        movd    [buffer+0],  xmm0 ; TODO Replace buffers with shifts
        movd    [buffer+4],  xmm1
        movd    [buffer+8],  xmm2
        movd    [buffer+12], xmm3
        lea     rcx, [buffer]
        jmp     AssemblyRGBAFromFloatArray
        ret

    AssemblyRGBAFromInt:
        mov eax, ecx
        ret

    AssemblyRGBAFromByte:
        mov ah, dl  ; The return value here is expected in little endian, but in functions above it is in big endian.
        mov al, cl  ; wtf? why?
        shl eax, 16 ;
        mov ah, cl  ; TODO solve the mistery
        mov al, cl
        ret