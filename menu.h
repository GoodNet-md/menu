#ifndef  menu_h
#define   menu_h
#include "stdint.h"
#include "ST7735.h"

typedef struct 
{
    uint8_t Cur_Index;//��ǰ������
	uint8_t previous;//��һҳ
	uint8_t next;//��һҳ
	uint8_t enter;//ȷ��
	uint8_t back;//����
	void (*current_operation)(uint8_t,uint8_t);//	��ǰ����ִ�еĺ���(����)    
}menu_t;
//�˵�����
enum
{
	  Main_menu=0,
	  child1_option,
    child2_option,	
    child3_option,

    child1_parameter1option,
    child1_parameter2option,

    child1_parameter1,
    child1_parameter2,


};
//��������ֵ
enum
{
	KEY_PREVIOUS=2,
	KEY_ENTER,
	KEY_NEXT,
	KEY_BACK
};


void Main_UI(uint8_t page_index,uint8_t key_val);
void Main_menu_UI(uint8_t page_index, uint8_t key_val);
void child1_ui(uint8_t page_index,uint8_t key_val);
void child2_ui(uint8_t page_index,uint8_t key_val);
void child3_ui(uint8_t page_index,uint8_t key_val);
void GUI_refresh(void);
void parameter1change(uint8_t page_index,uint8_t key_val);
void parameter2change(uint8_t page_index,uint8_t key_val);
#endif