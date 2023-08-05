/* 
linker_script.ld for ARM-cortex-M3 
(an Application on STM32)
Learn-in-depth Unit 3 Lesson 3 Lab_2
		~Made by Mohamed Nabil~
*/

MEMORY
{
flash(RX): ORIGIN = 0X00000000, LENGTH = 512M
SRAM(RWX): ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS
{
	.text :
	{
	*(.vector*)
	*(.text*)
	*(.rodata)
	_E_text = .;
	}>flash
	.data :
	{
	_S_data = .;
	*(.data)
	. = ALIGN(4);
	_E_data = .;
	}>SRAM AT> flash
	.bss :
	{
	_S_bss = .;
	*(.bss)
	_E_bss = .;
	}>SRAM
	
}