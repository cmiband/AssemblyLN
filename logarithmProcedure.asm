section .text use32

global	_naturalLogarithm

_naturalLogarithm:

    %idefine a [ebp+8]
    %idefine b [ebp+12]

    push ebp
    mov ebp, esp

    finit
    fld dword a
    fldln2
    fxch
    fyl2x

    fld1
    mov ecx, b
    multiplyLoop:
        fmul dword [tenNum]
        loop multiplyLoop

    fmul st1, st0

    fxch st1
    frndint

    fdiv st1

    leave
    ret

;section .data
    tenNum dd 10.0