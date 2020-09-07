
#include<allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>
#include<iostream>

#define ScreenWidth 640
#define ScreenHeight 48

int main(){

ALLEGRO_DISPLAY * display;
if(!al_init()){
    al_show_native_message_box(NULL, NULL, NULL, "Could not initialize Allegro 5", NULL, NULL);
    return -1;

}
//The function al_set_new_display_flags Sets various flags to be used when creating new displays on the calling thread.
al_set_new_display_flags(ALLEGRO_RESIZABLE);

//The function al_create_display create a display, or window, with the specified dimensions. The parameters of the display are determined by the last calls to al_set_new_display_*.
display=al_create_display(ScreenWidth, ScreenHeight);

//The function al_set_window_position sets where the top left pixel of the client area of newly created windows (non-fullscreen) will be on screen, for displays created by the calling thread.
al_set_window_position(display, 200,100);

//  The function al_set_window_title set the title on a display.
al_set_window_title(display, "Juego");


if(!display){
     //Show a native GUI message box. This can be used for example to display an error message if creation of an initial display fails. The display may be NULL, otherwise the given display is treated as the parent if possible.
  al_show_native_message_box(display, "Sample Text", "Display Settings", "Display window was not created properly ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
  return -1;
}

al_init_primitives_addon();
al_install_keyboard();

ALLEGRO_COLOR electricBlue = al_map_rgb(44,117,255);

ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

al_register_event_source(event_queue, al_get_keyboard_event_source());


bool done = false;
int x = 10, y = 10;
int moveSpeed = 5;

int state = NULL;

while(!done){

    //An ALLEGRO_EVENT is a union of all builtin event structures, i.e. it is an object large enough to hold the data of any event type.
    ALLEGRO_EVENT events;

    //Wait until the event queue specified is non-empty. If ret_event is not NULL, the first event in the queue will be copied into ret_event and removed from the queue. If ret_event is NULL the first event is left at the head of the queue.
    al_wait_for_event(event_queue, &events);
    //Loop para reconocer el teclado
    if(events.type=ALLEGRO_EVENT_KEY_DOWN){
        switch(events.keyboard.keycode){
        case ALLEGRO_KEY_DOWN:
        y+=moveSpeed;
        break;
        case ALLEGRO_KEY_UP:
        y-=moveSpeed;
        break;
        case ALLEGRO_KEY_RIGHT:
        x+=moveSpeed;
        break;
        case ALLEGRO_KEY_LEFT:
        x-=moveSpeed;
        break;
        case ALLEGRO_KEY_ESCAPE:
        done=true;
        break;
        }
    }
    //The function al_rest Waits for the specified number seconds. This tells the system to pause the current thread for the given amount of time. With some operating systems, the accuracy can be in the order of 10ms.
al_draw_rectangle(x, y, x+5, y+5, al_map_rgb(0,0,255), 1.0);
al_flip_display();
al_clear_to_color(al_map_rgb(0,0,0));


}
al_destroy_display(display);
al_destroy_event_queue(event_queue);
return 0;
}