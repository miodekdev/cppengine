bits 64
default rel

global AssemblyRGBAFromFloatArray
global AssemblyMultiplyRGBAByFloat

section .rodata
    multiplier      times 4 dd 255.0

section .text
    FloatsToBytes:
        cvtps2dq    xmm0, xmm0
        packssdw    xmm0, xmm0
        packuswb    xmm0, xmm0
        movd        eax,  xmm0
        ret

    AssemblyRGBAFromFloatArray:
        movaps      xmm0, [rcx]
        movaps      xmm1, [multiplier]
        mulps       xmm0, xmm1
        jmp         FloatsToBytes

    AssemblyMultiplyRGBAByFloat:
        movd        xmm0, ecx
        xorps       xmm2, xmm2
        punpcklbw   xmm0, xmm2
        punpcklwd   xmm0, xmm2
        cvtdq2ps    xmm0, xmm0
        shufps      xmm1, xmm1, 0
        mulps       xmm0, xmm1
        jmp         FloatsToBytes