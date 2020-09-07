
#include<allegro5/allegro.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/allegro_primitives.h>


#define ScreenWidth 640
#define ScreenHeight 480

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

//al_init_primitives_addon(); Initializes the primitives addon.
al_init_primitives_addon();

ALLEGRO_COLOR electricBlue = al_map_rgb(44,117,255);

float points [8]={0, 0, 100, 400, 150, 200, ScreenWidth, ScreenHeight};

//al_draw_triangle: Draws an outlined triangle.
//al_draw_triangle(115, 220, 35, 140, 120, 75, al_map_rgb(255,0,0), 1.0);
al_draw_filled_triangle(115, 220, 35, 140, 120, 75, al_map_rgb(255,0,0));
//al_draw_rounded_rectangle: Draws an outlined rounded rectangle.
//al_draw_rounded_rectangle(40, 40, 20, 20, 15, 15, al_map_rgb(0,255,0), 3);
al_draw_filled_rounded_rectangle(40, 40, 20, 20, 15, 15, al_map_rgb(0,255,0));
//al_draw_rectangle: Draws an outlined rectangle.
//al_draw_rectangle(250, 250, 400, 400, al_map_rgb(0,0,255), 9.0);
al_draw_filled_rectangle(250, 250, 400, 400, al_map_rgb(0,0,255));
//al_draw_circle(: Draws an outlined circle.
//al_draw_circle(ScreenWidth/2, ScreenHeight/2, 90, al_map_rgb(255,255,0), 3.0);
al_draw_filled_circle(ScreenWidth/2, ScreenHeight/2, 90, al_map_rgb(255,255,0));
//al_draw_ellipse: Draws an outlined ellipse.
//al_draw_ellipse(ScreenWidth/2, ScreenHeight-100, 60, 30, al_map_rgb(0,255,255), 3.0);
al_draw_filled_ellipse(ScreenWidth/2, ScreenHeight-100, 60, 30, al_map_rgb(0,255,255));
//al_draw_arc: Draws an arc.
al_draw_arc(120, 135, 20, 0, 4.0, al_map_rgb(255,0,255), 3);

al_draw_line(100,350,200,400, electricBlue, 5.0);

al_draw_pixel(300,300, electricBlue);

al_draw_spline(points, electricBlue, 5.0);

//The function al_rest Waits for the specified number seconds. This tells the system to pause the current thread for the given amount of time. With some operating systems, the accuracy can be in the order of 10ms.
al_flip_display();
al_rest(10.0);

al_destroy_display(display);
return 0;
}



