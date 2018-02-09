	#
	#zork.s for corewar
	#
	#Bob Byla,
	#
	#Sat Nov 1° 03:24:30 2081
	#
	.name "zork"
	.comment "just a basic living prog"

l2:	sti r1,%:live,%1
	and r1,%0,r1
live:	live %1
	zjmp %:live
