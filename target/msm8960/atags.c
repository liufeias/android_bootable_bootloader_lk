/* Copyright (c) 2009-2011, Code Aurora Forum. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Code Aurora nor
 *       the names of its contributors may be used to endorse or promote
 *       products derived from this software without specific prior written
 *       permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NON-INFRINGEMENT ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#define SIZE_1M     (1024 * 1024)
#define SIZE_141M	(141 * SIZE_1M)
#define SIZE_768M	(768 * SIZE_1M)
#define SIZE_256M	(256 * SIZE_1M)

#define EBI1_CH0_CS0_HLOS_ADDR	0x80200000
#define EBI1_CH1_CS0_HLOS_ADDR	0x90000000

unsigned* target_atag_mem(unsigned* ptr)
{
	/* ATAG_MEM */
	*ptr++ = 4;
	*ptr++ = 0x54410002;
	*ptr++ = SIZE_141M;
	*ptr++ = EBI1_CH0_CS0_HLOS_ADDR;

	*ptr++ = 4;
	*ptr++ = 0x54410002;
	*ptr++ = SIZE_256M;
	*ptr++ = EBI1_CH1_CS0_HLOS_ADDR;

	return ptr;
}

void *target_get_scratch_address(void)
{
	return((void *)EBI1_CH1_CS0_HLOS_ADDR);
}

unsigned target_get_max_flash_size(void)
{
	return (SIZE_256M);
}