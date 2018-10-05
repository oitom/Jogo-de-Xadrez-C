#include <allegro.h>
#include <stdio.h>

// largura e altura da tela
#define largura 900
#define altura  700
#define MARG  62 
#define CASA  73

void init(); // inicializa o ambiante para rodar o allegro
void deinit(); // finaliza o ambiente allegro
void abertura(); // abertura do jogo
int menu(); // menu do jogo
void jogo(); // jogo tabuleiro
void pegaNome(); // Pega o nome dos jogadores 
void option(); // tela opções 
void sair(); // fecha o jogo
void iniciaPecaPreta(); // carrega as peças pretas
void iniciaPecaBranca(); // carrega as peças brancas
void moveSeta(); // movimenta a seta dos jogadores
int LE_TECLADO();

PALETTE  paleta;
BITMAP *quadro, *torre1_b, *torre2_b, *cavalo1_b, *cavalo2_b, *bispo1_b, *bispo2_b, *rainha_b, *rei_b;
BITMAP *piao1_b, *piao2_b, *piao3_b, *piao4_b, *piao5_b, *piao6_b, *piao7_b, *piao8_b; 

BITMAP *torre1_p, *torre2_p, *cavalo1_p, *cavalo2_p, *bispo1_p, *bispo2_p, *rainha_p, *rei_p;
BITMAP *piao1_p, *piao2_p, *piao3_p, *piao4_p, *piao5_p, *piao6_p, *piao7_p, *piao8_p; 

char jogador1[60], jogador2[60], nome[60];
SAMPLE *som;	
//---------------------- MAIN --------------------------//
int main() 
{
	//Função que faz as inicializações dos hardwares utilizados
	init(); 
	int varMenu=1;	
    
    	
	som = load_sample("musicas/fundo.wav");
	play_sample(som, 255, 128, 1000, TRUE);
	
	//Função que exibe a primeira imagem de abertura
	abertura();
	
	//Loop do menu principal do jogo
	while (varMenu) 
    {
        //função Menu exibe a imagem de menu e fica esperando a entrada do usuario
		varMenu = menu(); 
		
        switch(varMenu)
        {
			case 1: pegaNome(); break;    //inicia o jogo
			case 2: option(); break; //entra nas opções
		}
	}
	
	//para a música que estava tocando
	stop_sample(som);
	
    //função saír carrega outra imagem e toca outra música pedindo para apertar 'Esc' para sair do programa
	sair(); 
	
	//Retira os dominios do Allegro
    deinit(); 
    
	return 0;
}
END_OF_MAIN();


void iniciaPecaPreta()
{
    
    torre1_p = load_bitmap("imagens/torre_p.bmp", paleta);
	torre2_p = load_bitmap("imagens/torre_p.bmp", paleta);
    cavalo1_p = load_bitmap("imagens/cavalo_p.bmp", paleta);
	cavalo2_p = load_bitmap("imagens/cavalo_p.bmp", paleta);
    bispo1_p = load_bitmap("imagens/bispo_p.bmp", paleta);
	bispo2_p = load_bitmap("imagens/bispo_p.bmp", paleta);
    rainha_p = load_bitmap("imagens/rainha_p.bmp", paleta);
	rei_p = load_bitmap("imagens/rei_p.bmp", paleta);
    
    piao1_p = load_bitmap("imagens/piao_p.bmp", paleta);
    piao2_p = load_bitmap("imagens/piao_p.bmp", paleta);
    piao3_p = load_bitmap("imagens/piao_p.bmp", paleta);
    piao4_p = load_bitmap("imagens/piao_p.bmp", paleta);
    piao5_p = load_bitmap("imagens/piao_p.bmp", paleta);
    piao6_p = load_bitmap("imagens/piao_p.bmp", paleta);
    piao7_p = load_bitmap("imagens/piao_p.bmp", paleta);
    piao8_p = load_bitmap("imagens/piao_p.bmp", paleta);    
   
   draw_sprite(screen, torre1_p,  MARG, MARG);       
   draw_sprite(screen, cavalo1_p, MARG+CASA, MARG);
   draw_sprite(screen, bispo1_p,  MARG+CASA*2, MARG);
   draw_sprite(screen, rainha_p,  MARG+CASA*3, MARG);
   draw_sprite(screen, rei_p,     MARG+CASA*4, MARG); 
   draw_sprite(screen, bispo2_p,  MARG+CASA*5, MARG);
   draw_sprite(screen, cavalo2_p, MARG+CASA*6, MARG);
   draw_sprite(screen, torre2_p,  MARG+CASA*7, MARG);      
                       
   draw_sprite(screen, piao1_p, MARG, MARG+CASA);
   draw_sprite(screen, piao2_p, MARG+CASA, MARG+CASA);       	
   draw_sprite(screen, piao3_p, MARG+CASA*2, MARG+CASA);
   draw_sprite(screen, piao4_p, MARG+CASA*3,MARG+CASA);
   draw_sprite(screen, piao5_p, MARG+CASA*4,MARG+CASA);
   draw_sprite(screen, piao6_p, MARG+CASA*5, MARG+CASA);
   draw_sprite(screen, piao7_p, MARG+CASA*6, MARG+CASA);
   draw_sprite(screen, piao8_p, MARG+CASA*7, MARG+CASA);
        
     
 return;     
}

