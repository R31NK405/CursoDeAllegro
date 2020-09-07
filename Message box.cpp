#include<allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<iostream>


int main(){

ALLEGRO_DISPLAY * display;
if(!al_init()){
    al_show_native_message_box(NULL, NULL, NULL, "Could not initialize Allegro 5", NULL, NULL);
    return -1;

}


//The function al_create_display create a display, or window, with the specified dimensions. The parameters of the display are determined by the last calls to al_set_new_display_*.
display=al_create_display(640, 480);

//The function al_set_window_position sets where the top left pixel of the client area of newly created windows (non-fullscreen) will be on screen, for displays created by the calling thread.
al_set_window_position(display, 200,100);

//  The function al_set_window_title set the title on a display.
al_set_window_title(display, "Juego");


if(!display){
     //Show a native GUI message box. This can be used for example to display an error message if creation of an initial display fails. The display may be NULL, otherwise the given display is treated as the parent if possible.
  al_show_native_message_box(display, "Sample Text", "Display Settings", "Display window was not created properly ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
  return -1;
}


//Commands used to show Dialog/Message Boxes
int value = al_show_native_message_box(display, "MessageBox Title", "error", "Display window could not be shown", NULL, ALLEGRO_MESSAGEBOX_WARN | ALLEGRO_MESSAGEBOX_YES_NO);
if (value == 1)
    std::cout << "No pus que mal" << std::endl;
else
    std::cout << "Pendejo XD" << std::endl;
    std::cout << value  << std::endl;

//The function al_rest Waits for the specified number seconds. This tells the system to pause the current thread for the given amount of time. With some operating systems, the accuracy can be in the order of 10ms.

al_rest(10.0);

al_destroy_display(display);
return 0;
}
