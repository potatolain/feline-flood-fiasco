#include "source/neslib_asm/neslib.h"
#include "source/menus/title.h"
#include "source/globals.h"
#include "source/configuration/game_states.h"
#include "source/configuration/system_constants.h"
#include "source/menus/text_helpers.h"
#include "source/map/map.h"
#include "source/sprites/player.h"

#pragma code-name ("CODE")
#pragma rodata-name ("CODE")

// Draws custom data from the patched area onto the screen, then moves on.
void draw_title_screen() {
	set_vram_update(NULL);
    ppu_off();

	oam_clear();

	vram_adr(0x2000);
	vram_write(&(titleScreenData[0]), 0x400);
    

	ppu_on_all();

	playerGridPositionX = 6;
	playerGridPositionY = 3;
	// Aim the player down to start
	playerSpriteTileId = 0x40;

	playerDirection = SPRITE_DIRECTION_DOWN;

	gameState = GAME_STATE_TITLE_INPUT;
}

void handle_title_input(void) {

	while (1) {
		tempChar1 = pad_poll(0);
		if (tempChar1 & PAD_START) {
			break;
		}
		ppu_wait_nmi();
		update_player_sprite();
	}
}