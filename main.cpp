#include <stdio.h>
#include <iostream>
#include <list>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <time.h>     
#include "saveload.h"
#include <string>
#include "util.h"
#include "tile.h"
#include "world.h"
#include "tiles.h"
#include "world.h"

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


int main()
{
    must_init(al_init(), "Project Keystone");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_install_mouse(), "mouse");

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
    bitmap* unselectedSlot = load_bitmap("res/tex/slot_unselected.png");
    must_init(unselectedSlot, "unsel slot");
    bitmap* selectedSlot = load_bitmap("res/tex/slot_selected.png");
    must_init(selectedSlot, "sel slot");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    //Testing out the world class
    World world;

   // int maxWidth = (int)1500 / 16;
   // int maxHeight = (int)960 / 16;
    int maxWidth = (int)5;
    int maxHeight = (int)5;

    for (int x = 0; x < maxWidth; x++) {
        for (int y = 0; y < maxHeight; y++) {
            std::cout << "creating tile at "<<x<<","<<y<<"\n";
            Tile grass = GrassTile(x, y, &world);
            world.tiles.push_back(grass);
            //grassptr = nullptr;
        }
    }
    std::cout << "Total world vec len: " << world.tiles.size() << "\n";

    //Initialize world
    world.init();

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
            //tick
            world.tick();

            al_clear_to_color(al_map_rgb(0, 0, 0));
          
            //Draw the world!
             world.render();
          
          
            
            
            //UI
            al_draw_filled_rectangle(0, 95, 45, 500, al_map_rgba_f(0, 0, 0, 0.7));
            al_draw_textf(font, al_map_rgb(0, 0, 0), 0, 0, 0, "Topdown Sandbox Project  %c", version);
            

            //Inventory

            //draw slots

           // for (int i = 1; i < 11; i++) {
           //     if (i != 1) {
           //         draw_bitmap(unselectedSlot, 5, 60 + 40 * i, 0);
           //     }
           //     else {
           //         draw_bitmap(selectedSlot, 5, 60 + 40 * i, 0);
           //     }
           //     draw_bitmap(tileTextures[5], 13, 60 + 40 * i + 9, 0);
           //     al_draw_textf(font, al_map_rgb(255, 255, 255), 10, 60 + 40 * i + 5, 0, "99");
           // }

          

     





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