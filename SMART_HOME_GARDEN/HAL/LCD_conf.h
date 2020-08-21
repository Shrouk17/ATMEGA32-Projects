/*
 * LCD_conf.h
 *
 *  Created on: Aug 8, 2019
 *      Author: Ahmed M Salah
 */

#ifndef LCD_CONF_H_
#define LCD_CONF_H_

#define LCD_DATA_PORT      'B'
#define LCD_DATA_DIR       'B'

#define LCD_CONTROL_PORT   'B'
#define LCD_CONTROL_DIR    'B'

#define RESET              PB5
#define ENABLE             PB4

#define DISPLAY_ON_CURSOR_ON     (0x0E)
#define _4_BIT_2_LINE            (0x28)
#define DISPLAY_ON_CURSOR_OFF    (0x0C)
#define CLEAR_DISPLAY            (0x01)
#define SET_CURSOR_LOCATION      (0x80)
#define RETURN_HOME              (0x02)

#endif /* LCD_CONF_H_ */