void iniciaPecaBranca()
{
    torre1_b = load_bitmap("imagens/torre_b.bmp", paleta);
	torre2_b = load_bitmap("imagens/torre_b.bmp", paleta);
    cavalo1_b = load_bitmap("imagens/cavalo_b.bmp", paleta);
	cavalo2_b = load_bitmap("imagens/cavalo_b.bmp", paleta);
    bispo1_b = load_bitmap("imagens/bispo_b.bmp", paleta);
	bispo2_b = load_bitmap("imagens/bispo_b.bmp", paleta);
    rainha_b = load_bitmap("imagens/rainha_b.bmp", paleta);
	rei_b = load_bitmap("imagens/rei_b.bmp", paleta);
    
    piao1_b = load_bitmap("imagens/piao_b.bmp", paleta);
    piao2_b = load_bitmap("imagens/piao_b.bmp", paleta);
    piao3_b = load_bitmap("imagens/piao_b.bmp", paleta);
    piao4_b = load_bitmap("imagens/piao_b.bmp", paleta);
    piao5_b = load_bitmap("imagens/piao_b.bmp", paleta);
    piao6_b = load_bitmap("imagens/piao_b.bmp", paleta);
    piao7_b = load_bitmap("imagens/piao_b.bmp", paleta);
    piao8_b = load_bitmap("imagens/piao_b.bmp", paleta);    
   
    draw_sprite(screen, torre1_b,   MARG, MARG+CASA*7);
    draw_sprite(screen, cavalo1_b,  MARG+CASA, MARG+CASA*7);   
    draw_sprite(screen, bispo1_b,   MARG+CASA*2, MARG+CASA*7);
    draw_sprite(screen, rainha_b,   MARG+CASA*3, MARG+CASA*7);    
    draw_sprite(screen, rei_b,      MARG+CASA*4, MARG+CASA*7);
    draw_sprite(screen, bispo2_b,   MARG+CASA*5, MARG+CASA*7);
    draw_sprite(screen, cavalo2_b,  MARG+CASA*6, MARG+CASA*7);
    draw_sprite(screen, torre2_b,   MARG+CASA*7, MARG+CASA*7); 
          
    draw_sprite(screen, piao1_b, MARG, MARG+CASA*6);
    draw_sprite(screen, piao2_b, MARG+CASA, MARG+CASA*6);       	
    draw_sprite(screen, piao3_b, MARG+CASA*2, MARG+CASA*6);
    draw_sprite(screen, piao4_b, MARG+CASA*3, MARG+CASA*6);
    draw_sprite(screen, piao5_b, MARG+CASA*4, MARG+CASA*6);
    draw_sprite(screen, piao6_b, MARG+CASA*5, MARG+CASA*6);
    draw_sprite(screen, piao7_b, MARG+CASA*6, MARG+CASA*6);
    draw_sprite(screen, piao8_b, MARG+CASA*7, MARG+CASA*6);       
     
 return;     
}


