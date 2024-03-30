bits 64
default rel

global AsmVectorDistance
global AsmVectorMagnitude
global AsmVectorNormalized
global AsmBodyApplySpeed

section .text
    AsmVectorDistance:
    movq    xmm0, rcx
    movq    xmm1, rdx
    subps   xmm0, xmm1
    mulps   xmm0, xmm0
    haddps  xmm0, xmm0
    sqrtss  xmm0, xmm0
    ret

    AsmVectorMagnitude:
    movd    xmm0, [rcx]
    add     rcx,  4
    movd    xmm1, [rcx]
    mulss   xmm0, xmm0
    mulss   xmm1, xmm1
    addss   xmm0, xmm1
    sqrtss  xmm0, xmm0
    ret

    AsmVectorNormalized:
    movq     xmm3, [rcx]
    call     AsmVectorMagnitude
    movsldup xmm0, xmm0
    divps    xmm3, xmm0
    movq     rax, xmm3
    ret

    AsmBodyApplySpeed:
    movq    xmm0, [rcx]
    add     rcx,  8
    movq    xmm1, [rcx]
    addps   xmm0, xmm1
    sub     rcx,  8
    movq    [rcx], xmm0
    ret