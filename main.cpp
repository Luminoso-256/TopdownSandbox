#include <stdio.h>
#include <iostream>
#include <list>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <time.h>     
#define bitmap ALLEGRO_BITMAP
#define load_bitmap al_load_bitmap
#define draw_bitmap al_draw_bitmap
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

struct tile
{
    int x;
    int y;
    int type;
};

int main()
{
    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");

    //Smooth
    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    ALLEGRO_DISPLAY* disp = al_create_display(640, 480);
    must_init(disp, "display");

    ALLEGRO_FONT* font = al_create_builtin_font();
    must_init(font, "font");

    must_init(al_init_primitives_addon(), "primitives");

    must_init(al_init_image_addon(), "image addon");
    ALLEGRO_BITMAP* mysha = al_load_bitmap("mysha.png");
    must_init(mysha, "mysha");
    bitmap* dirt = load_bitmap("dirt.png");
    must_init(dirt, "dirt");
    bitmap* grass = load_bitmap("grass.png");
    must_init(grass, "grass");
    bitmap* sand = load_bitmap("sand.png");
    must_init(sand, "sand");
    bitmap* water = load_bitmap("water.png");
    must_init(water, "water");
    bitmap* player = load_bitmap("player.png");
    must_init(player, "playyer");

    //Player init
    vector2 playerLocation = vector2{ 100,100 };
    float playerSpeed = 3;

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    //"World gen"
    std::list<tile> world;
    srand(time(NULL));
    int maxWidth = (int)50;
    int maxHeight = (int)50;


    for (int x = 0; x < maxWidth; x++) {
    
        for (int y = 0; y < maxHeight; y++) {
            
            float noiseVal = rand() % 4 + 1;

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
            //al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, "Hello world!");




            for (const tile worldtile : world) {
                switch (worldtile.type) {
                case 1:
                   // std::cout << "drawing dirt \n";
                    draw_bitmap(dirt, worldtile.x * 16, worldtile.y * 16, 0);
                    break;
                case 2:
                   // std::cout << "drawing sand \n";
                    draw_bitmap(sand, worldtile.x * 16, worldtile.y * 16, 0);
                    break;
                case 3:
                   // std::cout << "drawing grass \n";
                    draw_bitmap(grass, worldtile.x * 16, worldtile.y * 16, 0);
                    break;
                case 4:
                    draw_bitmap(water, worldtile.x * 16, worldtile.y * 16, 0);
                    break;
                }
            }

            draw_bitmap(player, playerLocation.x, playerLocation.y, 0);
           // al_draw_bitmap(mysha, 100, 100, 0);

     





            al_flip_display();

            redraw = false;
        }
    }

    al_destroy_bitmap(mysha);
    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}