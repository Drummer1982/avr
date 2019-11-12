/*
 * valik01.c
 *
 * Created: 06.11.2019 6:39:07
 * Author : drummer
 */ 



#define F_CPU 1000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>

uint8_t display[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};

int main (void){
	DDRD=0xff;
	
	
	
	TCCR0=(1<<CS00)|(1<<CS02);	
		
		TCNT0=0;
		TIMSK=TIMSK|(1<<TOIE0);
		
		sei();
	//��� ��������� �������
	while(1){
	}
}

ISR(TIMER0_OVF_vect){
	volatile static uint8_t counter=0;//��������� ����������� ���������� ������� � ������������� �� �����, volatile ������� ����������� �� �������������� ����������
	PORTD=display[counter];
	if(counter>=7)counter=0;//���� ������� ������ ��� ����� 8, �� ���������� ������� ���������
	
	else {//� ��������� ������
		counter=counter+1;//���������� ������� ��������� ���� ���� ���� 1
		//PORTD=display[counter];//����� � ����������� �������� ������ ������� � ����������� �� �������� � ���������� �������
		/*_delay_ms(1000);*/
	};
}
	