void pegaNome()
{
  PALETTE  paleta;
  BITMAP *quadro;
  SAMPLE *press;
  press = load_sample("musicas/press.wav");
	
  quadro = load_bitmap("imagens/player.bmp", paleta);
  draw_sprite(screen, quadro, 0, 0);
  int sair = 1;
  
   strcpy(jogador1,"");
   strcpy(jogador2,"");
   strcpy(nome,"");
   
   do{
                   
      textprintf_ex(screen, font, 99, 232, makecol(0, 0, 0), -1, "%s", nome);
          
      sair = LE_TECLADO();
      
      
      
    }while(sair);
    
    strcpy(jogador1,nome);    
    strcpy(nome,"");
    play_sample(press, 255, 128, 1000, FALSE);
   
   do 
    {
          textprintf_ex(screen, font, 99, 372, makecol(0, 0, 0), -1, "%s", nome);
          
          sair = LE_TECLADO();
    
    
    }while(sair);
    
    play_sample(press, 255, 128, 1000, FALSE);
    
    strcpy(jogador2,nome);
    jogo();
   
 return;
}
//---------------------- JOGO --------------------------//
void jogo()
{
	PALETTE  paleta;
	BITMAP *quadro, *setap1, *setap2;
	char flag='1';
   
    // carrega a imagem do jogo o tabuleiro	
	quadro = load_bitmap("imagens/jogo.bmp", paleta);
    
    // define as setas dos jogadores
	setap1 = load_bitmap("imagens/setap2.bmp", paleta);
    //setap2 = load_bitmap("imagens/seta-p2.bmp", paleta);

	// define o posicionamento e imprime o tabuleiro
	draw_sprite(screen, quadro, 0, 0);
   
   	// Inicia as peças do jogo	
    iniciaPecaPreta();      	
	iniciaPecaBranca();
		
    int x = 58, y=58, space = 73;	
    int go = 0;
    
    stop_sample(som);
    
    do{
		
        textprintf_ex(screen, font, 670, 107, makecol(0, 0, 0), -1, "%s", jogador1);
        textprintf_ex(screen, font, 670, 233, makecol(0, 0, 0), -1, "%s", jogador2);
    
		if(go == 0)
        {
             draw_sprite(screen, setap1, x, y);
             go++;
        }
       
               
       
          
          readkey();
          
          if(key[KEY_RIGHT])
          {             
              x+=space;
              
                            
              draw_sprite(screen, quadro, 0, 0);
              
              if(x <= 569)
                 draw_sprite(screen, setap1, x, y);
              else
              {
                 draw_sprite(screen, setap1, 569, y);
                 x=569;
              }               
              
              iniciaPecaPreta();      	
	          iniciaPecaBranca();
    
          }
          
          if(key[KEY_LEFT])
          {  
            
              x-=space;
              
              draw_sprite(screen, quadro, 0, 0);
              
              if(x >= 58)
                 draw_sprite(screen, setap1, x, y);
              else
              {
                 draw_sprite(screen, setap1, 58, y);
                 x=58;
              }
              iniciaPecaPreta();      	
	          iniciaPecaBranca();
	          
          }
          
          if(key[KEY_UP])
          {
              
              y-=space;
              draw_sprite(screen, quadro, 0, 0);
              
              if(y >= 58)
                 draw_sprite(screen, setap1, x, y);
              else
              {
                 draw_sprite(screen, setap1, x, 58);
                 y=58;      
              }
              iniciaPecaPreta();      	
	          iniciaPecaBranca();        
              
          }
          
          if(key[KEY_DOWN])
          {   
                
              y+=space;
              draw_sprite(screen, quadro, 0, 0);
             
              if(y <=569)
                 draw_sprite(screen, setap1, x, y);
              else
              {
                 draw_sprite(screen, setap1, x, 569);
                 y = 569;
              }
              iniciaPecaPreta();      	
	          iniciaPecaBranca();
	           
          }
          
          if(key[KEY_ENTER])
          {
               int POS_X = (x-58)/73;
               int POS_Y = (y-58)/73;
               
               
               draw_sprite(screen, piao1_b, x+3, y+3);
               
               textprintf_ex(screen, font, 0, 0, makecol(255, 0, 0), -1, "TAB[%d, %d]", POS_X, POS_Y);   
               
                              
          }
          
                   		
		// ao ser pressionado 'q' sai do jogo
		if(key[KEY_Q] || key[KEY_ESC])
			flag = '0'; // muda o flag para zero e sai do laço
			
		// limpa o buffer do teclado
		clear_keybuf();
		
	} while(flag != '0');
}

