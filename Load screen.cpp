#include<allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>

int main(){

ALLEGRO_DISPLAY * display;
if(!al_init()){
    al_show_native_message_box(NULL, NULL, NULL, "Could not initialize Allegro 5", NULL, NULL);

}

//The function al_create_display create a display, or window, with the specified dimensions. The parameters of the display are determined by the last calls to al_set_new_display_*.
display=al_create_display(640, 480);


if(!display){
     //Show a native GUI message box. This can be used for example to display an error message if creation of an initial display fails. The display may be NULL, otherwise the given display is treated as the parent if possible.
  al_show_native_message_box(NULL, "Sample Text", "Display Settings", "Allegro window was not created properly", NULL, NULL);
  return -1;
}

return 0;
}
