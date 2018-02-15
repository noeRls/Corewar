	# test de l encodage de toutes les fonctions basiques
	#
	#bismillah
	.name "romain bosa"
	.comment "just a basic prog to kick u from tek"

	live %1
	ld %4,r1
	st r1,23
	add r1,r2,r3
	sub r2,r7,r2
	and %23,40,r1
	or 12,%1,r12
	xor %32,%12,r1
	zjmp %4
	ldi %4,%12,r1
	sti r1,r2,%4
	fork %16
	lld %4,r1
	lldi %4,%12,r1
	lfork %16
	aff r3
