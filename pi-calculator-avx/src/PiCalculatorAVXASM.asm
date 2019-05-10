DEFAULT REL

global piCalculatorAVXASM_calculate

%define STEP_COUNT 1000000
%define STEP_SIZE 1.e-6

SECTION .rodata   align=32
        indices dq      __float64__(0.5), __float64__(1.5), __float64__(2.5), __float64__(3.5)

SECTION .rodata
        stepl   dq      __float64__(STEP_SIZE)
        one     dq      __float64__(1.)
        four    dq      __float64__(4.)

SECTION .text
piCalculatorAVXASM_calculate:
        push    rbx

        mov             ebx, STEP_COUNT / 4     ; ebx := loopIndex
        vxorpd          ymm0, ymm0              ; ymm0 := sum
        vmovapd         ymm1, yword [indices]   ; ymm1 := indices
        vbroadcastsd    ymm2, qword [stepl]     ; ymm2 := stepSize
        vbroadcastsd    ymm3, qword [one]       ; ymm3 := one
        vbroadcastsd    ymm4, qword [four]      ; ymm4 := four

.L1:
        vmulpd  ymm5, ymm1, ymm2        ; ymm5 = indices * stepSize
        vmulpd  ymm5, ymm5              ; ymm5 = ymm5 * ymm5
        vaddpd  ymm5, ymm3              ; ++ymm5
        vdivpd  ymm5, ymm4, ymm5        ; ymm5 = 4. / ymm5
        vaddpd  ymm0, ymm5              ; ymm0 += ymm5
        vaddpd  ymm1, ymm4              ; indices += four

        sub     ebx, 1
        jne     .L1

        ; Horizontally sum ymm0
        vperm2f128      ymm5, ymm0, ymm0, 1     ; ymm5 = ymm0 with the lower 128 bits being swapped with the higher 128 bits
        vaddpd          ymm0, ymm5
        vhaddpd         ymm0, ymm0              ; Horizontal add X0 and X1

        mulsd           xmm0, xmm2              ; Multiply with stepSize

        ; The result is being returned in xmm0

        pop     rbx
        ret
