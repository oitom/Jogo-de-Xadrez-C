#include <stdio.h>
#include <allegro.h>



int menu()
{

    
	PALETTE  paleta;
	BITMAP *quadro, *coroa;
	char flag='f';
    SAMPLE *press;
    press = load_sample("musicas/press.wav");
	
    // carrega a imagem do menu
	quadro = load_bitmap("imagens/menu.bmp", paleta);
    coroa = load_bitmap("imagens/crow.bmp", paleta);
    
	// define o posicionamento e imprime o menu
	draw_sprite(screen, quadro, 0, 0);
    
    // desenha a coroa
    draw_sprite(screen, coroa, 575, 236);
    	
	// limpa o buffer do teclado
	clear_keybuf( );
	
    int y = 236;
    
	do{
		readkey();
		
        if(key[KEY_DOWN])
        {      
             play_sample(press, 255, 128, 1000, FALSE);
              
              y+=87;
              draw_sprite(screen, quadro, 0, 0);
             
              if(y <=394)
                 draw_sprite(screen, coroa, 575, y);
              else
              {
                 draw_sprite(screen, coroa, 575, 394);
                 y= 394;
              }          
          }
          if(key[KEY_UP])
          {          
              play_sample(press, 255, 128, 1000, FALSE); 
             y-=87;
              draw_sprite(screen, quadro, 0, 0);
             
              if(y >=236)
                 draw_sprite(screen, coroa, 575, y);
              else
              {
                 draw_sprite(screen, coroa, 575, 236);
                 y = 236;
              }          
          }
		  
		  if(key[KEY_ENTER])
          {
              if(y == 236) return 1;
              if(y == 323) return 2;
              if(y == 394) return 0;
          }


	}while(1);
	
	
	// limpa o buffer do teclado
	clear_keybuf( );
	// desaloca a imagem do menu e limpa a tela
    destroy_bitmap(quadro);
	clear(screen);	
}

void abertura()
{
	PALETTE  paleta;
	BITMAP *quadro;
   
    // carrega a imagem de abertura do jogo
	quadro = load_bitmap("imagens/inicio.bmp", paleta);
	
    if (!quadro)	
       allegro_message(allegro_error);
	
	// define o posicionamento e imprime a imagem
    draw_sprite(screen, quadro, 0, 0);
	fade_in (paleta, 1);
	
	// desaloca a imagem e limpa a tela
	destroy_bitmap(quadro);
	//fade_out (1);
	clear(screen);
}

void option()
{
	PALETTE  paleta;
	BITMAP *quadro;
	char flag='1';
	
    int *digi_volume, 
        *midi_volume; 
	
	// carrega a imagem de opções
	quadro = load_bitmap("imagens/inicio.bmp", paleta);
  	draw_sprite(screen, quadro, 0, 0);
    
    // aloca as opçoes do som
	digi_volume = (int *) malloc(1 * sizeof(int));
	midi_volume = (int *) malloc(1 * sizeof(int));
	clear_keybuf();
	
	do{
		
        //get_volume(digi_volume, midi_volume);
        
        //aumenta o volume da música
		if(key[KEY_U])
        { 	*digi_volume += 25;
			*midi_volume += 25;
			if((*digi_volume) > 255)	
                *digi_volume = 255; //volume máximo possível
			if((*midi_volume) > 255)
            	*midi_volume = 255; //volume máximo possível
			
            set_volume(*digi_volume, *midi_volume);
		}
		
		//diminui o volume da música
		if(key[KEY_D])
        { 
			*digi_volume -= 25;
			*midi_volume -= 25;
			
            if((*digi_volume) < 0)	
                 *digi_volume = 0; //volume mínimo possível
			
            if((*midi_volume) < 0)	
                 *midi_volume = 0; //volume mínimo possível
                 
			set_volume(*digi_volume, *midi_volume);
		}
		
		// sai da tela de opções 
		if(key[KEY_Q] || key[KEY_ESC]) 
			flag = '0';
			
		clear_keybuf();
	} while(flag != '0');

}

void sair()
{
	PALETTE  paleta;
	BITMAP *quadro;
	MIDI *musica;
	
	// aumenta o volume
	//set_volume(255, 255);
	
	// carrega a imagem da finalização do jogo
	quadro = load_bitmap("imagens/final.bmp", paleta);
	
	// define o posicionamento e imprime a imagem
	draw_sprite(screen, quadro, 0, 0);
	
	// carrega a música de finalização do jogo
    musica = load_midi("musicas/fim.mid");
    
	if (!musica)
       allegro_message(allegro_error);
 
	// inicaliza a musica
    play_midi(musica, TRUE);
    
    // limpa o buffer do teclado
	clear_keybuf();
	
	// ao ser precionado 'esc' finaliza o jogo
    while(!key[KEY_ESC]);
    
    // desaloca a musica
    stop_midi();
	destroy_midi(musica);
}


