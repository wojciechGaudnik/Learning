#include "menu.h"
#include <stddef.h>
#include <string.h>
#include <avr\pgmspace.h>
#include "defines.h"
#include "LCD.h"

static const __flash struct _menuitem *currMenuPtr=&menu;   //Bie��ca pozycja menu
static int8_t menuindex;                                    //Numer aktualnie wybrane pozycji menu
static int8_t menufirstpos;                                 //Numer pozycji menu wy�wietlanej w g�rnym rz�dzie

uint8_t Menu_GetMenuItemsNo()            //Policz ile dane menu ma pozycji
{
	const __flash struct _menuitem *tmpmenuitem=currMenuPtr;
	uint8_t index=0;

	while(tmpmenuitem)
	{
		tmpmenuitem=tmpmenuitem->next;
		index++;
	}
	return index;
}

const __flash struct _menuitem *Menu_GetMenuItem(uint8_t index)
{
	const __flash struct _menuitem *tmpmenuitem=currMenuPtr;

	while((tmpmenuitem) && (index>0))
	{
	 tmpmenuitem=tmpmenuitem->next;
	 index--;
	}
	return tmpmenuitem;
}

uint8_t Menu_GetMenuRows()
{
	return LCD_ROWS;
}

void Menu_Show()
{
	const __flash struct _menuitem *tmpmenuitem=Menu_GetMenuItem(menufirstpos);
	uint8_t menuitemsno=Menu_GetMenuItemsNo();

	lcd_cls(); //Wyczy�� LCD

	for(uint8_t i=0; i < Menu_GetMenuRows(); i++)
	{
		lcd_goto(0, i);  //Wy�wietlany rz�d
		if(menuindex == ((menufirstpos + i) % menuitemsno)) lcd_puttext(PSTR(">")); else lcd_puttext(PSTR(" "));  //Dana pozycja menu jest zaznaczona
		lcd_puttext(tmpmenuitem->text); //Wy�wietl pozycj� menu
		if(tmpmenuitem->submenu)
		  lcd_puttext(PSTR(">>>")); //Zaznacz, �e mamy submenu
		tmpmenuitem=tmpmenuitem->next;
		if(tmpmenuitem == NULL)  //Koniec listy
		{
			if(Menu_GetMenuItemsNo() > Menu_GetMenuRows()) tmpmenuitem=currMenuPtr; //Zawijamy list� je�li jest d�u�sza ni� liczba wy�wietlanych pozycji
			   else break;   //lub ko�czymy, �eby unikn�� powtarzania element�w
		}
	}
}

void Menu_SelectNext()
{
	uint8_t no=Menu_GetMenuItemsNo();
	menuindex++;
	if(no > Menu_GetMenuRows())        //Czy liczba pozycji menu jest wi�ksza ni� liczba wy�wietlanych pozycji?
		{
			int8_t dist;               //Odleg�o�� pomi�dzy pierwsz� wy�wietlan� pozycj�, a pozycj� pod�wietlon�
			if(menuindex < menufirstpos) dist=no - menufirstpos + menuindex; //Jest zale�na od tego, kt�a z pozycji jest wi�ksza
			   else dist=menuindex-menufirstpos;
			if(dist >= Menu_GetMenuRows()) menufirstpos++;  //Koniec ekranu, trzeba przewija�
		}
	menuindex%=no;     //Liczymy wszysko modulo liczba pozycji w menu
	menufirstpos%=no;
	Menu_Show();      //Wy�wietl menu
}

void Menu_SelectPrev()
{
	if(menuindex > 0)
	{
		if(menuindex == menufirstpos) menufirstpos--;
		menuindex--;               //Poprzedni element
	}
	 else
	{
		if(menufirstpos == 0)
		{
			menuindex=Menu_GetMenuItemsNo()-1;  //Zawijamy menu
			if(Menu_GetMenuItemsNo()>Menu_GetMenuRows()) menufirstpos=menuindex;  //Je�li mamy mniej pozycji menu ni� linii na LCD to nie zmieniamy numeru pierwszej pozycji menu
		} else menuindex=Menu_GetMenuItemsNo()-1;
	}
	Menu_Show();     //Wy�wietl menu
}

void Menu_Back()
{
	menufirstpos=0;
	menuindex=0;
	currMenuPtr=currMenuPtr->parent;
}

void Menu_Click()
{
	const __flash struct _menuitem *tmpmenuitem=Menu_GetMenuItem(menuindex);
	const __flash struct _menuitem *submenu=tmpmenuitem->submenu;

    menuitemfuncptr mfptr=tmpmenuitem->menuitemfunc;
	if(mfptr) (*mfptr)();
	if(submenu)
	 {
	  currMenuPtr=submenu;
	  menuindex=0;
	  menufirstpos=0;
     }
    Menu_Show();
}
