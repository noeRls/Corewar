.name "bomb"
.comment "fork"

test:
	ld 42,r10
	ld 1,r11
	ld 34,r12
	ld 2,r13
	ld 255,r2
	sti r1,%:mainloop,%1

mainloop:	live %1
	add r10,r11,r10
	add r12,r13,r12
	sti r12,%34,r10
	sti r12,%42,r10
	fork %34
	ld 255,r2
	zjmp %:mainloop
