
#include<allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>

#define ScreenWidth 640
#define ScreenHeight 480

int main(){

ALLEGRO_DISPLAY * display;

const float FPS = 60.0;

enum Direction{ UP, DOWN, LEFT, RIGHT };

if(!al_init())
    al_show_native_message_box(NULL, NULL, NULL, "Could not initialize Allegro 5", NULL, NULL);

display=al_create_display(ScreenWidth, ScreenHeight);

if(!display)
    al_show_native_message_box(display, "Sample Text", "Display Settings", "Display window was not created properly ", NULL, ALLEGRO_MESSAGEBOX_ERROR);

al_set_window_position(display, 200,200);

bool done = false, draw=true;
int x = 10, y = 10, moveSpeed = 5;
int dir = DOWN;

al_init_primitives_addon();
al_install_keyboard();

ALLEGRO_KEYBOARD_STATE state;

ALLEGRO_TIMER *timer = al_create_timer(1.0/FPS);
ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
al_register_event_source(event_queue, al_get_keyboard_event_source());
al_register_event_source(event_queue, al_get_timer_event_source(timer));
al_register_event_source(event_queue, al_get_display_event_source(display));

al_start_timer(timer);

while(!done)
{
    ALLEGRO_EVENT events;
    al_wait_for_event(event_queue, &events);

    if(events.type=ALLEGRO_EVENT_KEY_UP)
    {
        switch(events.keyboard.keycode)
        {
        case ALLEGRO_KEY_ESCAPE:
        done=true;
        break;
        }
    }


//Despues del loop del manejo del teclado:
ALLEGRO_EVENT_DISPLAY_CLOSE: The close button of the window has been pressed.
    else if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
        done=true;
    }

     if(events.type=ALLEGRO_EVENT_TIMER)
     {
        al_get_keyboard_state(&state);
        {
        if(al_key_down(&state, ALLEGRO_KEY_DOWN))
        y+=moveSpeed;
        else  if(al_key_down(&state, ALLEGRO_KEY_UP))
        y-=moveSpeed;
        else if(al_key_down(&state, ALLEGRO_KEY_RIGHT))
        x+=moveSpeed;
        else if(al_key_down(&state, ALLEGRO_KEY_LEFT))
        x-=moveSpeed;
        }

        draw=true;
    }
    if(draw)
    {
//The function al_rest Waits for the specified number seconds. This tells the system to pause the current thread for the given amount of time. With some operating systems, the accuracy can be in the order of 10ms.
draw=false;
al_draw_rectangle(x, y, x+20, y+20, al_map_rgb(0,0,255), 5.0);
al_flip_display();
al_clear_to_color(al_map_rgb(0,0,0));

    }
}
al_destroy_display(display);
al_destroy_timer(timer);
al_destroy_event_queue(event_queue);

}
