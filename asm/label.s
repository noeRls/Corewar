	# test de l encodage de toutes les fonctions basiques
	#
	#bismillah
	.name "romain bosa"
	.comment "just a basic prog to kick u from tek"

	live %1
	ld %:label,r1
	st r1,:label
	add r1,r2,r3
label:	sub r2,r7,r2
	and %:label,40,r1
	or :label,%1,r12
	xor %32,%12,r1
	zjmp %:ok
	ldi %4,%12,r1
	sti r1,r2,%4
	fork %16
	lld %4,r1
ok:	lldi %4,%12,r1
	lfork %:ok
	aff r3
