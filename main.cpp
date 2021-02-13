#include <stdio.h>
#include <iostream>
#include <list>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <time.h>     
#include "world.h"
#include "saveload.h"
#include <string>
#include "util.h"

#define bitmap ALLEGRO_BITMAP
#define load_bitmap al_load_bitmap
#define draw_bitmap al_draw_bitmap

const string version = "Proto-2";


void must_init(bool test, const char* description)
{
    if (test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

struct vector2 {
    int x;
    int y;
};

void renderTile(tile worldtile, bitmap* textures[255]) {
    switch (worldtile.type) {
    case 1:
        draw_bitmap(textures[0], worldtile.x * 16, worldtile.y * 16, 0);
        break;
    case 2:
        draw_bitmap(textures[1], worldtile.x * 16, worldtile.y * 16, 0);
        break;
    case 3:
        draw_bitmap(textures[2], worldtile.x * 16, worldtile.y * 16, 0);
        break;
    case 4:
        draw_bitmap(textures[3], worldtile.x * 16, worldtile.y * 16, 0);
        break;
    case 5:
        draw_bitmap(textures[4], worldtile.x * 16, worldtile.y * 16, 0);
        break;
    case 6:
        draw_bitmap(textures[5], worldtile.x * 16, worldtile.y * 16, 0);
        break;
    case 7:
        draw_bitmap(textures[6], worldtile.x * 16, worldtile.y * 16, 0);
        break;
    }
}
int main()
{
    must_init(al_init(), "Project Keystone");
    must_init(al_install_keyboard(), "keyboard");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");

    //Smooth
    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    ALLEGRO_DISPLAY* disp = al_create_display(1580, 960);
    must_init(disp, "display");

    ALLEGRO_FONT* font = al_create_builtin_font();
    must_init(font, "font");

    must_init(al_init_primitives_addon(), "primitives");

    must_init(al_init_image_addon(), "image addon");
    bitmap* tileTextures[255]{};
    tileTextures[0] = load_bitmap("res/dirt.png");
    must_init(tileTextures[0], "dirt");
    tileTextures[1] = load_bitmap("res/grass.png");
    must_init(tileTextures[1], "grass");
    tileTextures[2] = load_bitmap("res/sand.png");
    must_init(tileTextures[2], "sand");
    tileTextures[3] = load_bitmap("res/water.png");
    must_init(tileTextures[3], "water");
    tileTextures[4] = load_bitmap("res/leaf.png");
    tileTextures[5] = load_bitmap("res/planks.png");
    tileTextures[6] = load_bitmap("res/mossy_stone.png");

    bitmap* player = load_bitmap("res/player.png");
    must_init(player, "player");
    bitmap* slot = load_bitmap("res/slot.png");
 



    //Player init
    vector2 playerLocation = vector2{ 100,100 };
    float playerSpeed = 3;

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;
    int activeType = 1;
    ALLEGRO_EVENT event;

    //"World gen"
    std::list<tile> world;
  //  World::world world = new World();
   // 1580, 960
    srand(time(NULL));
    int maxWidth = (int)1580/16+1;
    int maxHeight = (int)960/16;


    for (int x = 0; x < maxWidth; x++) {
    
        for (int y = 0; y < maxHeight; y++) {
            
            float noiseVal = rand() % 7 + 1;

            //noiseVal = noiseVal / 10000;

            int type = noiseVal;
          // std::cout << " noise value at " << x << "," << y << ":" << noiseVal << "\n";
            //Perlin noise
            

            tile worldtile = tile{
                x,
                y,
                type
            };
            world.push_back(worldtile);
        }
    }

    al_start_timer(timer);
    while (1)
    {
        al_wait_for_event(queue, &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_TIMER:
            // game logic goes here.
            redraw = true;
            break;

        case ALLEGRO_EVENT_KEY_CHAR:
            switch(event.keyboard.keycode){
            case ALLEGRO_KEY_W:
                playerLocation.y -= playerSpeed;
                break;
            case ALLEGRO_KEY_A:
                playerLocation.x -= playerSpeed;
                break;
            case ALLEGRO_KEY_S:
                playerLocation.y += playerSpeed;
                break;
            case ALLEGRO_KEY_D:
                playerLocation.x += playerSpeed;
                break;
            case ALLEGRO_KEY_0:
                saveTileData("test", world);
            case ALLEGRO_KEY_1:
                world = loadTileData("test");
            
            }
            break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;
        }

        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));
          
            for (const tile worldtile : world) {
                renderTile(worldtile, tileTextures);
            }
            al_draw_filled_rectangle(0, 95, 45, 500, al_map_rgba_f(0, 0, 0, 0.7));
            //UI
            al_draw_textf(font, al_map_rgb(0, 0, 0), 0, 0, 0, "Keystone  %c", version);
            

            //Inventory

            //draw slots

            for (int i = 1; i < 11; i++) {
                draw_bitmap(slot, 5, 60 + 40 * i, 0);
                draw_bitmap(tileTextures[0], 13, 60 + 40 * i + 9, 0);
                al_draw_textf(font, al_map_rgb(255, 255, 255), 10, 60 + 40 * i + 5, 0, "99");
            }

            draw_bitmap(player, playerLocation.x, playerLocation.y, 0);
           // al_draw_bitmap(mysha, 100, 100, 0);

     





            al_flip_display();

            redraw = false;
        }
    }

 
    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}