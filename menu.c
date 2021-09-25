
#include"menu.h"

uint8_t cur_index = Main_menu;   //当前页面索引值
uint8_t last_index= Main_menu;    //上一个页面索引值
uint8_t key_val ; 
void (*current_operation_func)(uint8_t,uint8_t);   //定义一个函数指针
int8_t parameter1,parameter2;

//索引表  描述菜单间的关系  这里结构体顺序要与菜单索引枚举顺序相同
//Cur_Index,previous,next,enter,back,(*current_operation)(u8,u8)
menu_t table[20] = {
    //主界面
    {Main_menu,Main_menu,Main_menu,child1_option,Main_menu,Main_UI},
    //主菜单
    {child1_option,child3_option,child2_option,child1_parameter1option,Main_menu,Main_menu_UI},
    {child2_option,child1_option,child3_option,child2_option,Main_menu,Main_menu_UI},
    {child3_option,child2_option,child1_option,child3_option,Main_menu,Main_menu_UI},

    //child1菜单
    {child1_parameter1option,child1_parameter2option,child1_parameter2option,child1_parameter1,child1_option,child1_ui},
    {child1_parameter2option,child1_parameter1option,child1_parameter1option,child1_parameter2,child1_option,child1_ui},
    //参数1 修改
    {child1_parameter1,child1_parameter1,child1_parameter1,child1_parameter1,child1_parameter1option,parameter1change},
     //参数2 修改
     {child1_parameter2,child1_parameter2,child1_parameter2,child1_parameter2,child1_parameter2option,parameter2change},
};
void GUI_refresh(void)  //刷新界面，只有按下才刷新
{
    last_index=cur_index;//更新上一界面索引值
	switch(key_val)//更新索引值
	{
		  case KEY_PREVIOUS:cur_index=table[cur_index].previous;
					break;
			case KEY_ENTER:cur_index=table[cur_index].enter;
					break;
			case KEY_NEXT:cur_index=table[cur_index].next;
					break;
			case KEY_BACK:cur_index=table[cur_index].back;
					break;
			default:break;
	}
		LCD_Clear(backcolor);
	
	current_operation_func=table[cur_index].current_operation;
	(*current_operation_func)(cur_index,key_val);  //执行当前索引对应的函数
}
void Main_UI(uint8_t page_index,uint8_t key_val)
{
    LCD_showstr(20,50,"helloworld!");
}
void Main_menu_UI(uint8_t page_index, uint8_t key_val)
{
    LCD_showstr(30,0,"main_menu");
    LCD_showstr(20,50,"child1_menu");
    LCD_showstr(20,100,"child2_menu");
    LCD_showstr(20,150,"child3_menu");
    switch(cur_index)
    {
        case child1_option: 
                LCD_showchar(10,35,'*');
                break;
        case child2_option: 
                LCD_showchar(10,65,'*');
                break;
        case child3_option: 
                LCD_showchar(10,100,'*');
                break;
    }
}
void child1_ui(uint8_t page_index,uint8_t key_val)
{
    LCD_showstr(30,0,"child1_menu");
    LCD_showstr(20,50,"parameter1");
    LCD_showstr(20,100,"parameter2");
    switch (cur_index)
    {
        case child1_parameter1option:
                 LCD_showchar(10,35,'*');
                 break;
        case child1_parameter2option:
              LCD_showchar(10,65,'*');
                break;
    }
}
void child2_ui(uint8_t page_index,uint8_t key_val)
{
 LCD_showstr(30,0,"child2_menu");
}
void child3_ui(uint8_t page_index,uint8_t key_val)
{
 LCD_showstr(30,0,"child3_menu");
}

void parameter1change(uint8_t page_index,uint8_t key_val)
{
    LCD_showstr(30,0,"parameter1:");
    LCD_showint8(35,20,parameter1);
    switch (key_val)
    {
         case KEY_PREVIOUS: parameter1++;
					break;
	     case KEY_NEXT:     parameter1--;
					break;
        default:
					break;
    }
}
void parameter2change(uint8_t page_index,uint8_t key_val)
{
    LCD_showstr(30,0,"parameter2:");
    LCD_showint8(35,20,parameter2);
    switch (key_val)
    {
         case KEY_PREVIOUS: parameter2++;
					break;
	     case KEY_NEXT:     parameter2--;
					break;
         default:
					break;
    }
}