#include <stdio.h>
#include <allegro.h>

// largura e altura da tela
#define largura 900
#define altura  700

void init() 
{
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	
	// referente ao padrão de cores de 32 bits
    if (depth == 0) 
       depth = 32;
	
	// define o padrão de cor de 32 bits
    set_color_depth(depth);
    
    // define o tamanho da tela
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, largura, altura, 0, 0);
	
	// caso tenha algum erro na hora de criar a tela
    if (res != 0) 
    {
		allegro_message(allegro_error);
		exit(-1);
	}
   
    // define o titulo da tela
    set_window_title("XADREZ");
 
   
    // inicializa os hardwares
	install_timer();
	install_keyboard();
	
	//Parametros da função install_sound:
	//	- o primeiro indica o controlador de som digital a ser usado pelo Allegro;
	//	- o segundo indica o controlador de som MIDI;
	//	- o terceiro existe apenas por motivos de compatibilidade com versões antigas do Allegro, 
    //    e deve ser ignorado passando-se o valor NULL.
	
	if(install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL))
    {
		allegro_message(allegro_error);
		exit(-1);
	}
}

void deinit()
{
	clear_keybuf();
	allegro_exit();
}