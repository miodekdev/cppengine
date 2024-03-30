bits 64
default rel

global AssemblyColorFromFloatArray
global AssemblyColorFromFloats
global AssemblyColorFromInt
global AssemblyColorFromByte

section .bss
    buffer          resd 4

section .data
    multiplier      times 4 dd 255.0

section .text
    AssemblyColorFromFloatArray:
        movaps      xmm0, [rcx]
        movaps      xmm1, [multiplier]
        mulps       xmm0, xmm1
        cvtps2dq    xmm0, xmm0
        packssdw    xmm0, xmm0
        packuswb    xmm0, xmm0
        movd        eax,  xmm0 ; overflows and underflows are handled automatically by saturations above
        ret

    AssemblyColorFromFloats:
        movd    [buffer+0],  xmm0 ; TODO Replace buffers with shifts
        movd    [buffer+4],  xmm1
        movd    [buffer+8],  xmm2
        movd    [buffer+12], xmm3
        lea     rcx, [buffer]
        jmp     AssemblyColorFromFloatArray
        ret

    AssemblyColorFromInt:
        mov eax, ecx
        ret

    AssemblyColorFromByte:
        mov ah, dl  ; Upon inspecting the registers when passing the Color struct through them, I have discovered that
        mov al, cl  ; their values are in a reversed order here,
        shl eax, 16 ; but everything was fine with AssemblyColorFromFloatArray. wtf? why?
        mov ah, cl  ; TODO solve the mistery
        mov al, cl
        ret