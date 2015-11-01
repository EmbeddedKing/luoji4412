
#define GPM4CON		(*(volatile unsigned int *)0x110002E0)
#define GPM4DAT		(*(volatile unsigned int *)0x110002E4)

void delay(volatile int time)
{
	for(; time > 0; time-- )
		;
}

int main(void)
{
	unsigned long tmp = 0;
	int i = 0;

	/*
	 *  GPM4_0-GPM4_3 ����Ϊ�������
	 */
	tmp = GPM4CON;
	tmp &= ~0xffff;
	tmp |= 0x1111;
	GPM4CON = tmp;
	
	/*
	 *  ʵ����ˮ��
	 */
	 while(1)
	 {
		GPM4DAT = i;
		if (++i == 16)
  			i = 0;
  		delay(9999999);
	 }
	

	return 0;
}
