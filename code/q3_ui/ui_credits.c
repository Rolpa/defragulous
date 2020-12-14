/*
===========================================================================
Copyright (C) 1999-2010 id Software LLC, a ZeniMax Media company.

This file is part of Spearmint Source Code.

Spearmint Source Code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 3 of the License,
or (at your option) any later version.

Spearmint Source Code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Spearmint Source Code.  If not, see <http://www.gnu.org/licenses/>.

In addition, Spearmint Source Code is also subject to certain additional terms.
You should have received a copy of these additional terms immediately following
the terms and conditions of the GNU General Public License.  If not, please
request a copy in writing from id Software at the address below.

If you have questions concerning this license or the applicable additional
terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc.,
Suite 120, Rockville, Maryland 20850 USA.
===========================================================================
*/
//
/*
=======================================================================

CREDITS

=======================================================================
*/


#include "ui_local.h"


typedef struct {
	menuframework_s	menu;
	int frame;
} creditsmenu_t;

static creditsmenu_t	s_credits;


/*
===============
UI_CreditMenu_Draw_ioq3
===============
*/
static void UI_CreditMenu_Draw_ioq3( void ) {
	int		y;
	int		i;

	static const char *names[] = {
		"",
		S_COLOR_WHITE "John Carmack and id Software",
		S_COLOR_WHITE "ioquake3 contributors",
		S_COLOR_WHITE "Spearmint contributors",
		S_COLOR_WHITE "OpenArena contributors",
		"...and many, many others!",  // keep this one last.
		NULL
	};

	// Center text vertically on the screen
	y = (SCREEN_HEIGHT - ARRAY_LEN(names) * (1.42 * PROP_HEIGHT * PROP_SMALL_SIZE_SCALE)) / 2;

	UI_DrawProportionalString( 320, y, "Special thanks to:", UI_CENTER|UI_SMALLFONT, color_white );
	y += 1.42 * PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;

	for (i = 0; names[i]; i++) {
		UI_DrawProportionalString( 320, y, names[i], UI_CENTER|UI_SMALLFONT, color_white );
		y += 1.42 * PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	}

	UI_DrawString( 320, 439, "http://www.openarena.ws/smfnews.php", UI_CENTER|UI_SMALLFONT, colorGreen );
	UI_DrawString( 320, 459, "https://clover.moe/spearmint", UI_CENTER|UI_SMALLFONT, colorGreen );
}


/*
=================
UI_CreditMenu_Key
=================
*/
static sfxHandle_t UI_CreditMenu_Key( int key ) {
	if( key & K_CHAR_FLAG ) {
		return 0;
	}

	s_credits.frame++;
	if (s_credits.frame == 1) {
		s_credits.menu.draw = UI_CreditMenu_Draw_ioq3;
	} else {
		trap_Cmd_ExecuteText( EXEC_APPEND, "quit\n" );
	}
	return 0;
}


/*
===============
UI_CreditMenu_Draw
===============
*/
static void UI_CreditMenu_Draw( void ) {
	int		y;

	y = 12;
	UI_DrawProportionalString( 320, y, "DEFRAGULOUS", UI_CENTER|UI_SMALLFONT, color_white );

	y += 1.42 * PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	UI_DrawProportionalString( 320, y, "Written for 7dfps 2020", UI_CENTER|UI_SMALLFONT, color_white );
	y += PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	UI_DrawProportionalString( 320, y, "Thanks for playing!", UI_CENTER|UI_SMALLFONT, color_white );

	// y += 1.42 * PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	// UI_DrawProportionalString( 320, y, "", UI_CENTER|UI_SMALLFONT, color_white );
	// y += PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	// UI_DrawProportionalString( 320, y, "Adrian Carmack, Kevin Cloud,", UI_CENTER|UI_SMALLFONT, color_white );
	// y += PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	// UI_DrawProportionalString( 320, y, "Kenneth Scott, Seneca Menard, Fred Nilsson", UI_CENTER|UI_SMALLFONT, color_white );

	// y += 1.42 * PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	// UI_DrawProportionalString( 320, y, "Game Designer", UI_CENTER|UI_SMALLFONT, color_white );
	// y += PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	// UI_DrawProportionalString( 320, y, "Graeme Devine", UI_CENTER|UI_SMALLFONT, color_white );

	// y += 1.42 * PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	// UI_DrawProportionalString( 320, y, "Level Design", UI_CENTER|UI_SMALLFONT, color_white );
	// y += PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	// UI_DrawProportionalString( 320, y, "Tim Willits, Christian Antkow, Paul Jaquays", UI_CENTER|UI_SMALLFONT, color_white );

	// y += 1.42 * PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	// UI_DrawProportionalString( 320, y, "CEO", UI_CENTER|UI_SMALLFONT, color_white );
	// y += PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	// UI_DrawProportionalString( 320, y, "Todd Hollenshead", UI_CENTER|UI_SMALLFONT, color_white );

	// y += 1.42 * PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	// UI_DrawProportionalString( 320, y, "Director of Business Development", UI_CENTER|UI_SMALLFONT, color_white );
	// y += PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	// UI_DrawProportionalString( 320, y, "Marty Stratton", UI_CENTER|UI_SMALLFONT, color_white );

	// y += 1.42 * PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	// UI_DrawProportionalString( 320, y, "Biz Assist and id Mom", UI_CENTER|UI_SMALLFONT, color_white );
	// y += PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	// UI_DrawProportionalString( 320, y, "Donna Jackson", UI_CENTER|UI_SMALLFONT, color_white );

	// y += 1.42 * PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	// UI_DrawProportionalString( 320, y, "Development Assistance", UI_CENTER|UI_SMALLFONT, color_white );
	// y += PROP_HEIGHT * PROP_SMALL_SIZE_SCALE;
	// UI_DrawProportionalString( 320, y, "Eric Webb", UI_CENTER|UI_SMALLFONT, color_white );

	y += 1.35 * PROP_HEIGHT * PROP_SMALL_SIZE_SCALE * 14;
	UI_DrawString( 320, y, "(c) 2020 Stefano Pinti", UI_CENTER|UI_SMALLFONT, color_red );
	y += SMALLCHAR_HEIGHT;
	UI_DrawString( 320, y, "https://itch.io/jam/7dfps-2020", UI_CENTER|UI_SMALLFONT, color_red );
}


/*
===============
UI_CreditMenu
===============
*/
void UI_CreditMenu( void ) {
	memset( &s_credits, 0 ,sizeof(s_credits) );

	s_credits.menu.draw = UI_CreditMenu_Draw;
	s_credits.menu.key = UI_CreditMenu_Key;
	s_credits.menu.fullscreen = qtrue;
	UI_PushMenu ( &s_credits.menu );
}
