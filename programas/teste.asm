INICIO:
MEIO:
FIM: CMP <R0,                                               R1>
MOV <4, R0>
SUBT:
SUB <4, (R0)>
BRZ <#FIM>
ADD <(R0), R1>
NOTR: ADD <(R0), (R1)>
ADD <R0, (R1)>
JMP <#NOTR>
;só comentando..
ADD <R0, (R1)> ; tem nada demais, tem?
