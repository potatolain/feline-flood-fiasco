#include "source/menus/credits.h"
#include "source/configuration/system_constants.h"
#include "source/globals.h"
#include "source/neslib_asm/neslib.h"
#include "source/configuration/game_states.h"
#include "source/menus/text_helpers.h"
#include "source/map/map.h"

#pragma code-name ("CODE")
#pragma rodata-name ("CODE")

void draw_tempint1(void) {
    vram_put('0' + ((tempInt1 / 100) % 10) + 0x60);
    vram_put('0' +((tempInt1 / 10) % 10) + 0x60);
    vram_put('0' + ((tempInt1 % 10)) + 0x60);
}

void draw_win_screen() {
    ppu_off();
    clear_screen_with_border();
    scroll(0, 0);

    // Add whatever you want here; NTADR_A just picks a position on the screen for you. Your options are 0, 0 to 32, 30
    put_str(NTADR_A(8, 5), "Congratulations!");

    put_str(NTADR_A(9, 12), "You escaped! ");

    put_str(NTADR_A(5, 24), "Your time:       ");

    // 60 frames/second, so get down to seconds
    tempInt1 = (frameCount - gameTime) / 60;
    // Build it up in reverse...
    screenBuffer[4] = (tempInt1 % 60) % 10;
    screenBuffer[3] = (tempInt1 % 60) / 10;
    // Down to minutes
    tempInt1 /= 60;
    screenBuffer[2] = (tempInt1 % 100) % 10;
    screenBuffer[1] = (tempInt1 % 100) / 10;

    vram_put('0' + screenBuffer[1] + 0x60);
    vram_put('0' + screenBuffer[2] + 0x60);
    vram_put(':' + 0x60);
    vram_put('0' + screenBuffer[3] + 0x60);
    vram_put('0' + screenBuffer[4] + 0x60);

    tempChar1 = 0;
    put_str(NTADR_A(5, 22), coinsCollectedText);
    // Text too long, reset address
    vram_adr(NTADR_A(20, 22));
    tempInt1 = gameCollectableCount;

    // gameCollectableAvailableCount
    draw_tempint1();
    vram_put('/' + 0x60);
    tempInt1 = TOTAL_CATS;
    draw_tempint1();

    // This is your last ending screen, unless you got all cats!
    if (gameCollectableCount <= TOTAL_CATS) {
        put_str(NTADR_A(5, 17), "Thank you for playing!");
    }

    // Hide all existing sprites
    oam_clear();
    ppu_on_all();

}

void draw_credits_screen() {
    if (gameCollectableCount <= TOTAL_CATS) {
        reset();
    }
    ppu_off();
    scroll(0, 0);


    vram_adr(0x2000);
    vram_write(&creditsScreenData[0], 0x400);

    // Hide all existing sprites
    oam_clear();
    ppu_on_all();
}