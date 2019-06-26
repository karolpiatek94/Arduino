float napiecie = 0.0, float napiecie_ref = 0.0;
float ref = 0.1;                      //minimalna wart. zmiany napiecia jaka musi wystapic, np. 0.1 (nie jestem pewien jak odczytuje dane arduino - tzn. czy to będzie 0.1 czy. ileś bitow) 
int g = 0, d = 0, p = 0, l = 0;       //zmienne do zliczania krokow w kazdym kierunku

void setup()
{
Serial.begin(9600);                   //nie wiem co to, ale wystepuje w wiekszosci programow na arduino
}

void petla()
{
  float analog = analogRead(A0);        //zczytanie wart. napiecia z. pinu A0 (przetwornika AD)
  napiecie = (analog * 5.0)/1024.0;     //przerzucenie liczby na wolty - nie wiem czy to potrzebne
  
  /* SPRAWDZA W GORE*/
  
  rusz_silniki_w_gore_o_1_krok;
  g=g+1;
  float analog_ref = analogRead(A0);
  if(analog_ref - analog >= ref)
  {
  while(analog_ref - analog >= ref)     //nakurwiaj w gore poki napiecie bedzie sie zwiekszac
  {
    rusz_silniki_w_gore_o_1_krok;       
    analog = analog_ref;                
    analog_ref = analogRead(A0);
    g=g+1;                              //zliczamy ile krokow wykonal w gore
  }
 }
 else                                   
 {
 if(analog > analog_ref)
 {
  rusz_silniki_w_dol_o_1_krok;
  analog = analog_ref;
  analog_ref = analogRead(A0);
  g=g-1;
 } 
 }
 
 /* SPRAWDZA W PRAWO */
 
 rusz_silniki_w_prawo_o_1_krok;
  p=p+1;
  analog = analog_ref;
  analog_ref = analogRead(A0);
  if(analog_ref - analog >= ref)
  {
  while(analog_ref - analog >= ref)     //nakurwiaj w prawo poki napiecie bedzie sie zwiekszac
  {
    rusz_silniki_w_prawo_o_1_krok;       
    analog = analog_ref;                
    analog_ref = analogRead(A0);
    p=p+1;                              //zliczamy ile krokow wykonal w prawo
  }
 }
 else                                   
 {
 if(analog > analog_ref)
 {
  rusz_silniki_w_lewo_o_1_krok;
  analog = analog_ref;
  analog_ref = analogRead(A0);
  p=p-1;
 } 
 }
 
 /* SPRAWDZA W LEWO */
 
  rusz_silniki_w_lewo_o_1_krok;
  l=l+1;
  analog = analog_ref;
  analog_ref = analogRead(A0);
  if(analog_ref - analog >= ref)
  {
  while(analog_ref - analog >= ref)     //nakurwiaj w lewo poki napiecie bedzie sie zwiekszac
  {
    rusz_silniki_w_lewo_o_1_krok;       
    analog = analog_ref;                
    analog_ref = analogRead(A0);
    l=l+1;                              //zliczamy ile krokow wykonal w lewo
  }
 }
 else                                   
 {
 if(analog > analog_ref)
 {
  rusz_silniki_w_prawo_o_1_krok;
  analog = analog_ref;
  analog_ref = analogRead(A0);
  l=l-1;
 } 
 }
 
}
