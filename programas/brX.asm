MOV <0, R0>
BRZ <#FAZDARZERO>
MOV <99, R0>
BRN <#FAZDARNEG>
FAZDARZERO: MOV <-91, R0>
BRE <#FAZDAREQU>
FAZDARNEG: CMP <R1, R2>
BRL <#FAZDARLOW>
FAZDAREQU:
FAZDARLOW:
MOV <255, R4>