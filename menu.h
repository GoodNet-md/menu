#ifndef  menu_h
#define   menu_h
#include "stdint.h"
#include "ST7735.h"

typedef struct 
{
    uint8_t Cur_Index;//当前索引项
	uint8_t previous;//上一页
	uint8_t next;//下一页
	uint8_t enter;//确认
	uint8_t back;//返回
	void (*current_operation)(uint8_t,uint8_t);//	当前索引执行的函数(界面)    
}menu_t;
//菜单索引
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
//按键索引值
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