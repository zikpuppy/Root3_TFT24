#include "Home.h"
#include "includes.h"

//1��title(����), ITEM_PER_PAGE��item(ͼ��+��ǩ)
const MENUITEMS homeItems = {
//   title
LABEL_HOME,
// icon                       label
#ifdef CNC_MENU //if CNC menu is selected
  {{ICON_HOME,                 LABEL_XY},
    {ICON_Z_HOME,               LABEL_Z},
    {ICON_BACKGROUND,           LABEL_BACKGROUND},
    {ICON_PROBE_OFFSET,         LABEL_PROBE_Z},
    {ICON_ZERO_X,               LABEL_ZERO_X},
    {ICON_ZERO_Y,               LABEL_ZERO_Y},
    {ICON_ZERO_Z,               LABEL_ZERO_Z},
    {ICON_BACK,                 LABEL_BACK},}
#else
  {{ICON_HOME,                 LABEL_HOME},
    {ICON_X_HOME,               LABEL_X},
    {ICON_Y_HOME,               LABEL_Y},
    {ICON_Z_HOME,               LABEL_Z},
    {ICON_BACKGROUND,           LABEL_BACKGROUND},
    {ICON_BACKGROUND,           LABEL_BACKGROUND},
    {ICON_BACKGROUND,           LABEL_BACKGROUND},
    {ICON_BACK,                 LABEL_BACK},}
#endif
  
};

void menuHome(void)
{
  KEY_VALUES key_num = KEY_IDLE;
  menuDrawPage(&homeItems);
  while(infoMenu.menu[infoMenu.cur] == menuHome)
  {
    key_num = menuKeyGetValue();
    switch(key_num)
    {
    	#ifdef CNC_MENU //if CNC menu is selected
        case KEY_ICON_0: storeCmd("G28 XY\n");   break;
        case KEY_ICON_1: storeCmd("G28 Z\n"); break;
        case KEY_ICON_3:
          // storeCmd("G92 Z0\n");
          // storeCmd("G21;"); 
          storeCmd("G38.2 Z-50 F50\n"); 
          storeCmd("G92 Z8.19\n"); 
          storeCmd("G0 Z33 F300\n"); break;
        case KEY_ICON_4: storeCmd("G92 X0\n"); break;
        case KEY_ICON_5: storeCmd("G92 Y0\n"); break;
        case KEY_ICON_6: storeCmd("G92 Z0\n"); break;
      #else
        case KEY_ICON_0: storeCmd("G28\n");   break;
        case KEY_ICON_1: storeCmd("G28 X\n"); break;
        case KEY_ICON_2: storeCmd("G28 Y\n"); break;
        case KEY_ICON_3: storeCmd("G28 Z\n"); break;
      #endif
      case KEY_ICON_7: infoMenu.cur--;      break;
      default:break;
    }
    loopProcess();
  }
}

