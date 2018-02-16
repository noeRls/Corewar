	.name "zork"
	.name "zork"
	.comment "just a basic living prog"

	sti r1,%4,r1
	and r1,%4,r1
	zjmp %:live
live:	live %1
