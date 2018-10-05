#include <stdio.h>
#include <allegro.h>

#define MARG  62 
#define CASA  73

PALETTE  paleta;
BITMAP *quadro, *torre1_b, *torre2_b, *cavalo1_b, *cavalo2_b, *bispo1_b, *bispo2_b, *rainha_b, *rei_b;
BITMAP *piao1_b, *piao2_b, *piao3_b, *piao4_b, *piao5_b, *piao6_b, *piao7_b, *piao8_b; 

BITMAP *torre1_p, *torre2_p, *cavalo1_p, *cavalo2_p, *bispo1_p, *bispo2_p, *rainha_p, *rei_p;
BITMAP *piao1_p, *piao2_p, *piao3_p, *piao4_p, *piao5_p, *piao6_p, *piao7_p, *piao8_p; 


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
   
 return;     
}





