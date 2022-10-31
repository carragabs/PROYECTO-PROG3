#include <iostream>
#include <string>
#include <cstring>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <Windows.h>

using namespace std;


int jugar();
int menu();
int ancho = 768;
int alto = 576;

ALLEGRO_DISPLAY* ventana;
ALLEGRO_EVENT_QUEUE* event_queue;

int jugar() {

	cout << "Click en boton jugar";
	ALLEGRO_FONT* Triforce = al_load_font("Fonts/Triforce.ttf",62 , 0);
	ALLEGRO_FONT* Triforce1 = al_load_font("Fonts/Triforce.ttf", 23, 0);
	ALLEGRO_BITMAP* Nivel1 = al_load_bitmap("Imagenes/Mapa2.jpg");
	while (true)
	{

			ALLEGRO_EVENT Evento;

			al_wait_for_event(event_queue, &Evento);
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(Nivel1, 0, 0, 0);

			//al_draw_(200, 200, 100, al_map_rgb(255, 255, 255));
			al_draw_text (Triforce, al_map_rgb(0, 0, 0),250, 1, NULL, "Historia:");
			al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 1,63, NULL,"En el reino de Hyrule, la trifuerza un objeto deseado por muchas personas,");
			al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 1, 93, NULL,"algunas intentando dominarse del mundo. Dos bandos,los empiristas y los racionalistas");
			al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 1, 123, NULL,"apoderarse de ese poder para demostrar quien es superior, en una lucha");
			al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 1, 153, NULL,"constante.Link, un mercenario en busca de trabajo, este se topa");
			al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 1, 183, NULL,"con dos personas que estan en peligro, corriendo a su llamado de auxilio,");
			al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 1, 213, NULL,"Link elige ayudar a estas dos personas.");
			al_draw_text(Triforce, al_map_rgb(0, 0, 0), 250, 375, NULL, "Jugar");
			al_flip_display();


		}

	return 1;
}



int main() {

	if (!al_init()) {
		al_show_native_message_box(NULL, "ERROR CRITICO", "ERROR: 404", "No se pudo cargar correctamente la libreria alelgro", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}
	
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_install_mouse();
	al_init_image_addon();

	//ALLEGRO_DISPLAY* ventana = al_create_display(800, 600);
	//ALLEGRO_FONT*Triforce=al_load_font("Fonts/Triforce.ttf", 70, 0);




	ventana = al_create_display(ancho, alto);

	int ancho_W = GetSystemMetrics(SM_CXSCREEN);
	int alto_W = GetSystemMetrics(SM_CYSCREEN);

	al_set_window_title(ventana, "Zelda");
	al_set_window_position(ventana, ancho_W / 2 - ancho / 2, alto_W / 2 - alto / 2);

	

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_mouse_event_source());




	menu();


	return 0;
}


int menu() {
	int x = -1, y = -1;
	

	ALLEGRO_BITMAP* menu_null = al_load_bitmap("Imagenes/Menu.jpeg");
	ALLEGRO_BITMAP* menu_jugar = al_load_bitmap("Imagenes/Jugar.jpeg");
	ALLEGRO_BITMAP* menu_salir = al_load_bitmap("Imagenes/Salir.jpeg");
	//menu
	int botones[] = { 0 };

	while (true)
	{
		ALLEGRO_EVENT Evento;
		al_wait_for_event(event_queue, &Evento);


		al_clear_to_color(al_map_rgb(0, 0, 0));

		if (botones[0] == 0)
			al_draw_bitmap(menu_null, 0, 0, 0);
		else if (botones[0] == 1)
			al_draw_bitmap(menu_jugar, 0, 0, 0);
		else
			al_draw_bitmap(menu_salir, 0, 0, 0);

		if (Evento.type == ALLEGRO_EVENT_MOUSE_AXES || Evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{

			x = Evento.mouse.x;
			y = Evento.mouse.y;

			if (x >= 234 && x <= 527 && y >= 354 && y <= 413) {
				botones[0] = 1;
				if (Evento.mouse.button & 1)
					jugar();

			}
			else {
				if (x >= 234 && x <= 527 && y >= 451 && y <= 510) {
					botones[0] = 2;
					if (Evento.mouse.button & 1)
						return 1;
				}
				else {
					botones[0] = 0;
				}

			}


		}

		al_flip_display();
	}
	
	}
