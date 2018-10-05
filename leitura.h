#include <stdio.h>
#include <allegro.h>

char jogador1[60], jogador2[60], nome[60];


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
    
   //jogo();
   
 return;
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