//---------------------- MENU --------------------------//
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

//---------------------- OPTION --------------------------//
void option()
{
	PALETTE  paleta;
	BITMAP *quadro;
	char flag='1';
	
    int *digi_volume, 
        *midi_volume; 
	
	// carrega a imagem de opções
	quadro = load_bitmap("imagens/option.bmp", paleta);
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

//---------------------- SAIR --------------------------//
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


//---------------------- ABERTURA --------------------------//
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


//---------------------- INIT --------------------------//
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
	install_mouse();
	
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

//---------------------- DEINIT --------------------------//
void deinit()
{
	clear_keybuf();
	allegro_exit();
}

int LE_TECLADO() 
{
  int tam;

  readkey();
  if (strlen(nome) < 13){
    if(key[KEY_A])
      strcat(nome,"A");
    else if(key[KEY_B])
      strcat(nome,"B");
    else if(key[KEY_C])
      strcat(nome,"C");
    else if(key[KEY_D])
      strcat(nome,"D");
    else if(key[KEY_E])
      strcat(nome,"E");
    else if(key[KEY_F])
      strcat(nome,"F");
    else if(key[KEY_G])
      strcat(nome,"G");
    else if(key[KEY_H])
      strcat(nome,"H");
    else if(key[KEY_I])
      strcat(nome,"I");
    else if(key[KEY_J])
      strcat(nome,"J");
    else if(key[KEY_K])
      strcat(nome,"K");
    else if(key[KEY_L])
      strcat(nome,"L");
    else if(key[KEY_M])
      strcat(nome,"M");
    else if(key[KEY_N])
      strcat(nome,"N");
    else if(key[KEY_O])
      strcat(nome,"O");
    else if(key[KEY_P])
      strcat(nome,"P");
    else if(key[KEY_Q])
      strcat(nome,"Q");
    else if(key[KEY_R])
      strcat(nome,"R");
    else if(key[KEY_S])
      strcat(nome,"S");
    else if(key[KEY_T])
      strcat(nome,"T");
    else if(key[KEY_U])
      strcat(nome,"U");
    else if(key[KEY_V])
      strcat(nome,"V");
    else if(key[KEY_X])
      strcat(nome,"X");
    else if(key[KEY_Z])
      strcat(nome,"Z");
    else if(key[KEY_W])
      strcat(nome,"W");
    else if(key[KEY_Y])
      strcat(nome,"Y");
    else if(key[KEY_SPACE])
      strcat(nome," ");
    else if(key[KEY_0_PAD])
      strcat(nome,"0");
    else if(key[KEY_1_PAD])
      strcat(nome,"1");
    else if(key[KEY_2_PAD])
      strcat(nome,"2");
    else if(key[KEY_3_PAD])
      strcat(nome,"3");
    else if(key[KEY_4_PAD])
      strcat(nome,"4");
    else if(key[KEY_5_PAD])
      strcat(nome,"5");
    else if(key[KEY_6_PAD])
      strcat(nome,"6");
    else if(key[KEY_7_PAD])
      strcat(nome,"7");
    else if(key[KEY_8_PAD])
      strcat(nome,"8");
    else if(key[KEY_9_PAD])
      strcat(nome,"9");
    else if(key[KEY_0])
      strcat(nome,"0");
    else if(key[KEY_1])
      strcat(nome,"1");
    else if(key[KEY_2])
      strcat(nome,"2");
    else if(key[KEY_3])
      strcat(nome,"3");
    else if(key[KEY_4])
      strcat(nome,"4");
    else if(key[KEY_5])
      strcat(nome,"5");
    else if(key[KEY_6])
      strcat(nome,"6");
    else if(key[KEY_7])
      strcat(nome,"7");
    else if(key[KEY_8])
      strcat(nome,"8");
    else if(key[KEY_9])
      strcat(nome,"9");
  }
  if(key[KEY_BACKSPACE])
  { 
    tam = strlen(nome);
    
    if (tam > 0)
      nome[tam-1] = '\0';
  }
        
  if(key[KEY_ENTER])
     return 0;
  else
      return 1;
}
