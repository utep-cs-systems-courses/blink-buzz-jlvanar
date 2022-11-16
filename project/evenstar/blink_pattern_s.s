	.arch msp430g2553
	.p2align 1,0
	.text

	.global blink_pattern
	.extern green_on

blink_pattern:
	jz end

end:	pop r0
