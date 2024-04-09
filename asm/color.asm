bits 64
default rel

global AssemblyRGBAFromFloatArray

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
